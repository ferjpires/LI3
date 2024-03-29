#ifndef METRICS_MANAGER_H
#define METRICS_MANAGER_H

#include "stats/metrics_catalog.h"
#include "entities/user.h"

/**
 * @brief Sets in the metrics catalog the statistics from the flights
 *
 * @param metrics - The metrics catalog of type 'METRICS_CATALOG'
 * @param date - The date to insert of type 'char*'
 */
void flight_metrics(METRICS_CATALOG metrics, char *date);

/**
 * @brief Sets in the metrics catalog the statistics from the users
 *
 * @param metrics - The metrics catalog of type 'METRICS_CATALOG'
 * @param date - The date to insert of type 'char*'
 */
void user_metrics(METRICS_CATALOG metrics, char *date);

/**
 * @brief Sets in the metrics catalog the statistics from the reservations
 *
 * @param metrics - The metrics catalog of type 'METRICS_CATALOG'
 * @param date - The date to insert of type 'char*'
 */
void reservation_metrics(METRICS_CATALOG metrics, char *date);

/**
 * @brief Sets in the metrics catalog the statistics from the passengers
 *
 * @param metrics - The metrics catalog of type 'METRICS_CATALOG'
 * @param date - The date to insert of type 'char*'
 * @param user - The user to check account creation of type 'USER'
 */
void passenger_metrics(METRICS_CATALOG metrics, char *date, USER user);

#endif