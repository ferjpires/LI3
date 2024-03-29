#include "queries/query4.h"

#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "catalogs/reservations_catalog.h"
#include "entities/reservation.h"
#include "catalogs/hotels_catalog.h"
#include "utils/utils.h"


void _write_hotel_reservations_(GArray *hotel_reservation_list, RESERVATIONS_CATALOG reservations_catalog, FILE *output, int flag)
{
    g_array_sort_with_data(hotel_reservation_list, sort_reservation_list, reservations_catalog);

    for (int i = 0; i < hotel_reservation_list->len; ++i)
    {
        int current_reservation_id = g_array_index(hotel_reservation_list, int, i);
        char res_id[16];
        sprintf(res_id, "Book%010d", current_reservation_id);

        RESERVATION found_reservation = lookup_reservation(reservations_catalog, res_id);

        char *id = get_reservation_id(found_reservation);
        char *begin_date = get_reservation_begin_date(found_reservation);
        char *end_date = get_reservation_end_date(found_reservation);
        char *user_id = get_reservation_user_id(found_reservation);
        int rating = get_reservation_rating(found_reservation);
        double total_price = get_reservation_total_price(found_reservation);

        if (flag == 1)
        {
            if (i == hotel_reservation_list->len - 1)
                fprintf(output, "--- %d ---\nid: %s\nbegin_date: %s\nend_date: %s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n",
                        i + 1,
                        id,
                        begin_date,
                        end_date,
                        user_id,
                        rating,
                        total_price);

            else
                fprintf(output, "--- %d ---\nid: %s\nbegin_date: %s\nend_date: %s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n\n",
                        i + 1,
                        id,
                        begin_date,
                        end_date,
                        user_id,
                        rating,
                        total_price);
        }
        else
        {
            fprintf(output, "%s;%s;%s;%s;%d;%.3f\n",
                    id,
                    begin_date,
                    end_date,
                    user_id,
                    rating,
                    total_price);
        }

        free(id);
        free(begin_date);
        free(end_date);
        free(user_id);
    }
}

//                                          Execution of query four
// ===================================================================================================================

void exec_query_four(HOTELS_CATALOG hotels_catalog, RESERVATIONS_CATALOG reservations_catalog,
                     char *arguments, FILE *output, int flag)
{
    HOTEL found_hotel = lookup_hotel(hotels_catalog, arguments);
    if (found_hotel != NULL)
    {
        GArray *hotel_reservation_list = get_hotel_reservation_list(found_hotel);
        if (hotel_reservation_list != NULL)
            _write_hotel_reservations_(hotel_reservation_list, reservations_catalog, output, flag);
        g_array_free(hotel_reservation_list, TRUE);
    }
}
