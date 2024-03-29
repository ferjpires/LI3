#ifndef FLIGHT_STATS_H
#define FLIGHT_STATS_H

#include "data_manager/validater.h"
#include "entities/flight.h"

/**
 * @brief Calculates the total delay of a flight
 *        This calculation is made using the schedule departure date and real departure date
 *        We use this function every time we parse a flight to help us later in some queries
 *
 * @param date1 - The schedule departure date of a flight of type 'char*'
 * @param date2 - The real departure date of a flight of type 'char*'
 *
 * @return The calculated delay of the flight given the dates
 */
int _get_flight_delay(char *date1, char *date2);

#endif