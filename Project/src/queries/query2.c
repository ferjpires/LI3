#include "queries/query2.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "entities/flight.h"
#include "entities/reservation.h"
#include "entities/user.h"
#include "data_manager/validater.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"
#include "utils/utils.h"

//============================== Write Flight Function ==============================

void _write_user_flights_(GArray *in_order_flight_list, FLIGHTS_CATALOG flights_catalog, FILE *output, int flag)
{

    if (in_order_flight_list == NULL)
        return;

    g_array_sort_with_data(in_order_flight_list, sort_flight_array_by_dates2, flights_catalog);

    if (flag == 1)
    {
        for (int i = 0; i < in_order_flight_list->len; ++i)
        {
            int current_flight_id = g_array_index(in_order_flight_list, int, i);
            char id[11];
            sprintf(id, "%010d", current_flight_id);
            FLIGHT found_flight = lookup_flight(flights_catalog, id);

            char *token;
            char *date = get_flight_schedule_departure_date(found_flight);
            char *date_copy = date;
            token = strsep(&date_copy, " ");

            if (i == (in_order_flight_list->len) - 1)
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\n",
                        i + 1,
                        id,
                        token);
            else
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\n\n",
                        i + 1,
                        id,
                        token);
            free(date);
        }
    }
    else
    {
        for (int i = 0; i < in_order_flight_list->len; ++i)
        {
            int current_flight_id = g_array_index(in_order_flight_list, int, i);
            char id[11];
            sprintf(id, "%010d", current_flight_id);
            FLIGHT found_flight = lookup_flight(flights_catalog, id);

            char *token;
            char *date = get_flight_schedule_departure_date(found_flight);
            char *date_copy = date;
            token = strsep(&date_copy, " ");

            fprintf(output, "%s;%s\n",
                    id,
                    token);
            free(date);
        }
    }
}

//============================== Write Reservation Function ==============================

void _write_user_reservations_(GArray *in_order_reservation_list, RESERVATIONS_CATALOG reservations_catalog, FILE *output, int flag)
{

    if (in_order_reservation_list == NULL)
        return;

    g_array_sort_with_data(in_order_reservation_list, sort_reservation_list2, reservations_catalog);

    if (flag == 1)
    {
        for (int i = 0; i < in_order_reservation_list->len; ++i)
        {
            int current_reservation_id = g_array_index(in_order_reservation_list, int, i);
            char res_id[16];
            sprintf(res_id, "Book%010d", current_reservation_id);
            RESERVATION found_reservation = lookup_reservation(reservations_catalog, res_id);

            char *date = get_reservation_begin_date(found_reservation);

            if (i == (in_order_reservation_list->len) - 1)
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\n",
                        i + 1,
                        res_id,
                        date);
            else
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\n\n",
                        i + 1,
                        res_id,
                        date);
            free(date);
        }
    }
    else
    {
        for (int i = 0; i < in_order_reservation_list->len; ++i)
        {
            int current_reservation_id = g_array_index(in_order_reservation_list, int, i);
            char res_id[16];
            sprintf(res_id, "Book%010d", current_reservation_id);
            RESERVATION found_reservation = lookup_reservation(reservations_catalog, res_id);

            char *date = get_reservation_begin_date(found_reservation);

            fprintf(output, "%s;%s\n",
                    res_id,
                    date);
            free(date);
        }
    }
}

//============================== Write Flight & Reservations Function ==============================

void _write_user_flights_reservations_(GArray *in_order_reservation_list, GArray *in_order_flight_list,
                                       FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                                       FILE *output, int flag)
{
    int i_r = 0;
    int i_f = 0;

    g_array_sort_with_data(in_order_flight_list, sort_flight_array_by_dates2, flights_catalog);
    g_array_sort_with_data(in_order_reservation_list, sort_reservation_list2, reservations_catalog);

    int len_reservations;
    if (in_order_reservation_list == NULL)
        len_reservations = 0;
    else
        len_reservations = in_order_reservation_list->len;

    int len_flights;
    if (in_order_flight_list == NULL)
        len_flights = 0;
    else
        len_flights = in_order_flight_list->len;

    if (flag == 1)
    {
        while (i_r < len_reservations && i_f < len_flights)
        {
            int current_reservation_id = g_array_index(in_order_reservation_list, int, i_r);
            char res_id[16];
            sprintf(res_id, "Book%010d", current_reservation_id);
            RESERVATION found_reservation = lookup_reservation(reservations_catalog, res_id);

            char *begin_date = get_reservation_begin_date(found_reservation);

            int current_flight_id = g_array_index(in_order_flight_list, int, i_f);
            char id[11];
            sprintf(id, "%010d", current_flight_id);
            FLIGHT found_flight = lookup_flight(flights_catalog, id);

            char *schedule_departure_date = get_flight_schedule_departure_date(found_flight);

            if (date_cmp(begin_date, schedule_departure_date, res_id, id) > 0)
            {
                if (i_r + i_f == len_reservations + len_flights - 1)
                    fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: reservation\n",
                            i_r + i_f + 1,
                            res_id,
                            begin_date);
                else
                    fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: reservation\n\n",
                            i_r + i_f + 1,
                            res_id,
                            begin_date);

                i_r++;
            }
            else
            {
                char *token;
                char *date = get_flight_schedule_departure_date(found_flight);
                char *date_copy = date;
                token = strsep(&date_copy, " ");

                if (i_r + i_f == len_reservations + len_flights - 1)
                    fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: flight\n",
                            i_r + i_f + 1,
                            id,
                            token);
                else
                    fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: flight\n\n",
                            i_r + i_f + 1,
                            id,
                            token);
                free(date);

                i_f++;
            }
            free(begin_date);
            free(schedule_departure_date);
        }

        for (; i_r < len_reservations; i_r++)
        {
            int current_reservation_id = g_array_index(in_order_reservation_list, int, i_r);
            char res_id[16];
            sprintf(res_id, "Book%010d", current_reservation_id);
            RESERVATION found_reservation = lookup_reservation(reservations_catalog, res_id);

            char *date = get_reservation_begin_date(found_reservation);

            if (i_r + i_f == len_reservations + len_flights - 1)
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: reservation\n",
                        i_r + i_f + 1,
                        res_id,
                        date);
            else
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: reservation\n\n",
                        i_r + i_f + 1,
                        res_id,
                        date);
            free(date);
        }

        for (; i_f < len_flights; i_f++)
        {
            int current_flight_id = g_array_index(in_order_flight_list, int, i_f);
            char id[11];
            sprintf(id, "%010d", current_flight_id);
            FLIGHT found_flight = lookup_flight(flights_catalog, id);

            char *token;
            char *date = get_flight_schedule_departure_date(found_flight);
            char *date_copy = date;
            token = strsep(&date_copy, " ");

            if (i_r + i_f == len_reservations + len_flights - 1)
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: flight\n",
                        i_r + i_f + 1,
                        id,
                        token);
            else
                fprintf(output, "--- %d ---\nid: %s\ndate: %s\ntype: flight\n\n",
                        i_r + i_f + 1,
                        id,
                        token);
            free(date);
        }
    }
    else
    {
        while (i_r < len_reservations && i_f < len_flights)
        {
            int current_reservation_id = g_array_index(in_order_reservation_list, int, i_r);
            char res_id[16];
            sprintf(res_id, "Book%010d", current_reservation_id);
            RESERVATION found_reservation = lookup_reservation(reservations_catalog, res_id);

            char *begin_date = get_reservation_begin_date(found_reservation);

            int current_flight_id = g_array_index(in_order_flight_list, int, i_f);
            char id[11];
            sprintf(id, "%010d", current_flight_id);
            FLIGHT found_flight = lookup_flight(flights_catalog, id);

            char *schedule_departure_date = get_flight_schedule_departure_date(found_flight);

            if (date_cmp(begin_date, schedule_departure_date, res_id, id) > 0)
            {
                fprintf(output, "%s;%s;reservation\n",
                        res_id,
                        begin_date);

                i_r++;
            }
            else
            {
                char *token;
                char *date = get_flight_schedule_departure_date(found_flight);
                char *date_copy = date;
                token = strsep(&date_copy, " ");

                fprintf(output, "%s;%s;flight\n",
                        id,
                        token);
                free(date);

                i_f++;
            }
            free(begin_date);
            free(schedule_departure_date);
        }

        for (; i_r < len_reservations; i_r++)
        {
            int current_reservation_id = g_array_index(in_order_reservation_list, int, i_r);
            char res_id[16];
            sprintf(res_id, "Book%010d", current_reservation_id);
            RESERVATION found_reservation = lookup_reservation(reservations_catalog, res_id);

            char *date = get_reservation_begin_date(found_reservation);

            fprintf(output, "%s;%s;reservation\n",
                    res_id,
                    date);
            free(date);
        }

        for (; i_f < len_flights; i_f++)
        {
            int current_flight_id = g_array_index(in_order_flight_list, int, i_f);
            char id[11];
            sprintf(id, "%010d", current_flight_id);
            FLIGHT found_flight = lookup_flight(flights_catalog, id);

            char *token;
            char *date = get_flight_schedule_departure_date(found_flight);
            char *date_copy = date;
            token = strsep(&date_copy, " ");

            fprintf(output, "%s;%s;flight\n",
                    id,
                    token);
            free(date);
        }
    }
}

//                                          Execution of query two
//===================================================================================================================
void exec_query_two(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                    char *arguments, FILE *output, int flag)
{
    char *token;
    char *arguments_copy = arguments;
    token = strsep(&arguments_copy, " ");

    if (token == NULL)
        printf("No arguments received in query 2\n");
    else
    {
        char *argument_id = strdup(token);

        USER found_user = lookup_user(users_catalog, argument_id);

        if (found_user != NULL)
        {
            char *account_status = get_user_account_status(found_user);
            if (is_user_active(account_status))
            {
                token = strsep(&arguments_copy, " ");
                if (token != NULL)
                {
                    char *argument_flights_reservations = strdup(token);

                    if (strcmp(argument_flights_reservations, "flights") == 0)
                    {
                        GArray *flight_list = get_user_flight_list(found_user);
                        _write_user_flights_(flight_list, flights_catalog, output, flag);

                        if (flight_list != NULL)
                            g_array_free(flight_list, TRUE);
                    }
                    else
                    {
                        if (strcmp(argument_flights_reservations, "reservations") == 0)
                        {
                            GArray *reservation_list = get_user_reservation_list(found_user);
                            _write_user_reservations_(reservation_list, reservations_catalog, output, flag);

                            if (reservation_list != NULL)
                                g_array_free(reservation_list, TRUE);
                        }
                        else
                            printf("Invalid second argument in query 2\n");
                    }
                    free(argument_flights_reservations);
                }
                else
                {
                    GArray *flight_list = get_user_flight_list(found_user);
                    GArray *reservation_list = get_user_reservation_list(found_user);
                    _write_user_flights_reservations_(reservation_list, flight_list, flights_catalog, reservations_catalog, output, flag);

                    if (flight_list != NULL)
                        g_array_free(flight_list, TRUE);
                    if (reservation_list != NULL)
                        g_array_free(reservation_list, TRUE);
                }
            }
            free(account_status);
        }
        free(argument_id);
    }
}
