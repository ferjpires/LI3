#ifndef PARSER_H
#define PARSER_H

#include <glib.h>

#include "data_manager/validater.h"
#include "data_manager/flight_stats.h"
#include "data_manager/reservation_stats.h"
#include "data_manager/airport_stats.h"
#include "data_manager/user_stats.h"
#include "entities/flight.h"
#include "entities/user.h"
#include "entities/reservation.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/users_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "stats/metrics_catalog.h"
#include "stats/metric_manager.h"
#include "utils/parser_utils.h"

/**
 * @brief Initializes the parser to read and process files containing user, flight, reservation, and passenger data.
 *
 * This function initializes the parser to read data from specified files and populates catalogs with users, flights,
 * reservations, and passengers. The provided file pointers represent the input files containing relevant data. The
 * metrics catalog is also updated to record parsing times for analysis.
 *
 * @param users_catalog The catalog to be filled with user information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog to be filled with flight information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog to be filled with reservation information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The catalog to be filled with airport information of type 'AIRPORTS_CATALOG'.
 * @param hotels_catalog The catalog to be filled with hotel information of type 'HOTELS_CATALOG'.
 * @param users_file The file containing user data of type 'FILE'.
 * @param flights_file The file containing flight data of type 'FILE'.
 * @param reservations_file The file containing reservation data of type 'FILE'.
 * @param passengers_file The file containing passenger data of type 'FILE'.
 * @param metrics The METRICS_CATALOG for recording and analyzing metrics data.
 */
void parser(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
            AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog,
            FILE *users_file, FILE *flights_file, FILE *reservations_file, FILE *passengers_file,
            METRICS_CATALOG metrics);

/**
 * @brief Reads data from a file, sets the flight, and inserts it into the flight catalog.
 *
 * This function reads data from a specified file, creates a flight object, and inserts it into the flight catalog.
 * The provided catalogs include flight and airport information, and the METRICS_CATALOG is updated to record parsing times.
 *
 * @param catalog The catalog to be filled with flight information of type 'FLIGHTS_CATALOG'.
 * @param airports_catalog The catalog containing airport information of type 'AIRPORTS_CATALOG'.
 * @param file The file containing flight data of type 'FILE'.
 * @param metrics The METRICS_CATALOG for recording and analyzing metrics data.
 */
void set_flight(FLIGHTS_CATALOG catalog, AIRPORTS_CATALOG airports_catalog, FILE *file, METRICS_CATALOG metrics);

/**
 * @brief Reads data from a file, sets the user, and inserts it into the user catalog.
 *
 * This function reads data from a specified file, creates a user object, and inserts it into the user catalog.
 * The METRICS_CATALOG is updated to record parsing times.
 *
 * @param catalog The catalog to be filled with user information of type 'USERS_CATALOG'.
 * @param file The file containing user data of type 'FILE'.
 * @param metrics The METRICS_CATALOG for recording and analyzing metrics data.
 */
void set_user(USERS_CATALOG catalog, FILE *file, METRICS_CATALOG metrics);

/**
 * @brief Reads data from a file, sets the reservation, and inserts it into the reservation catalog.
 *
 * This function reads data from a specified file, creates a reservation object, and inserts it into the reservation catalog.
 * The provided catalogs include reservation, user, and hotel information, and the METRICS_CATALOG is updated to record parsing times.
 *
 * @param reservations_catalog The catalog to be filled with reservation information of type 'RESERVATIONS_CATALOG'.
 * @param users_catalog The catalog containing user information of type 'USERS_CATALOG'.
 * @param hotels_catalog The catalog containing hotel information of type 'HOTELS_CATALOG'.
 * @param file The file containing reservation data of type 'FILE'.
 * @param metrics The METRICS_CATALOG for recording and analyzing metrics data.
 */
void set_reservation(RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog, HOTELS_CATALOG hotels_catalog,
                     FILE *file, METRICS_CATALOG metrics);

/**
 * @brief Reads data from a file, sets the passenger, and inserts it into the flights catalog.
 *
 * This function reads data from a specified file, creates a passenger object, and inserts it into the flights catalog.
 * The provided catalogs include flight and user information, and the METRICS_CATALOG is updated to record parsing times.
 *
 * @param flights_catalog The catalog to be filled with flight information of type 'FLIGHTS_CATALOG'.
 * @param users_catalog The catalog containing user information of type 'USERS_CATALOG'.
 * @param file The file containing passenger data of type 'FILE'.
 * @param metrics The METRICS_CATALOG for recording and analyzing metrics data.
 */
void set_passenger(FLIGHTS_CATALOG flights_catalog, USERS_CATALOG users_catalog, FILE *file, METRICS_CATALOG metrics);

#endif