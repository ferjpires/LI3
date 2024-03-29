#include <ctype.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

#include "entities/reservation.h"
#include "data_manager/validater.h"
#include "catalogs/reservations_catalog.h"

struct reservations_catalog
{
    GHashTable *reservations;
};

//                                               Create Reservations Hash Table
// ===================================================================================================================
RESERVATIONS_CATALOG create_reservations_catalog()
{
    RESERVATIONS_CATALOG new_catalog = malloc(sizeof(struct reservations_catalog));
    new_catalog->reservations = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)reservation_destroy_function);
    return new_catalog;
}

//                                               Build a reservation
// ===================================================================================================================

void build_reservation(char **reservation_params, int number_of_nights, double total_price, RESERVATIONS_CATALOG catalog)
{

    RESERVATION reservation = create_reservation();

    set_reservation_id(reservation, reservation_params[0]);
    set_reservation_user_id(reservation, reservation_params[1]);
    set_reservation_hotel_id(reservation, reservation_params[2]);
    set_reservation_hotel_name(reservation, reservation_params[3]);
    set_reservation_hotel_stars(reservation, reservation_params[4]);
    set_reservation_city_tax(reservation, reservation_params[5]);
    set_reservation_begin_date(reservation, reservation_params[7]);
    set_reservation_end_date(reservation, reservation_params[8]);
    set_reservation_price_per_night(reservation, reservation_params[9]);
    set_reservation_includes_breakfast(reservation, reservation_params[10]);
    set_reservation_rating(reservation, reservation_params[12]);
    set_reservation_number_of_nights(reservation, number_of_nights);
    set_reservation_total_price(reservation, total_price);

    // to insert we give the hashtable which we're going to insert in, the struct to insert and the key (we pass the string and then change it)
    insert_reservation(catalog, reservation, reservation_params[0]);
}

//                                               Insert a reservation
// ===================================================================================================================

void insert_reservation(RESERVATIONS_CATALOG catalog, RESERVATION reservation, char *key)
{
    char *id_dup = g_strdup(key);
    g_hash_table_insert(catalog->reservations, id_dup, GINT_TO_POINTER(reservation));
}

//                                               Lookup Reservation
// ===================================================================================================================

RESERVATION lookup_reservation(RESERVATIONS_CATALOG catalog, char *reservation_id)
{
    RESERVATION found_reservation = NULL;
    found_reservation = g_hash_table_lookup(catalog->reservations, reservation_id);
    return found_reservation;
}

//                                               Destroy Catalog
// ===================================================================================================================

void free_reservations_catalog(RESERVATIONS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->reservations);
    free(catalog);
}
