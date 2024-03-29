#include "queries/query5.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "catalogs/flights_catalog.h"
#include "entities/flight.h"
#include "data_manager/validater.h"
#include "catalogs/airports_catalog.h"
#include "utils/utils.h"

//                                          Execution of query five
// ===================================================================================================================
void exec_query_five(AIRPORTS_CATALOG airports_catalog, FLIGHTS_CATALOG flights_catalog, char *args, FILE *output, int flag)
{
    char *airport_id = malloc(4 * sizeof(char));
    char begin_date[20];
    char end_date[20];
    int print = 1;

    sscanf(args, "%3s \"%19[^\"]\" \"%19[^\"]\"", airport_id, begin_date, end_date);

    AIRPORT airport = lookup_airport(airports_catalog, airport_id);
    GArray *flight_list = get_airport_flight_list(airport);

    g_array_sort_with_data(flight_list, sort_flight_array_by_dates3, flights_catalog);

    if (flag == 1)
    {
        for (int i = 0; i < flight_list->len; i++)
        {
            int id = g_array_index(flight_list, int, i);
            char flight_id[11];
            sprintf(flight_id, "%010d", id);
            FLIGHT flight = lookup_flight(flights_catalog, flight_id);

            char *date = get_flight_schedule_departure_date(flight);
            if (strcmp(date, begin_date) < 0 || strcmp(date, end_date) > 0)
            {
                free(date);
                continue;
            }

            char *destination = get_flight_destination(flight);
            char *airline = get_flight_airline(flight);
            char *plane_model = get_flight_plane_model(flight);

            if (i == flight_list->len - 1)
            {
                if (print == 1)
                    fprintf(output, "--- %d ---\nid: %s\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n",
                            print,
                            flight_id,
                            date,
                            destination,
                            airline,
                            plane_model);
                else
                    fprintf(output, "\n--- %d ---\nid: %s\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n",
                            print,
                            flight_id,
                            date,
                            destination,
                            airline,
                            plane_model);
            }
            else
            {
                if (print == 1)
                    fprintf(output, "--- %d ---\nid: %s\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n",
                            print,
                            flight_id,
                            date,
                            destination,
                            airline,
                            plane_model);
                else
                    fprintf(output, "\n--- %d ---\nid: %s\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n",
                            print,
                            flight_id,
                            date,
                            destination,
                            airline,
                            plane_model);
            }
            print++;

            free(destination);
            free(airline);
            free(plane_model);
            free(date);
        }
    }
    else
    {
        for (int i = 0; i < flight_list->len; i++)
        {
            int id = g_array_index(flight_list, int, i);
            char flight_id[11];
            sprintf(flight_id, "%010d", id);
            FLIGHT flight = lookup_flight(flights_catalog, flight_id);

            char *date = get_flight_schedule_departure_date(flight);
            if (strcmp(date, begin_date) < 0 || strcmp(date, end_date) > 0)
            {
                free(date);
                continue;
            }

            char *destination = get_flight_destination(flight);
            char *airline = get_flight_airline(flight);
            char *plane_model = get_flight_plane_model(flight);

            fprintf(output, "%s;%s;%s;%s;%s\n",
                    flight_id, date, destination, airline, plane_model);

            free(destination);
            free(airline);
            free(plane_model);
            free(date);
        }
    }
    free(airport_id);
    g_array_free(flight_list, TRUE);
}
