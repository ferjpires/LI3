#include "utils/parser_utils.h"

#include <glib.h>
#include <stdio.h>
#include "entities/flight.h"

void free_info(char **info, int numStrings)
{
    for (int i = 0; i < numStrings; i++)
        g_free(info[i]);
    free(info);
}

void print_passenger_errors(GArray *list, char *flight_id, FILE *errorsFilePassengers)
{
    for (guint i = 0; i < list->len; ++i)
    {
        char *element = g_array_index(list, char *, i);
        fprintf(errorsFilePassengers, "%s;%s", flight_id, element);
        g_free(element);
        g_free(flight_id);
    }
}

void print_flight_errors(FLIGHT found_flight, FILE *errorsFileFlights)
{
    fprintf(errorsFileFlights, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s",
            get_flight_id(found_flight),
            get_flight_airline(found_flight),
            get_flight_plane_model(found_flight),
            get_flight_total_seats(found_flight),
            get_flight_origin(found_flight),
            get_flight_destination(found_flight),
            get_flight_schedule_departure_date(found_flight),
            get_flight_schedule_arrival_date(found_flight),
            get_flight_real_departure_date(found_flight),
            get_flight_real_arrival_date(found_flight),
            get_flight_pilot(found_flight),
            get_flight_copilot(found_flight));
}