#include "tests/test_manager.h"

void test_manager(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                  AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, char *path, char *commands, char *outputs,
                  TEST tests, METRICS_CATALOG metrics)
{
    FILE *users_csv = open_csv(path, "users.csv");
    if (users_csv == NULL)
        perror("Error opening file: users.csv");

    FILE *flights_csv = open_csv(path, "flights.csv");
    if (flights_csv == NULL)
        perror("Error opening file: flights.csv");

    FILE *passengers_csv = open_csv(path, "passengers.csv");
    if (passengers_csv == NULL)
        perror("Error opening file: passengers.csv");

    FILE *reservations_csv = open_csv(path, "reservations.csv");
    if (reservations_csv == NULL)
        perror("Error opening file: reservations.csv");

    FILE *queries = fopen(commands, "r");
    if (queries == NULL)
        perror("Error opening file: queries.csv");

    clock_t init, finit;
    double time;
    init = clock();

    parser(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, users_csv, flights_csv, reservations_csv, passengers_csv, metrics);

    finit = clock();
    time = ((double)(finit - init)) / CLOCKS_PER_SEC;
    set_parser_time(tests, time);

    init = clock();

    test_query_manager(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, queries, outputs, tests, metrics);

    finit = clock();
    time = ((double)(finit - init)) / CLOCKS_PER_SEC;
    set_queries_time(tests, time);

    // Free the files
    fclose(users_csv);
    fclose(flights_csv);
    fclose(passengers_csv);
    fclose(reservations_csv);
    fclose(queries);
}
