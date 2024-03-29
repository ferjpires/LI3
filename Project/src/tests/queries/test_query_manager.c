#include "tests/queries/test_query_manager.h"

#include "queries/query1.h"
#include "queries/query2.h"
#include "queries/query3.h"
#include "queries/query4.h"
#include "queries/query5.h"
#include "queries/query6.h"
#include "queries/query7.h"
#include "queries/query8.h"
#include "queries/query9.h"
#include "queries/query10.h"
#include "utils/output.h"

void test_process_line(char *line, int input_line, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog,
                       RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, char *expected_outputs, TEST tests, METRICS_CATALOG metrics)
{
    char *query, *args;

    query = strsep(&line, " "); // setting the query todo

    args = (line != NULL) ? line : ""; // setting the arguments of the query

    char *path = create_output_path(input_line); // creating output path

    FILE *output = fopen(path, "w"); // creating output file
    if (output == NULL)              // checking if file correctly opened
        printf("Error opening file: query manager in line %d\n", input_line);

    clock_t start, end;
    double cpu_time_used;

    int query_number = atoi(query);
    QUERY found_query = lookup_query(tests, query_number);

    // knowing which query needs to be executed
    if (strcmp(query, "1") == 0)
    {
        start = clock();
        exec_query_one(users_catalog, flights_catalog, reservations_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "1F") == 0)
    {
        start = clock();
        exec_query_one(users_catalog, flights_catalog, reservations_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "2") == 0)
    {
        start = clock();
        exec_query_two(users_catalog, flights_catalog, reservations_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "2F") == 0)
    {
        start = clock();
        exec_query_two(users_catalog, flights_catalog, reservations_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "3") == 0)
    {
        start = clock();
        exec_query_three(hotels_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "3F") == 0)
    {
        start = clock();
        exec_query_three(hotels_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "4") == 0)
    {
        start = clock();
        exec_query_four(hotels_catalog, reservations_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "4F") == 0)
    {
        start = clock();
        exec_query_four(hotels_catalog, reservations_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "5") == 0)
    {
        start = clock();
        exec_query_five(airports_catalog, flights_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "5F") == 0)
    {
        start = clock();
        exec_query_five(airports_catalog, flights_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "6") == 0)
    {
        start = clock();
        exec_query_six(airports_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "6F") == 0)
    {
        start = clock();
        exec_query_six(airports_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "7") == 0)
    {
        start = clock();
        exec_query_seven(flights_catalog, airports_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "7F") == 0)
    {
        start = clock();
        exec_query_seven(flights_catalog, airports_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "8") == 0)
    {
        start = clock();
        exec_query_eight(hotels_catalog, reservations_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "8F") == 0)
    {
        start = clock();
        exec_query_eight(hotels_catalog, reservations_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "9") == 0)
    {
        start = clock();
        exec_query_nine(users_catalog, args, output, 0);
        end = clock();
    }
    else if (strcmp(query, "9F") == 0)
    {
        start = clock();
        exec_query_nine(users_catalog, args, output, 1);
        end = clock();
    }
    else if (strcmp(query, "10") == 0)
    {
        start = clock();
        exec_query_ten(metrics, args, output, 0);
        end = clock();
    }

    else if (strcmp(query, "10F") == 0)
    {
        start = clock();
        exec_query_ten(metrics, args, output, 1);
        end = clock();
    }

    fclose(output);
    free(path);

    int correct = 1, missing_line = -2, missing_query = 0;

    check_files(expected_outputs, input_line, &correct, &missing_line, &missing_query);

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    set_query_time(found_query, cpu_time_used);
    set_query_number_of_queries(found_query, 1);
    if (correct)
        set_query_total_correct_queries(found_query, 1);
    else
    {
        set_query_failed_queries(found_query, missing_query, missing_line);
    }
}

void test_read_file(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                    AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file, char *expected_outputs, TEST tests, METRICS_CATALOG metrics)
{
    int input_line = 1;
    char line[1024];
    while (fgets(line, sizeof(line), queries_file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        test_process_line(line, input_line, users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, expected_outputs, tests, metrics);
        input_line++;
    }
}

void test_query_manager(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                        AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file, char *expected_outputs, TEST tests, METRICS_CATALOG metrics)
{
    test_read_file(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, queries_file, expected_outputs, tests, metrics);
}
