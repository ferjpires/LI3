#include <glib.h>
#include <string.h>
#include <stdio.h>

#include "entities/reservation.h"

struct reservation
{
    int id;
    char *user_id;
    int hotel_id;
    char *hotel_name;
    int hotel_stars;
    int city_tax;
    int begin_date;
    int end_date;
    int price_per_night;
    int includes_breakfast;
    int rating;
    int number_of_nights;
    double total_price;
};

//                                               Create a reservation
// ===================================================================================================================

RESERVATION create_reservation(void)
{
    RESERVATION new_reservation = malloc(sizeof(struct reservation));

    new_reservation->id = 0;
    new_reservation->user_id = NULL;
    new_reservation->hotel_id = 0;
    new_reservation->hotel_name = NULL;
    new_reservation->hotel_stars = 0;
    new_reservation->city_tax = 0;
    new_reservation->begin_date = 0;
    new_reservation->end_date = 0;
    new_reservation->price_per_night = 0;
    new_reservation->includes_breakfast = 0;
    new_reservation->rating = 0;

    return new_reservation;
}

//                                               ID
// ===================================================================================================================

char *get_reservation_id(RESERVATION reservation)
{
    char id[16];
    sprintf(id, "Book%010d", reservation->id);
    return g_strdup(id);
}
void set_reservation_id(RESERVATION reservation, char *id)
{
    char *numericPart = id + strlen("Book");
    reservation->id = atoi(numericPart);
}

//                                               USER ID
// ===================================================================================================================

char *get_reservation_user_id(RESERVATION reservation)
{
    return g_strdup(reservation->user_id);
}
void set_reservation_user_id(RESERVATION reservation, char *user_id)
{
    free(reservation->user_id); // release previous one
    reservation->user_id = g_strdup(user_id);
}

//                                               Hotel ID
// ===================================================================================================================

char *get_reservation_hotel_id(RESERVATION reservation)
{
    char id[9];
    sprintf(id, "HTL%d", reservation->hotel_id);
    return strdup(id);
}
void set_reservation_hotel_id(RESERVATION reservation, char *hotel_id)
{
    char *numericPart = hotel_id + strlen("HTL");
    reservation->hotel_id = atoi(numericPart);
}

//                                               Hotel Name
// ===================================================================================================================

char *get_reservation_hotel_name(RESERVATION reservation)
{
    return g_strdup(reservation->hotel_name);
}
void set_reservation_hotel_name(RESERVATION reservation, char *hotel_name)
{
    free(reservation->hotel_name); // release previous one
    reservation->hotel_name = g_strdup(hotel_name);
}

//                                               Hotel Stars
// ===================================================================================================================

char *get_reservation_hotel_stars(RESERVATION reservation)
{
    char stars[5];
    sprintf(stars, "%d", reservation->hotel_stars);
    return g_strdup(stars);
}
void set_reservation_hotel_stars(RESERVATION reservation, char *hotel_stars)
{
    reservation->hotel_stars = atoi(hotel_stars);
}

//                                               City Tax
// ===================================================================================================================

char *get_reservation_city_tax(RESERVATION reservation)
{
    char tax[5];
    sprintf(tax, "%d", reservation->city_tax);
    return g_strdup(tax);
}
void set_reservation_city_tax(RESERVATION reservation, char *city_tax)
{
    reservation->city_tax = atoi(city_tax);
}

//                                               Begin Date
// ===================================================================================================================

char *get_reservation_begin_date(RESERVATION reservation)
{
    char *date = malloc(20 * sizeof(char));
    sprintf(date, "%04d/%02d/%02d", reservation->begin_date / 10000, (reservation->begin_date % 10000) / 100, reservation->begin_date % 100);
    return date;
}
void set_reservation_begin_date(RESERVATION reservation, char *begin_date)
{
    int year, month, day;
    if (sscanf(begin_date, "%d/%d/%d", &year, &month, &day) == 3)
        reservation->begin_date = year * 10000 + month * 100 + day;
}

//                                               End Date
// ===================================================================================================================

char *get_reservation_end_date(RESERVATION reservation)
{
    char *date = malloc(20 * sizeof(char));
    sprintf(date, "%04d/%02d/%02d", reservation->end_date / 10000, (reservation->end_date % 10000) / 100, reservation->end_date % 100);
    return date;
}
void set_reservation_end_date(RESERVATION reservation, char *end_date)
{
    int year, month, day;
    if (sscanf(end_date, "%d/%d/%d", &year, &month, &day) == 3)
        reservation->end_date = year * 10000 + month * 100 + day;
}

//                                               Price per Night
// ===================================================================================================================

char *get_reservation_price_per_night(RESERVATION reservation)
{
    char price[6];
    sprintf(price, "%d", reservation->price_per_night);
    return g_strdup(price);
}
void set_reservation_price_per_night(RESERVATION reservation, char *price_per_night)
{
    reservation->price_per_night = atoi(price_per_night);
}

//                                               Includes Breakfast
// ===================================================================================================================

char *get_reservation_includes_breakfast(RESERVATION reservation)
{
    if (reservation->includes_breakfast == 1)
        return g_strdup("True");
    else
        return g_strdup("False");
}
void set_reservation_includes_breakfast(RESERVATION reservation, char *includes_breakfast)
{
    if (strcasecmp(includes_breakfast, "true") == 0 || strcasecmp(includes_breakfast, "t") == 0 || g_strcmp0(includes_breakfast, "1") == 0)
        reservation->includes_breakfast = 1;
    else
        reservation->includes_breakfast = 0;
}

//                                               Rating
// ===================================================================================================================

int get_reservation_rating(RESERVATION reservation)
{
    return reservation->rating;
}
void set_reservation_rating(RESERVATION reservation, char *rating)
{
    // free(reservation->rating); // release previous one
    // reservation->rating = g_strdup(rating);
    reservation->rating = atoi(rating);
}

//                                               Validation
// ===================================================================================================================

int _is_reservation_id(char *str)
{
    if (strlen(str) >= 4 && strncmp(str, "Book", 4) == 0)
        return 1; // The first 4 characters are "Book"

    else
        return 0; // The first 4 characters are not "Book"
}

//                                               Number Of Nights
// ===================================================================================================================

int get_reservation_number_of_nights(RESERVATION reservation)
{
    return reservation->number_of_nights;
}
void set_reservation_number_of_nights(RESERVATION reservation, int number_of_nights)
{
    reservation->number_of_nights = number_of_nights;
}

//                                               Total Price
// ===================================================================================================================

double get_reservation_total_price(RESERVATION reservation)
{
    return reservation->total_price;
}
void set_reservation_total_price(RESERVATION reservation, double total_price)
{
    reservation->total_price = total_price;
}

//                                               Free reservation
// ===================================================================================================================

void reservation_destroy_function(gpointer data)
{
    RESERVATION reservation = (RESERVATION)data;

    // Free dynamically allocated strings
    free(reservation->user_id);
    free(reservation->hotel_name);

    // Free the reservation structure itself
    g_free(reservation);
}
