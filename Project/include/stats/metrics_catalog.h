#ifndef METRICS_CATALOG_H
#define METRICS_CATALOG_H

#include <stdbool.h>
#include "stats/year_metric.h"

typedef struct metrics_catalog *METRICS_CATALOG;

/**
 * @brief Creates a new metrics catalog.
 *
 * This function allocates memory for a new metrics catalog and initializes its
 * internal data structures. The created catalog is empty initially.
 *
 * @return A pointer to the newly created metrics catalog.
 */
METRICS_CATALOG create_metrics_catalog();

/**
 * @brief Builds a metric for the specified year in the catalog.
 *
 * This function creates and initializes a new YEAR_METRIC for the specified year
 * within the metrics catalog. If a metric for the given year already exists, this
 * function rebuilds it.
 *
 * @param catalog The metrics catalog where the metric will be built.
 * @param year A string representing the year for which the metric will be built.
 */
void build_metric(METRICS_CATALOG catalog, char *year);

/**
 * @brief Inserts a YEAR_METRIC into the metrics catalog.
 *
 * This function inserts a YEAR_METRIC into the metrics catalog, associating it with
 * a given key. The key is typically the year for which the metric is relevant.
 *
 * @param catalog The metrics catalog where the metric will be inserted.
 * @param year_metric The YEAR_METRIC to be inserted.
 * @param key A pointer to a key associated with the metric (e.g., a year string).
 */
void insert_metric(METRICS_CATALOG catalog, YEAR_METRIC year_metric, gpointer key);

/**
 * @brief Looks up a YEAR_METRIC for a specific year in the metrics catalog.
 *
 * This function retrieves the YEAR_METRIC associated with a specified year from
 * the metrics catalog.
 *
 * @param catalog The metrics catalog to search for the YEAR_METRIC.
 * @param year A string representing the year for which the metric is requested.
 *
 * @return The YEAR_METRIC associated with the specified year, or NULL if not found.
 */
YEAR_METRIC lookup_year_metric(METRICS_CATALOG catalog, char *year);

/**
 * @brief Frees the memory allocated for the metrics catalog and its contents.
 *
 * This function releases all the memory allocated for the metrics catalog and
 * its associated metrics. It should be called when the catalog is no longer needed
 * to avoid memory leaks.
 *
 * @param catalog The metrics catalog to be freed.
 */
void free_metrics_catalog(METRICS_CATALOG catalog);

#endif