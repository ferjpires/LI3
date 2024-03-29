#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H

#include <glib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "data_manager/parser.h"
#include "tests/queries/test_query_manager.h"
#include "tests/test_struct/tests.h"
#include "tests/test_struct/query.h"
#include "stats/metrics_catalog.h"
#include "utils/utils.h"

/**
 * @brief Manages the execution of test scenarios.
 *
 * This function serves as the central manager for executing test scenarios. It takes various
 * catalogs (e.g., users, flights, reservations, airports, hotels), input and expected output paths,
 * and performs tests based on the provided commands. The results of each test, including parsing time,
 * query execution time, and overall test duration, are recorded in the TEST structure. Additionally,
 * metrics data is collected and stored in the METRICS_CATALOG for analysis.
 *
 * @param users_catalog The catalog containing users' information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog containing flights' information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog containing reservations' information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The catalog containing airports' information of type 'AIRPORTS_CATALOG'.
 * @param hotels_catalog The catalog containing hotels' information of type 'HOTELS_CATALOG'.
 * @param path The directory path where the input files are located of type 'char*'.
 * @param commands The filename of the input file containing test commands of type 'char*'.
 * @param outputs The directory path where the expected output files are located of type 'char*'.
 * @param tests The TEST structure to record and analyze test results.
 * @param metrics The METRICS_CATALOG for recording and analyzing metrics data.
 */
void test_manager(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog,
                  RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog,
                  HOTELS_CATALOG hotels_catalog, char *path, char *commands, char *outputs,
                  TEST tests, METRICS_CATALOG metrics);

#endif