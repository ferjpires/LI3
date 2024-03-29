#ifndef QUERY10_H
#define QUERY10_H

#include <stdio.h>
#include "stats/metrics_catalog.h"

/**
 * @brief Function used to execute query 10.
 *
 * This function executes query 10 based on the provided metrics catalog and arguments. It writes the results to the
 * output file, utilizing an additional flag for query-specific formatting.
 *
 * @param metrics - The metrics catalog containing performance metrics (type: METRICS_CATALOG).
 * @param args - The arguments provided to the function (type: char*).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void exec_query_ten(METRICS_CATALOG metrics, char *args, FILE *output, int flag);

/**
 * @brief Writes metrics information to the output file.
 *
 * This function writes the metrics information stored in the metrics catalog to the output file. It utilizes an
 * additional flag for query-specific formatting.
 *
 * @param metrics - The metrics catalog containing performance metrics (type: METRICS_CATALOG).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void _write_metrics(METRICS_CATALOG metrics, FILE *output, int flag);

/**
 * @brief Writes year-based metrics information to the output file.
 *
 * This function writes the year-based metrics information stored in the metrics catalog to the output file. It utilizes
 * an additional flag for query-specific formatting.
 *
 * @param year_metric - The year-based metrics information (type: YEAR_METRIC).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void _write_year_metrics(YEAR_METRIC year_metric, FILE *output, int flag);

/**
 * @brief Writes month-based metrics information to the output file.
 *
 * This function writes the month-based metrics information stored in the metrics catalog to the output file. It utilizes
 * an additional flag for query-specific formatting.
 *
 * @param month_metric - The month-based metrics information (type: MONTH_METRIC).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void _write_month_metrics(MONTH_METRIC month_metric, FILE *output, int flag);

/**
 * @brief Fixes the unique passengers array by removing duplicate entries.
 *
 * This function takes two GArrays, one containing unique passengers and the other containing all passengers. It modifies
 * the unique passengers array by removing duplicate entries found in the all passengers array.
 *
 * @param unique - The GArray containing unique passengers (type: GArray*).
 * @param passengers - The GArray containing all passengers (type: GArray*).
 */
void fix_unique_passengers(GArray *unique, GArray *passengers);

#endif