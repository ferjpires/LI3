#include "queries/query6.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entities/flight.h"
#include "entities/airport.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/airports_catalog.h"

void exec_query_six(AIRPORTS_CATALOG airports_catalog, char *arguments, FILE *output, int flag)
{
    char *token;
    token = strsep(&arguments, " ");
    char *year = token;
    token = strsep(&arguments, " ");
    int val = atoi(token);

    GArray *airports = g_array_new(FALSE, FALSE, sizeof(AIRPORT));

    iterate_airports(airports_catalog, add_airport_to_list3, airports);

    g_array_sort_with_data(airports, sort_airport_list_by_passengers, year);

    if (flag == 1)
    {
        for (int i = 0; i < val && i < airports->len; i++)
        {
            AIRPORT airport = g_array_index(airports, AIRPORT, i);
            char *name = get_airport_name(airport);
            int passengers = get_airport_yearly_passengers(airport, year);

            fprintf(output, "--- %d ---\n", i + 1);
            fprintf(output, "name: %s\n", name);
            free(name);
            if (i == airports->len - 1 || i == val - 1)
                fprintf(output, "passengers: %d\n", passengers);
            else
                fprintf(output, "passengers: %d\n\n", passengers);
        }
    }
    else
    {
        for (int i = 0; i < val && i < airports->len; i++)
        {
            AIRPORT airport = g_array_index(airports, AIRPORT, i);
            char *name = get_airport_name(airport);
            int passengers = get_airport_yearly_passengers(airport, year);

            fprintf(output, "%s;%d\n", name, passengers);

            free(name);
        }
    }

    g_array_free(airports, TRUE);
}

void add_airport_to_list3(AIRPORT airport, void *user_data)
{
    GArray *list = user_data;
    g_array_append_val(list, airport);
}

gint sort_airport_list_by_passengers(gconstpointer a, gconstpointer b, gpointer user_data)
{
    AIRPORT airport_a = *(AIRPORT *)a;
    AIRPORT airport_b = *(AIRPORT *)b;
    char *year = (char*)user_data;

    int airport_a_passengers = get_airport_yearly_passengers(airport_a, year);
    int airport_b_passengers = get_airport_yearly_passengers(airport_b, year);

    char *airport_a_name = get_airport_name(airport_a);
    char *airport_b_name = get_airport_name(airport_b);

    gint compare;

    if (airport_b_passengers > airport_a_passengers)
        compare = 1;
    else if (airport_b_passengers < airport_a_passengers)
        compare = -1;
    else
        compare = strcmp(airport_a_name, airport_b_name);

    free(airport_a_name);
    free(airport_b_name);

    return compare;
}
