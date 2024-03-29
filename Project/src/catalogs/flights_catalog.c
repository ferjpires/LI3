#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>

#include "catalogs/flights_catalog.h"
#include "entities/flight.h"
#include "data_manager/validater.h"

struct flights_catalog
{
    GHashTable *flights;
};

//                                               Create Flights Hash Table
// ===================================================================================================================
FLIGHTS_CATALOG create_flights_catalog()
{
    FLIGHTS_CATALOG new_catalog = malloc(sizeof(struct flights_catalog));
    new_catalog->flights = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)flight_destroy_function);
    return new_catalog;
}

//                                               Build a flight
// ===================================================================================================================

void build_flight(char **flight_params, FLIGHTS_CATALOG flights)
{
    FLIGHT flight = create_flight();

    set_flight_id(flight, flight_params[0]);
    set_flight_airline(flight, flight_params[1]);
    set_flight_plane_model(flight, flight_params[2]);
    set_flight_total_seats(flight, flight_params[3]);
    set_flight_origin(flight, flight_params[4]);
    set_flight_destination(flight, flight_params[5]);
    set_flight_schedule_departure_date(flight, flight_params[6]);
    set_flight_schedule_arrival_date(flight, flight_params[7]);
    set_flight_real_departure_date(flight, flight_params[8]);
    set_flight_real_arrival_date(flight, flight_params[9]);
    set_flight_pilot(flight, flight_params[10]);
    set_flight_copilot(flight, flight_params[11]);
    set_flight_delay(flight, atoi(flight_params[12]));

    // to insert we give the hashtable which we're going to insert in, the struct to insert and the key (we pass the string and then change it)
    insert_flight(flights, flight, flight_params[0]);
}

//                                               Insert a flight
// ===================================================================================================================

void insert_flight(FLIGHTS_CATALOG catalog, FLIGHT flight, char *key)
{
    char *id_dup = g_strdup(key);
    g_hash_table_insert(catalog->flights, id_dup, GINT_TO_POINTER(flight));
}

//                                               Lookup Flight
// ===================================================================================================================

FLIGHT lookup_flight(FLIGHTS_CATALOG catalog, char *flight_id)
{
    FLIGHT found_flight = NULL;
    found_flight = g_hash_table_lookup(catalog->flights, flight_id);
    return found_flight;
}

//                                               Contains Flight
// ===================================================================================================================

int contains_flight(FLIGHTS_CATALOG catalog, char *key)
{
    if (g_hash_table_contains(catalog->flights, key))
        return 1;
    else
        return 0;
}

//                                               Destroy Catalog
// ===================================================================================================================

void free_flights_catalog(FLIGHTS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->flights);
    free(catalog);
}

//                                               Remove from HashTable
// ===================================================================================================================

void remove_flight_from_hashtable(FLIGHTS_CATALOG catalog, char *key)
{
    g_hash_table_remove(catalog->flights, key);
}

//                                               Iterate the HashTable
// ===================================================================================================================

void iterate_flights(FLIGHTS_CATALOG catalog, FlightIteratorFunc iterator_func, void *user_data)
{
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->flights);

    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        FLIGHT flight = value;
        iterator_func(flight, user_data);
    }
}
