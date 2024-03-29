#include "program/batch_mode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#include "queries/query_manager.h"
#include "data_manager/parser.h"
#include "entities/user.h"
#include "entities/flight.h"
#include "entities/reservation.h"
#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "stats/metrics_catalog.h"
#include "utils/utils.h"

void exec_batch_mode(char *path, char *commands, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog,
                     RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog,
                     METRICS_CATALOG metrics)
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

    parser(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog,
           users_csv, flights_csv, reservations_csv, passengers_csv, metrics);

    finit = clock();
    time = ((double)(finit - init)) / CLOCKS_PER_SEC;
    printf("CPU time used parser: %f seconds\n", time);

    init = clock();

    query_manager(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, queries, metrics);

    finit = clock();
    time = ((double)(finit - init)) / CLOCKS_PER_SEC;
    printf("CPU time used queries: %f seconds\n", time);

    fclose(users_csv);
    fclose(flights_csv);
    fclose(passengers_csv);
    fclose(reservations_csv);
    fclose(queries);
}
