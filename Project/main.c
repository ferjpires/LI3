#include <glib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <sys/resource.h>

#include "program/batch_mode.h"
#include "program/menu_mode.h"
#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "stats/metrics_catalog.h"

int main(int argc, char **argv)
{
    struct rusage r_usage;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    if (argc != 1 && argc != 3)
        return 1;

    USERS_CATALOG users_catalog = create_users_catalog();
    FLIGHTS_CATALOG flights_catalog = create_flights_catalog();
    RESERVATIONS_CATALOG reservations_catalog = create_reservations_catalog();
    AIRPORTS_CATALOG airports_catalog = create_airports_catalog();
    HOTELS_CATALOG hotels_catalog = create_hotels_catalog();
    METRICS_CATALOG metrics = create_metrics_catalog();

    if (argc == 1)
        exec_menu_mode(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, metrics);
    else
    {
        if (argc == 3)
            exec_batch_mode(argv[1], argv[2], users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, metrics);
    }

    // Free of all catalogs
    free_users_catalog(users_catalog);
    free_flights_catalog(flights_catalog);
    free_reservations_catalog(reservations_catalog);
    free_airports_catalog(airports_catalog);
    free_hotels_catalog(hotels_catalog);
    free_metrics_catalog(metrics);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %f seconds\n", cpu_time_used);
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);

    return 0;
}