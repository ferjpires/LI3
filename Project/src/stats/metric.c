#include "stats/metric.h"

#include <stdbool.h>
#include <glib.h>
#include "catalogs/users_catalog.h"

struct metric
{
    bool exists;
    int total_users;
    int total_flights;
    int total_passengers;
    int unique_passengers;
    int total_reservations;
    GHashTable *unique_users;
};

//                                               Create a metric
// ===================================================================================================================

METRIC create_metric(void)
{
    METRIC new_metric = malloc(sizeof(struct metric));

    new_metric->exists = false;
    new_metric->total_users = 0;
    new_metric->total_flights = 0;
    new_metric->total_passengers = 0;
    new_metric->unique_passengers = 0;
    new_metric->total_reservations = 0;
    new_metric->unique_users = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);

    return new_metric;
}

//                                               Free metric
// ===================================================================================================================

void metric_destroy_function(gpointer data)
{
    METRIC metric = (METRIC)data;
    g_hash_table_destroy(metric->unique_users);

    free(metric);
}

//                                               Exists
// ===================================================================================================================

bool get_daily_existence(METRIC metric)
{
    return metric->exists;
}

void set_daily_existence(METRIC metric)
{
    metric->exists = true;
}

//                                               Users
// ===================================================================================================================

int get_total_users(METRIC metric)
{
    return metric->total_users;
}

void set_total_users(METRIC metric)
{
    metric->total_users++;
}

//                                               Flights
// ===================================================================================================================

int get_total_flights(METRIC metric)
{
    return metric->total_flights;
}

void set_total_flights(METRIC metric)
{
    metric->total_flights++;
}

//                                               Passengers
// ===================================================================================================================

int get_total_passengers(METRIC metric)
{
    return metric->total_passengers;
}

void set_total_passengers(METRIC metric)
{
    metric->total_passengers++;
}

//                                               Unique Passengers
// ===================================================================================================================

int get_unique_passengers(METRIC metric)
{
    return metric->unique_passengers;
}

void set_total_unique_passengers(METRIC metric)
{
    metric->unique_passengers++;
}

//                                               Reservations
// ===================================================================================================================

int get_total_reservations(METRIC metric)
{
    return metric->total_reservations;
}

void set_total_reservations(METRIC metric)
{
    metric->total_reservations++;
}

//                                               Unique users
// ===================================================================================================================

int get_unique_users_size(METRIC metric)
{
    return g_hash_table_size(metric->unique_users);
}

void set_unique_users(METRIC metric, char *id)
{
    if (!g_hash_table_contains(metric->unique_users, id))
    {
        char *id_dup = strdup(id);
        g_hash_table_insert(metric->unique_users, id_dup, GINT_TO_POINTER(1));
    }
}