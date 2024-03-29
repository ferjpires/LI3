#ifndef RESERVATION_STATS_H
#define RESERVATION_STATS_H

#include <glib.h>

#include "entities/reservation.h"
#include "catalogs/reservations_catalog.h"

/**
 * @brief Calculates the total cost of a reservation based on the price per night, number of nights, and city tax.
 *
 * This function takes the price per night, number of nights, and city tax of a reservation, and computes the total cost
 * by multiplying the price per night by the number of nights and adding the city tax. The result represents the total
 * cost of the reservation.
 *
 * @param price_per_night The price per night of the reservation as a string.
 * @param number_of_nights The number of nights of the reservation.
 * @param city_tax The city tax of the reservation as a string.
 *
 * @return The total cost of the reservation as a double.
 */
double _get_reservation_total_cost(char *price_per_night, int number_of_nights, char *city_tax);

/**
 * @brief Calculates the total number of nights of a reservation based on the begin and end dates.
 *
 * This function takes the begin date and end date of a reservation and calculates the total number of nights
 * by finding the difference between the two dates. The result represents the total duration of the reservation in nights.
 *
 * @param begin_date The begin date of the reservation as a string.
 * @param end_date The end date of the reservation as a string.
 *
 * @return The total number of nights of the reservation as an integer.
 */
int _get_reservation_total_nights(char *begin_date, char *end_date);

#endif