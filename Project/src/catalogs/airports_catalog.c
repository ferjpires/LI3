#include <stdio.h>
#include <glib.h>

#include "catalogs/airports_catalog.h"

struct airports_catalog
{
    GHashTable *airports;
};

//                                               Create Airports Hash Table
// ===================================================================================================================
AIRPORTS_CATALOG create_airports_catalog()
{
    AIRPORTS_CATALOG new_catalog = malloc(sizeof(struct airports_catalog));
    new_catalog->airports = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)airport_destroy_function);
    return new_catalog;
}

//                                               Build an airport
// ===================================================================================================================

void build_airport(AIRPORTS_CATALOG catalog, char *name, int delay, char *flight_id)
{
    if (contains_airport(catalog, name) == 1)
    {
        AIRPORT found = g_hash_table_lookup(catalog->airports, name);
        set_airport_delay_list(found, delay);
        set_airport_flight_list(found, flight_id);
    }
    else
    {
        AIRPORT airport = create_airport();
        set_airport_name(airport, name);
        set_airport_delay_list(airport, delay);
        set_airport_flight_list(airport, flight_id);

        // to insert we give the hashtable which we're going to insert in, the struct to insert and the key (we pass the string and then change it)
        insert_airport(catalog, airport, name);
    }
}

//                                               Insert an airport
// ===================================================================================================================

void insert_airport(AIRPORTS_CATALOG catalog, AIRPORT airport, char *key)
{
    char *id_dup = g_strdup(key);
    g_hash_table_insert(catalog->airports, id_dup, GINT_TO_POINTER(airport));
}

//                                               Lookup Airport
// ===================================================================================================================

AIRPORT lookup_airport(AIRPORTS_CATALOG catalog, char *airport_id)
{
    AIRPORT found_airport = NULL;
    found_airport = g_hash_table_lookup(catalog->airports, airport_id);
    return found_airport;
}

//                                               Contains Airport
// ===================================================================================================================

int contains_airport(AIRPORTS_CATALOG catalog, char *key)
{
    if (g_hash_table_contains(catalog->airports, key))
        return 1;
    else
        return 0;
}

//                                               Destroy Catalog
// ===================================================================================================================

void free_airports_catalog(AIRPORTS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->airports);
    free(catalog);
}

//                                               Iterate the HashTable
// ===================================================================================================================

void iterate_airports(AIRPORTS_CATALOG catalog, AirportIteratorFunc iterator_func, void *user_data)
{
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->airports);

    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        AIRPORT airport = value;
        iterator_func(airport, user_data);
    }
}

void iterate_airports_no_data(AIRPORTS_CATALOG catalog, AirportIteratorFuncNoData iterator_func)
{
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->airports);

    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        AIRPORT airport = value;
        iterator_func(airport);
    }
}