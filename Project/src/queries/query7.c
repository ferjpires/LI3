#include "queries/query7.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "catalogs/flights_catalog.h"
#include "catalogs/airports_catalog.h"
#include "entities/flight.h"
#include "data_manager/flight_stats.h"
#include "entities/airport.h"

//                                          Execution of query seven
//===================================================================================================================
void exec_query_seven(FLIGHTS_CATALOG flights_catalog, AIRPORTS_CATALOG airports_catalog,
                      char *args, FILE *output, int flag)
{
    int limit = atoi(args);

    GArray *list = g_array_new(FALSE, FALSE, sizeof(AIRPORT));

    iterate_airports(airports_catalog, add_airport_to_list2, list);

    g_array_sort(list, sort_airport_list_by_median);

    if (flag == 1)
    {
        for (int i = 0; i < limit && i < list->len; i++)
        {
            AIRPORT airport = g_array_index(list, AIRPORT, i);
            char *name = get_airport_name(airport);
            double median = get_airport_median(airport);

            fprintf(output, "--- %d ---\n", i + 1);
            fprintf(output, "name: %s\n", name);
            free(name);
            if (i == list->len - 1 || i == limit - 1)
                fprintf(output, "median: %.f\n", median);
            else
                fprintf(output, "median: %.f\n\n", median);
        }
    }
    else
    {
        for (int i = 0; i < limit && i < list->len; i++)
        {
            AIRPORT airport = g_array_index(list, AIRPORT, i);
            char *name = get_airport_name(airport);
            double median = get_airport_median(airport);

            fprintf(output, "%s;%.f\n", name, median);

            free(name);
        }
    }

    g_array_free(list, TRUE);
}

void add_airport_to_list2(AIRPORT airport, void *user_data)
{
    GArray *list = user_data;
    GArray *delay_list = get_airport_delay_list(airport);
    if (delay_list->len > 0)
        g_array_append_val(list, airport);
    g_array_free(delay_list, TRUE);
}

gint sort_airport_list_by_median(gconstpointer a, gconstpointer b)
{

    AIRPORT airport_a = *(AIRPORT *)a;
    AIRPORT airport_b = *(AIRPORT *)b;

    double airport_a_median = get_airport_median(airport_a);
    double airport_b_median = get_airport_median(airport_b);
    char *airport_a_name = get_airport_name(airport_a);
    char *airport_b_name = get_airport_name(airport_b);

    gint compare;

    if (airport_b_median > airport_a_median)
        compare = 1;
    else if (airport_b_median < airport_a_median)
        compare = -1;
    else
        compare = g_strcmp0(airport_a_name, airport_b_name);

    free(airport_a_name);
    free(airport_b_name);

    return compare;
}
