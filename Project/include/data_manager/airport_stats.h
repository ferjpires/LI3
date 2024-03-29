#ifndef AIRPORT_STATS_H
#define AIRPORT_STATS_H

#include "catalogs/flights_catalog.h"
#include "catalogs/airports_catalog.h"
#include "entities/flight.h"
#include "entities/airport.h"
#include "data_manager/flight_stats.h"

/**
 * @brief Orders the airports list by the median of the delays of the flights
 *
 * @param airports_catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 */
void order_airports_list(AIRPORTS_CATALOG airports_catalog);

/**
 * @brief Calculates the median of the delays of the flights of an airport and sets it
 *
 * @param airport - The airport of type 'AIRPORT'
 */
void set_median(AIRPORT airport);

/**
 * @brief Calculates the median of the delays of the flights of all the airports
 *
 * @param airports_catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 */
void stats_for_seven(AIRPORTS_CATALOG airports_catalog);

/**
 * @brief Adds the number of passengers of a flight to the airports
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param user_data - The airports catalog of type 'void*'
 */
void add_passengers(FLIGHT flight, void *user_data);

/**
 * @brief Calculates the number of passengers of each airport in each year
 *
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param airports_catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 */
void stats_for_six(FLIGHTS_CATALOG flights_catalog, AIRPORTS_CATALOG airports_catalog);

/**
 * @brief Calculates the median of a list of delays
 *
 * @param list - The list of delays of type 'GArray*'
 */
double calculate_median(GArray *list);

#endif