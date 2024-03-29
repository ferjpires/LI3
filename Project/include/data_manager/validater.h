#ifndef VALIDATER_H
#define VALIDATER_H

#include <glib.h>

/**
 * @brief Checks if a date is in a valid format.
 *
 * This function verifies whether the provided date follows a valid format.
 *
 * @param date The date to be validated of type 'char*'.
 *
 * @return 1 If the date is in a valid format.
 * @return 0 If the date is not in a valid format.
 */
int is_valid_date(char *date);

/**
 * @brief Checks if a date with time is in a valid format.
 *
 * This function verifies whether the provided date with time follows a valid format.
 *
 * @param date The date with time to be validated of type 'char*'.
 *
 * @return 1 If the date with time is in a valid format.
 * @return 0 If the date with time is not in a valid format.
 */
int is_valid_date_with_time(char *date);

/**
 * @brief Converts a date to a numeric representation.
 *
 * This function converts a date string to a numerical representation for comparison purposes.
 *
 * @param date The date to be converted of type 'char*'.
 *
 * @return The numeric value of the date.
 */
int date_to_number(char *date);

/**
 * @brief Compares two dates.
 *
 * This function compares two dates and returns:
 * - 1 if the first date is greater than the second date.
 * - 0 if the first date is equal to the second date.
 * - -1 if the first date is less than the second date.
 *
 * @param date1 The first date of type 'char*'.
 * @param date2 The second date of type 'char*'.
 *
 * @return The comparison result as an integer.
 */
int date_compare(char *date1, char *date2);

/**
 * @brief Converts a date with time to a numeric representation.
 *
 * This function converts a date with time string to a numerical representation for comparison purposes.
 *
 * @param date The date with time to be converted of type 'char*'.
 *
 * @return The numeric value of the date with time.
 */
int date_with_time_to_number(char *date);

/**
 * @brief Compares two dates with time.
 *
 * This function compares two dates with time and returns:
 * - 1 if the first date with time is greater than the second date with time.
 * - 0 if the first date with time is equal to the second date with time.
 * - -1 if the first date with time is less than the second date with time.
 *
 * @param date1 The first date with time of type 'char*'.
 * @param date2 The second date with time of type 'char*'.
 *
 * @return The comparison result as an integer.
 */
int date_compare_with_time(char *date1, char *date2);

/**
 * @brief Validates the order of flight departure and arrival times.
 *
 * This function checks if the departure time is after the arrival time for a flight.
 *
 * @param departure_time The departure time of type 'char*'.
 * @param arrival_time The arrival time of type 'char*'.
 *
 * @return 1 If the departure time is greater than the arrival time.
 * @return 0 If they are equal.
 * @return -1 If the departure time is smaller than the arrival time.
 */
int flight_departure_arrival_validation(char *departure_time, char *arrival_time);

/**
 * @brief Validates the order of reservation begin and end dates.
 *
 * This function checks if the begin date is before the end date for a reservation.
 *
 * @param begin_date The begin date of type 'char*'.
 * @param end_date The end date of type 'char*'.
 *
 * @return 1 If the begin date is before the end date.
 */
int reservation_date_validation(char *begin_date, char *end_date);

/**
 * @brief Checks if an email address is in a valid format.
 *
 * This function verifies whether the provided email address follows a valid format.
 *
 * @param email The email address to be validated of type 'char*'.
 *
 * @return 1 If the email address is in a valid format.
 * @return 0 If the email address is not in a valid format.
 */
int is_email_valid(char *email);

/**
 * @brief Checks if a country code is in a valid format.
 *
 * This function verifies whether the provided country code follows a valid format.
 *
 * @param country_code The country code to be validated of type 'char*'.
 *
 * @return 1 If the country code is in a valid format.
 * @return 0 If the country code is not in a valid format.
 */
int is_country_code_valid(char *country_code);

/**
 * @brief Checks if an account status is valid.
 *
 * This function checks if the provided account status is valid.
 *
 * @param account_status The account status to be validated of type 'char*'.
 *
 * @return 1 If the account status is valid.
 */
int is_account_status_valid(char *account_status);

/**
 * @brief Checks if a user account is active.
 *
 * This function checks if the provided user account status indicates an active account.
 *
 * @param account_status The account status of type 'char*'.
 *
 * @return 1 If the user account is active.
 */
int is_user_active(char *account_status);

/**
 * @brief Checks if the total seats value is valid.
 *
 * This function checks if the provided total seats value is valid.
 *
 * @param total_seats The total seats value to be validated of type 'char*'.
 *
 * @return 1 If the total seats value is valid.
 */
int is_total_seats_valid(char *total_seats);

/**
 * @brief Checks if the total seats value for a flight is valid compared to the number of passengers.
 *
 * This function checks if the provided total seats value for a flight is valid compared to the number of passengers.
 *
 * @param total_seats The total seats value for the flight of type 'char*'.
 * @param number_of_passengers The number of passengers for the flight of type 'int'.
 *
 * @return 1 If the total seats value is valid.
 */
int is_flight_total_seats_valid(char *total_seats, int number_of_passengers);

/**
 * @brief Checks if an airport name is in a valid format.
 *
 * This function verifies whether the provided airport name follows a valid format.
 *
 * @param airport The airport name to be validated of type 'char*'.
 *
 * @return 1 If the airport name is in a valid format.
 */
int is_airport_name_valid(char *airport);

/**
 * @brief Checks if a hotel star rating is in a valid format.
 *
 * This function verifies whether the provided hotel star rating follows a valid format.
 *
 * @param hotel_stars The hotel star rating to be validated of type 'char*'.
 *
 * @return 1 If the hotel star rating is in a valid format.
 */
int is_hotel_stars_valid(char *hotel_stars);

/**
 * @brief Checks if a city tax value is valid.
 *
 * This function checks if the provided city tax value is valid.
 *
 * @param city_tax The city tax value to be validated of type 'char*'.
 *
 * @return 1 If the city tax value is valid.
 */
int is_city_tax_valid(char *city_tax);

/**
 * @brief Checks if a price per night value is valid.
 *
 * This function checks if the provided price per night value is valid.
 *
 * @param price_per_night The price per night value to be validated of type 'char*'.
 *
 * @return 1 If the price per night value is valid.
 */
int is_price_per_night_valid(char *price_per_night);

/**
 * @brief Checks if an "includes breakfast" indicator is in a valid format.
 *
 * This function verifies whether the provided "includes breakfast" indicator follows a valid format.
 *
 * @param includes_breakfast The "includes breakfast" indicator to be validated of type 'char*'.
 *
 * @return 1 If the "includes breakfast" indicator is in a valid format.
 */
int is_includes_breakfast_valid(char *includes_breakfast);

/**
 * @brief Checks if a hotel rating value is valid.
 *
 * This function checks if the provided hotel rating value is valid.
 *
 * @param rating The hotel rating value to be validated of type 'char*'.
 *
 * @return 1 If the hotel rating value is valid.
 */
int is_rating_valid(char *rating);

/**
 * @brief Checks if a generic parameter value is valid.
 *
 * This function checks if the provided generic parameter value is valid.
 *
 * @param param The parameter value to be validated of type 'char*'.
 *
 * @return 1 If the parameter value is valid.
 */
int is_param_valid(char *param);

/**
 * @brief Checks if the information of a user is valid.
 *
 * This function checks if the provided information about a user is valid.
 *
 * @param info The information about the user as an array of strings of type 'char**'.
 *
 * @return 1 If the user information is valid.
 */
int is_user_valid(char **info);

/**
 * @brief Checks if the information of a flight is valid.
 *
 * This function checks if the provided information about a flight is valid.
 *
 * @param info The information about the flight as an array of strings of type 'char**'.
 *
 * @return 1 If the flight information is valid.
 */
int is_flight_valid(char **info);

/**
 * @brief Checks if the information of a reservation is valid.
 *
 * This function checks if the provided information about a reservation is valid.
 *
 * @param info The information about the reservation as an array of strings of type 'char**'.
 *
 * @return 1 If the reservation information is valid.
 */
int is_reservation_valid(char **info);

#endif