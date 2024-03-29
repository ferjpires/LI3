#include <glib.h>

#include "catalogs/hotels_catalog.h"
#include "entities/hotel.h"

struct hotels_catalog
{
    GHashTable *hotels;
};

//                                               Create Hotels Hash Table
// ===================================================================================================================
HOTELS_CATALOG create_hotels_catalog()
{
    HOTELS_CATALOG new_catalog = malloc(sizeof(struct hotels_catalog));
    new_catalog->hotels = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)hotel_destroy_function);
    return new_catalog;
}

//                                               Build an hotel
// ===================================================================================================================

void build_hotel(HOTELS_CATALOG catalog, char *hotel_id, char *hotel_rating, char *reservation_id)
{
    HOTEL hotel = create_hotel();

    set_hotel_id(hotel, hotel_id);
    set_hotel_rating(hotel, hotel_rating);
    set_hotel_reservation_list(hotel, reservation_id);

    // to insert we give the hashtable which we're going to insert in, the struct to insert and the key (we pass the string and then change it)
    insert_hotel(catalog, hotel, hotel_id);
}

//                                               Insert an hotel
// ===================================================================================================================

void insert_hotel(HOTELS_CATALOG catalog, HOTEL hotel, char *key)
{
    char *id_dup = g_strdup(key);
    g_hash_table_insert(catalog->hotels, id_dup, GINT_TO_POINTER(hotel));
}

//                                               Lookup an hotel
// ===================================================================================================================

HOTEL lookup_hotel(HOTELS_CATALOG catalog, char *hotel_id)
{
    HOTEL found_hotel = g_hash_table_lookup(catalog->hotels, hotel_id);
    return found_hotel;
}

//                                               Contains Hotel
// ===================================================================================================================

int contains_hotel(HOTELS_CATALOG catalog, char *key)
{
    if (g_hash_table_contains(catalog->hotels, key))
        return 1;
    else
        return 0;
}

//                                               Destroy Catalog
// ===================================================================================================================

void free_hotels_catalog(HOTELS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->hotels);
    free(catalog);
}