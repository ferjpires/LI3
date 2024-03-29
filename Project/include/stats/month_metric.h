#ifndef MONTH_METRIC_C
#define MONTH_METRIC_C

#include <stdbool.h>
#include "stats/metric.h"

typedef struct month_metric *MONTH_METRIC;

/**
 * @brief Creates a new MONTH_METRIC instance.
 *
 * This function allocates memory for a new MONTH_METRIC and initializes its internal data.
 *
 * @return A pointer to the newly created MONTH_METRIC.
 */
MONTH_METRIC create_month_metric();

/**
 * @brief Retrieves the monthly existence status from a MONTH_METRIC.
 *
 * This function returns the monthly existence status from the provided MONTH_METRIC.
 * The monthly existence status indicates whether the metric has been set for the current month.
 *
 * @param month_metric The MONTH_METRIC instance.
 *
 * @return A boolean value: true if the monthly existence has been set, false otherwise.
 */
bool get_monthly_existence(MONTH_METRIC month_metric);

/**
 * @brief Sets the monthly existence status in a MONTH_METRIC.
 *
 * This function sets the monthly existence status in the provided MONTH_METRIC, indicating
 * that the metric has been recorded for the current month.
 *
 * @param month_metric The MONTH_METRIC instance.
 */
void set_monthly_existence(MONTH_METRIC month_metric);

/**
 * @brief Retrieves the month from a MONTH_METRIC.
 *
 * This function returns the month associated with the provided MONTH_METRIC.
 *
 * @param month_metric The MONTH_METRIC instance.
 *
 * @return An integer representing the month (e.g., 1 for January, 2 for February).
 */
int get_month(MONTH_METRIC month_metric);

/**
 * @brief Sets the month in a MONTH_METRIC.
 *
 * This function sets the month in the provided MONTH_METRIC.
 *
 * @param month_metric The MONTH_METRIC instance.
 * @param month An integer representing the month to be set.
 */
void set_month(MONTH_METRIC month_metric, int month);

/**
 * @brief Looks up a daily METRIC for a specific day in the MONTH_METRIC.
 *
 * This function retrieves the METRIC associated with a specified day from the MONTH_METRIC.
 *
 * @param month_metric The MONTH_METRIC instance.
 * @param day An integer representing the day of the month for which the METRIC is requested.
 *
 * @return The METRIC associated with the specified day, or NULL if not found.
 */
METRIC lookup_metric(MONTH_METRIC month_metric, int day);

/**
 * @brief Frees the memory allocated for the MONTH_METRIC and its contents.
 *
 * This function releases all the memory allocated for the MONTH_METRIC and its associated METRICs.
 * It should be called when the MONTH_METRIC is no longer needed to avoid memory leaks.
 *
 * @param month_metric The MONTH_METRIC to be freed.
 */
void free_month_metrics(MONTH_METRIC month_metric);

/**
 * @brief Retrieves the size of the unique users list in a MONTH_METRIC.
 *
 * This function returns the size of the unique users list recorded in the provided MONTH_METRIC.
 *
 * @param month_metric The MONTH_METRIC instance.
 *
 * @return An integer representing the size of the unique users list.
 */
int get_month_unique_users_size(MONTH_METRIC month_metric);

/**
 * @brief Sets the unique users list in a MONTH_METRIC.
 *
 * This function sets the unique users list in the provided MONTH_METRIC.
 *
 * @param month_metric The MONTH_METRIC instance.
 * @param id The ID of the unique user to be added to the list.
 */
void set_month_unique_users(MONTH_METRIC month_metric, char *id);

#endif