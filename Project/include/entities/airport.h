#ifndef AIRPORT_H
#define AIRPORT_H

#include <glib.h>
#include <stdio.h>
#include "utils/utils.h"

typedef struct airport *AIRPORT;

/**
 * @brief Creates a new airport
 *
 * @return new_airport - The new airport of type 'AIRPORT'
 */
AIRPORT create_airport(void);

/**
 * @brief frees the memory allocated for the airport
 *
 * @param data - The airport of type 'gpointer'
 */
void airport_destroy_function(gpointer data);

/**
 * @brief Gets the airport name
 *
 * @param airport - The airport of type 'AIRPORT'
 *
 * @return name - The airport name of type 'char*'
 */
char *get_airport_name(AIRPORT airport);

/**
 * @brief Sets the airport name
 *
 * @param airport - The airport of type 'AIRPORT'
 * @param name - The name of type 'char*'
 */
void set_airport_name(AIRPORT airport, char *name);

/**
 * @brief Gets the airport delay list
 *
 * @param airport - The airport of type 'AIRPORT'
 *
 * @return delay_list - The airport delay list of type 'GArray*'
 */
GArray *get_airport_delay_list(AIRPORT airport);

/**
 * @brief Adds a delay to the airport delay list
 *
 * @param airport - The airport of type 'AIRPORT'
 * @param delay - The delay of type 'int'
 */
void set_airport_delay_list(AIRPORT airport, int delay);

/**
 * @brief Orders the airport delay list
 *
 * @param airport - The airport of type 'AIRPORT'
 */
void order_delay_list(AIRPORT airport);

/**
 * @brief Gets the airport median
 *
 * @param airport - The airport of type 'AIRPORT'
 *
 * @return median - The airport median of type 'int'
 */
int get_airport_median(AIRPORT airport);

/**
 * @brief Sets the airport median
 *
 * @param airport - The airport of type 'AIRPORT'
 * @param median - The median of type 'int'
 */
void set_airport_median(AIRPORT airport, int median);

/**
 * @brief Gets the airport yearly passengers
 *
 * @param airport - The airport of type 'AIRPORT'
 * @param year - The year of type 'char*'
 *
 * @return yearly_passengers - The airport yearly passengers of type 'int'
 */
int get_airport_yearly_passengers(AIRPORT airport, char *year);

/**
 * @brief Adds passengers to the airport yearly passengers
 *
 * @param airport - The airport of type 'AIRPORT'
 * @param year - The year of type 'char*'
 * @param additional_passengers - The additional passengers of type 'int'
 */
void set_airport_yearly_passengers(AIRPORT airport, char *year, int additional_passengers);

/**
 * @brief Gets the airport flight list
 *
 * @param airport - The airport of type 'AIRPORT'
 *
 * @return flight_list - The airport flight list of type 'GArray*'
 */
GArray *get_airport_flight_list(AIRPORT airport);

/**
 * @brief Adds a flight to the airport flight list
 *
 * @param airport - The airport of type 'AIRPORT'
 * @param flight_id - The flight id of type 'char*'
 */
void set_airport_flight_list(AIRPORT airport, char *flight_id);

#endif