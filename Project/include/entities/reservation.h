#ifndef RESERVATION_H
#define RESERVATION_H

#include <glib.h>

typedef struct reservation *RESERVATION;

/**
 * @brief Creates a new reservation
 *
 * @return new_reservation - The new reservation of type 'RESERVATION'
 */
RESERVATION create_reservation(void);

/**
 * @brief Sets the reservation id
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param id - The id of type 'char*'
 */
void set_reservation_id(RESERVATION reservation, char *id);

/**
 * @brief Gets the reservation id
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return id - The reservation id of type 'char*'
 */
char *get_reservation_id(RESERVATION reservation);

/**
 * @brief Sets the reservation user id
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param user_id - The user id of type 'char*'
 */
void set_reservation_user_id(RESERVATION reservation, char *user_id);

/**
 * @brief Gets the reservation user id
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return user id - The reservation user id of type 'char*'
 */
char *get_reservation_user_id(RESERVATION reservation);

/**
 * @brief Sets the reservation hotel id
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param hotel_id - The hotel id of type 'char*'
 */
void set_reservation_hotel_id(RESERVATION reservation, char *hotel_id);

/**
 * @brief Gets the reservation hotel id
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return hotel id - The reservation hotel id of type 'char*'
 */
char *get_reservation_hotel_id(RESERVATION reservation);

/**
 * @brief Sets the reservation hotel name
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param hotel_name - The hotel name of type 'char*'
 */
void set_reservation_hotel_name(RESERVATION reservation, char *hotel_name);

/**
 * @brief Gets the reservation hotel name
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return hotel name - The reservation hotel name of type 'char*'
 */
char *get_reservation_hotel_name(RESERVATION reservation);

/**
 * @brief Sets the reservation hotel stars
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param hotel_stars - The hotel stars of type 'char*'
 */
void set_reservation_hotel_stars(RESERVATION reservation, char *hotel_stars);

/**
 * @brief Gets the reservation hotel stars
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return hotel stars - The reservation hotel stars of type 'char*'
 */
char *get_reservation_hotel_stars(RESERVATION reservation);

/**
 * @brief Sets the reservation city tax
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param city_tax - The city tax of type 'char*'
 */
void set_reservation_city_tax(RESERVATION reservation, char *city_tax);

/**
 * @brief Gets the reservation city tax
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return city tax - The reservation city tax of type 'char*'
 */
char *get_reservation_city_tax(RESERVATION reservation);

/**
 * @brief Sets the reservation begin date
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param begin_date - The begin date of type 'char*'
 */
void set_reservation_begin_date(RESERVATION reservation, char *begin_date);

/**
 * @brief Gets the reservation begin date
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return begin date - The reservation begin date of type 'char*'
 */
char *get_reservation_begin_date(RESERVATION reservation);

/**
 * @brief Sets the reservation end date
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param end_date - The end date of type 'char*'
 */
void set_reservation_end_date(RESERVATION reservation, char *end_date);

/**
 * @brief Gets the reservation end date
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return end date - The reservation end date of type 'char*'
 */
char *get_reservation_end_date(RESERVATION reservation);

/**
 * @brief Sets the reservation price per night
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param price_per_night - The price per night of type 'char*'
 */
void set_reservation_price_per_night(RESERVATION reservation, char *price_per_night);

/**
 * @brief Gets the reservation price per night
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return price per night - The reservation price per night of type 'char*'
 */
char *get_reservation_price_per_night(RESERVATION reservation);

/**
 * @brief Sets the reservation includes breakfast
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param includes_breakfast - The includes breakfast of type 'char*'
 */
void set_reservation_includes_breakfast(RESERVATION reservation, char *includes_breakfast);

/**
 * @brief Gets the reservation includes breakfast
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return includes breakfast - The reservation includes breakfast of type 'char*'
 */
char *get_reservation_includes_breakfast(RESERVATION reservation);

/**
 * @brief Sets the reservation rating
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param rating - The rating of type 'char*'
 */
void set_reservation_rating(RESERVATION reservation, char *rating);

/**
 * @brief Gets the reservation rating
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return rating - The reservation rating of type 'int'
 */
int get_reservation_rating(RESERVATION reservation);

/**
 * @brief Verifies if a reservation id is valid
 *
 * @param str - The reservation id of type 'char*'
 */
int _is_reservation_id(char *str);

/**
 * @brief Gets the reservation number of nights
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return number of nights - The reservation number of nights of type 'int'
 */
int get_reservation_number_of_nights(RESERVATION reservation);

/**
 * @brief Sets the reservation number of nights
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param number_of_nights - The number of nights of type 'int'
 */
void set_reservation_number_of_nights(RESERVATION reservation, int number_of_nights);

/**
 * @brief Gets the reservation total price
 *
 * @param reservation - The reservation of type 'RESERVATION'
 *
 * @return total price - The reservation total price of type 'double'
 */
double get_reservation_total_price(RESERVATION reservation);

/**
 * @brief Sets the reservation total price
 *
 * @param reservation - The reservation of type 'RESERVATION'
 * @param total_price - The total price of type 'double'
 */
void set_reservation_total_price(RESERVATION reservation, double total_price);

/**
 * @brief Free's the reservation memory
 *
 * @param data - The reservation of type 'gpointer'
 *
 */
void reservation_destroy_function(gpointer data);

#endif