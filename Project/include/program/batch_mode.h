#ifndef BATCH_MODE_H
#define BATCH_MODE_H

#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "stats/metrics_catalog.h"

/**
 * @brief Executes the program in batch mode.
 *
 * This function processes a series of commands provided in a file, executing queries
 * and operations on user, flight, reservation, airport, hotel catalogs, and updating metrics.
 * The catalogs and metrics are expected to be initialized and filled with data before calling
 * this function.
 *
 * @param path Path to the directory containing the CSV files.
 * @param commands Path to the file containing the queries.
 * @param users_catalog Users catalog initialized and populated with user data.
 * @param flights_catalog Flights catalog initialized and populated with flight data.
 * @param reservations_catalog Reservations catalog initialized and populated with reservation data.
 * @param airports_catalog Airports catalog initialized and populated with airport data.
 * @param hotels_catalog Hotels catalog initialized and populated with hotel data.
 * @param metrics Metrics catalog initialized and populated with metric data.
 */
void exec_batch_mode(char *path, char *commands, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog,
                     RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog,
                     METRICS_CATALOG metrics);

#endif