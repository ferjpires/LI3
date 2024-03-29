#include "queries/query8.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "catalogs/reservations_catalog.h"
#include "entities/reservation.h"
#include "catalogs/hotels_catalog.h"

int get_revenue(RESERVATION reservation, char *begin_date, char *end_date)
{

    char *reservation_begin_date = get_reservation_begin_date(reservation);
    char *reservation_end_date = get_reservation_end_date(reservation);
    char *reservation_price_per_night = get_reservation_price_per_night(reservation);

    if (strcmp(begin_date, reservation_end_date) > 0 || strcmp(reservation_begin_date, end_date) > 0)
    {
        free(reservation_begin_date);
        free(reservation_end_date);
        free(reservation_price_per_night);
        return 0; // out of bounds, no rating
    }

    int number_begin_date, number_end_date, number_res_begin_date, number_res_end_date = 0;

    number_begin_date = to_number(begin_date);
    number_end_date = to_number(end_date);
    number_res_begin_date = to_number(reservation_begin_date);
    number_res_end_date = to_number(reservation_end_date);

    int inicio_reserva = (number_res_begin_date > number_begin_date) ? number_res_begin_date : number_begin_date;
    int fim_reserva = (number_res_end_date <= number_end_date) ? number_res_end_date : number_end_date + 1;

    int number_of_nights = (fim_reserva - inicio_reserva) > 0 ? (fim_reserva - inicio_reserva) : 0;

    int revenue = atoi(reservation_price_per_night) * number_of_nights;

    free(reservation_begin_date);
    free(reservation_end_date);
    free(reservation_price_per_night);

    return revenue;
}

int to_number(char *date)
{
    int year, month, day;
    sscanf(date, "%d/%d/%d", &year, &month, &day);

    return year * 365 + month * 30 + day;
}

void calculate_total_revenue(RESERVATION reservation, void *user_data)
{
    char *res_hotel_id = get_reservation_hotel_id(reservation);
    char **values = (char **)user_data;
    if (strcmp(res_hotel_id, values[0]) == 0)
    {
        int rev = atoi(values[3]) + get_revenue(reservation, values[1], values[2]);
        sprintf(values[3], "%d", rev);
    }

    free(res_hotel_id);
}

//                                          Execution of query eight
//===================================================================================================================
void exec_query_eight(HOTELS_CATALOG hotels_catalog, RESERVATIONS_CATALOG reservations_catalog, char *args, FILE *output, int flag)
{
    char *hotel_id, *begin_date, *end_date;
    hotel_id = strsep(&args, " ");
    begin_date = strsep(&args, " ");
    end_date = strsep(&args, " ");
    int revenue = 0;

    HOTEL hotel = lookup_hotel(hotels_catalog, hotel_id);

    if (hotel != NULL)
    {
        GArray *reservation_list = get_hotel_reservation_list(hotel);
        for (int i = 0; i < reservation_list->len; i++)
        {
            int current_reservation_id = g_array_index(reservation_list, int, i);
            char res_id[16];
            sprintf(res_id, "Book%010d", current_reservation_id);

            RESERVATION reservation = lookup_reservation(reservations_catalog, res_id);
            revenue += get_revenue(reservation, begin_date, end_date);
        }
        g_array_free(reservation_list, TRUE);
    }

    if (flag == 1)
    {
        fprintf(output, "--- 1 ---\n");
        fprintf(output, "revenue: %d\n", revenue);
    }
    else
        fprintf(output, "%d\n", revenue);
}
