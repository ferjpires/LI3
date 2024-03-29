#ifndef TEST_QUERY_MANAGER_H
#define TEST_QUERY_MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "utils/output.h"
#include "utils/test_validation.h"

#include "queries/query_manager.h"
#include "tests/test_struct/tests.h"
#include "tests/test_struct/query.h"

/**
 * @brief Processes a line of input for testing purposes.
 *
 * This function reads a line from the input, interprets it as a test query, and evaluates
 * the expected result against the actual result. The test results are then recorded and
 * analyzed to assess the correctness of the implemented functionality.
 *
 * @param line The string representing the input line.
 * @param input_line The line number in the input file (for error reporting) of type 'int'.
 * @param users_catalog The catalog containing users' information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog containing flights' information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog containing reservations' information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The catalog containing airports' information of type 'AIRPORTS_CATALOG'.
 * @param hotels_catalog The catalog containing hotels' information of type 'HOTELS_CATALOG'.
 * @param expected_outputs The directory with the expected outputs of the queries of type 'char*'.
 * @param tests The TEST structure to record and analyze test results.
 * @param metrics The catalog for recording and analyzing metrics data.
 */
void test_process_line(char *line, int input_line, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog,
                       RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog,
                       HOTELS_CATALOG hotels_catalog, char *expected_outputs, TEST tests, METRICS_CATALOG metrics);

/**
 * @brief Reads and processes each line of the queries file for testing.
 *
 * This function reads each line from the specified queries file, processes the test queries,
 * and evaluates the expected results against the actual results. The test results are then
 * recorded and analyzed to assess the correctness of the implemented functionality.
 *
 * @param users_catalog The catalog containing users' information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog containing flights' information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog containing reservations' information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The catalog containing airports' information of type 'AIRPORTS_CATALOG'.
 * @param hotels_catalog The catalog containing hotels' information of type 'HOTELS_CATALOG'.
 * @param queries_file The input file given by the user with queries of type 'FILE'.
 * @param expected_outputs The directory with the expected outputs of the queries of type 'char*'.
 * @param tests The TEST structure to record and analyze test results.
 * @param metrics The catalog for recording and analyzing metrics data.
 */
void test_read_file(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                    AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file,
                    char *expected_outputs, TEST tests, METRICS_CATALOG metrics);

/**
 * @brief Manages the execution of test queries and records the results.
 *
 * This function manages the execution of test queries, compares the actual results against
 * the expected results, and records the test results for later analysis. It utilizes other
 * test-related functions to achieve this.
 *
 * @param users_catalog The catalog containing users' information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog containing flights' information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog containing reservations' information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The catalog containing airports' information of type 'AIRPORTS_CATALOG'.
 * @param hotels_catalog The catalog containing hotels' information of type 'HOTELS_CATALOG'.
 * @param queries_file The input file given by the user with queries of type 'FILE'.
 * @param expected_outputs The directory with the expected outputs of the queries of type 'char*'.
 * @param tests The TEST structure to record and analyze test results.
 * @param metrics The catalog for recording and analyzing metrics data.
 */
void test_query_manager(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                        AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file,
                        char *expected_outputs, TEST tests, METRICS_CATALOG metrics);

#endif