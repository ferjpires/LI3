#include <glib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <sys/resource.h>

#include "tests/test_manager.h"
#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "tests/test_struct/tests.h"
#include "tests/test_struct/query.h"
#include "tests/results.h"
#include "stats/metrics_catalog.h"

int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;

    // Memory and Time usage
    struct rusage r_usage;
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Catalogs
    USERS_CATALOG users_catalog = create_users_catalog();
    FLIGHTS_CATALOG flights_catalog = create_flights_catalog();
    RESERVATIONS_CATALOG reservations_catalog = create_reservations_catalog();
    AIRPORTS_CATALOG airports_catalog = create_airports_catalog();
    HOTELS_CATALOG hotels_catalog = create_hotels_catalog();
    TEST tests = create_test();
    METRICS_CATALOG metrics = create_metrics_catalog();

    // Executing the Tests
    test_manager(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, argv[1], argv[2], argv[3], tests, metrics);

    write_results(tests);

    // Free the catalogs
    free_users_catalog(users_catalog);
    free_flights_catalog(flights_catalog);
    free_reservations_catalog(reservations_catalog);
    free_airports_catalog(airports_catalog);
    free_hotels_catalog(hotels_catalog);
    free_metrics_catalog(metrics);
    

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    set_total_time(tests, cpu_time_used);

    printf("\033[0;32m[TIME INFO]\033[0m\n");
    printf("\033[0;32mParser: %f seconds\033[0m\n", get_parser_time(tests));
    printf("\033[0;32mQueries: %f seconds\033[0m\n", get_queries_time(tests));
    printf("\033[0;32mTotal time: %f seconds\033[0m\n", get_total_time(tests));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("\033[0;32m[MEMORY INFO]\033[0m\n");
    printf("\033[0;32m%ld KB\n", r_usage.ru_maxrss);

    free_tests(tests);

    return 0;
}