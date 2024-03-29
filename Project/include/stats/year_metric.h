#ifndef YEAR_METRIC_H
#define YEAR_METRIC_H

#include <stdbool.h>
#include "stats/month_metric.h"

typedef struct year_metric *YEAR_METRIC;

/**
 * @brief Creates a new YEAR_METRIC instance.
 *
 * This function allocates memory for a new YEAR_METRIC and initializes its internal data.
 *
 * @return A pointer to the newly created YEAR_METRIC.
 */
YEAR_METRIC create_year_metric();

/**
 * @brief Retrieves the yearly existence status from a YEAR_METRIC.
 *
 * This function returns the yearly existence status from the provided YEAR_METRIC.
 * The yearly existence status indicates whether the metric has been set for the current year.
 *
 * @param year_metric The YEAR_METRIC instance.
 *
 * @return A boolean value: true if the yearly existence has been set, false otherwise.
 */
bool get_yearly_existence(YEAR_METRIC year_metric);

/**
 * @brief Sets the yearly existence status in a YEAR_METRIC.
 *
 * This function sets the yearly existence status in the provided YEAR_METRIC, indicating
 * that the metric has been recorded for the current year.
 *
 * @param year_metric The YEAR_METRIC instance.
 */
void set_yearly_existence(YEAR_METRIC year_metric);

/**
 * @brief Looks up a monthly MONTH_METRIC for a specific month in the YEAR_METRIC.
 *
 * This function retrieves the MONTH_METRIC associated with a specified month from the YEAR_METRIC.
 *
 * @param year_metric The YEAR_METRIC instance.
 * @param month An integer representing the month for which the MONTH_METRIC is requested.
 *
 * @return The MONTH_METRIC associated with the specified month, or NULL if not found.
 */
MONTH_METRIC lookup_month_metric(YEAR_METRIC year_metric, int month);

/**
 * @brief Frees the memory allocated for the YEAR_METRIC and its contents.
 *
 * This function releases all the memory allocated for the YEAR_METRIC and its associated MONTH_METRICs.
 * It should be called when the YEAR_METRIC is no longer needed to avoid memory leaks.
 *
 * @param year_metric The YEAR_METRIC to be freed.
 */
void free_year_metrics(YEAR_METRIC year_metric);

/**
 * @brief Retrieves the size of the unique users list in a YEAR_METRIC.
 *
 * This function returns the size of the unique users list recorded in the provided YEAR_METRIC.
 *
 * @param year_metric The YEAR_METRIC instance.
 *
 * @return An integer representing the size of the unique users list.
 */
int get_year_unique_users_size(YEAR_METRIC year_metric);

/**
 * @brief Sets the unique users list in a YEAR_METRIC.
 *
 * This function sets the unique users list in the provided YEAR_METRIC.
 *
 * @param year_metric The YEAR_METRIC instance.
 * @param id The ID of the unique user to be added to the list.
 */
void set_year_unique_users(YEAR_METRIC year_metric, char *id);

#endif