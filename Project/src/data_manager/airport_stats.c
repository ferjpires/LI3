#include "data_manager/airport_stats.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/airports_catalog.h"
#include "entities/flight.h"
#include "entities/airport.h"
#include "data_manager/flight_stats.h"

#include <string.h>
#include <stdlib.h>
#include <glib.h>

void order_airports_list(AIRPORTS_CATALOG airports_catalog)
{
    iterate_airports_no_data(airports_catalog, order_delay_list);
}

void set_median(AIRPORT airport)
{
    GArray *list = get_airport_delay_list(airport);

    double median = calculate_median(list);
    set_airport_median(airport, median);

    g_array_free(list, TRUE);
}

void stats_for_seven(AIRPORTS_CATALOG airports_catalog)
{
    order_airports_list(airports_catalog);

    iterate_airports_no_data(airports_catalog, set_median);
}

void add_passengers(FLIGHT flight, void *user_data)
{
    AIRPORTS_CATALOG catalog = (AIRPORTS_CATALOG)user_data;
   
    char *origin = get_flight_origin(flight);
    char *destination = get_flight_destination(flight);
    int number_of_passengers = get_flight_passenger_number(flight);
    char *date = get_flight_schedule_departure_date(flight);

    char year[5];
    strncpy(year, date, 4);
    year[4] = '\0';

    AIRPORT airportA = lookup_airport(catalog, origin);
    AIRPORT airportB = lookup_airport(catalog, destination);
    if (airportB == NULL){
        AIRPORT airport = create_airport();
        set_airport_name(airport, destination);
        insert_airport(catalog, airport, destination);
    }
    airportB = lookup_airport(catalog, destination);

    set_airport_yearly_passengers(airportA, year, number_of_passengers);

    set_airport_yearly_passengers(airportB, year, number_of_passengers);

    free(origin);
    free(destination);
    free(date);
}

void stats_for_six(FLIGHTS_CATALOG flights_catalog, AIRPORTS_CATALOG airports_catalog)
{
    iterate_flights(flights_catalog, add_passengers, airports_catalog);
}

double calculate_median(GArray *list)
{
    double result = 0;

    int length = list->len;

    if (length % 2 == 0)
    {
        int middle1 = g_array_index(list, int, (length / 2) - 1);
        int middle2 = g_array_index(list, int, (length / 2));
        result = (middle1 + middle2) / 2.0;
    }
    else
        result = g_array_index(list, int, ((length + 1) / 2) - 1);

    return result;
}