#include <stdio.h>
#include <glib.h>

#include "entities/hotel.h"

struct hotel
{
    int id;
    double rating;
    double number_of_ratings;
    GArray *reservation_list;
};

//                                               Create an hotel
// ===================================================================================================================

HOTEL create_hotel(void)
{
    HOTEL new_hotel = malloc(sizeof(struct hotel));

    new_hotel->id = 0;
    new_hotel->rating = 0.0;
    new_hotel->number_of_ratings = 0.0;
    new_hotel->reservation_list = g_array_new(FALSE, FALSE, sizeof(int));

    return new_hotel;
}

//                                               ID
// ===================================================================================================================

char *get_hotel_id(HOTEL hotel)
{
    char id[9];
    sprintf(id, "HTL%d", hotel->id);
    return strdup(id);
}
void set_hotel_id(HOTEL hotel, char *id)
{
    char *numericPart = id + strlen("HTL");
    hotel->id = atoi(numericPart);
}

//                                               Rating
// ===================================================================================================================

double get_hotel_rating(HOTEL hotel)
{
    return (hotel->rating / hotel->number_of_ratings);
}
void set_hotel_rating(HOTEL hotel, char *rating)
{
    double rat = strtod(rating, NULL);
    hotel->rating += rat;
    hotel->number_of_ratings++;
}

//                                               Reservation List
// ===================================================================================================================

GArray *get_hotel_reservation_list(HOTEL hotel)
{
    return g_array_copy(hotel->reservation_list);
}

void set_hotel_reservation_list(HOTEL hotel, char *reservation_id)
{
    char *numericPart = reservation_id + strlen("Book");
    int id = atoi(numericPart);
    g_array_append_val(hotel->reservation_list, id);
}

//                                               Free Hotel
// ===================================================================================================================

void hotel_destroy_function(gpointer data)
{
    HOTEL hotel = (HOTEL)data;

    g_array_free(hotel->reservation_list, TRUE);

    free(hotel);
}