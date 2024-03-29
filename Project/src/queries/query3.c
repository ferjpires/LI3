#include "queries/query3.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "catalogs/reservations_catalog.h"
#include "entities/reservation.h"
#include "catalogs/hotels_catalog.h"


//============================== Write Functions ==============================

void _write_hotel_rating_(double rating, FILE *output, int flag)
{
    if (flag == 1)
        fprintf(output, "--- 1 ---\nrating: %.3f\n", rating);
    else
        fprintf(output, "%.3f\n", rating);
}

//                                          Execution of query three
// ===================================================================================================================

void exec_query_three(HOTELS_CATALOG hotels_catalog, char *arguments, FILE *output, int flag)
{
    double rating = 0.0;
    HOTEL hotel = lookup_hotel(hotels_catalog, arguments);
    if (hotel != NULL) rating = get_hotel_rating(hotel);
    _write_hotel_rating_(rating, output, flag);
}
