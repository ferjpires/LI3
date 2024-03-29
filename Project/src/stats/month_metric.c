#include "stats/month_metric.h"

#include "stats/metric.h"

#define MAX_DAYS 31

struct month_metric
{
    bool exists;
    int month;
    METRIC daily_metric[MAX_DAYS];
    GHashTable *unique_users;
};

//                                               Create month metrics
// ===================================================================================================================

MONTH_METRIC create_month_metric()
{
    MONTH_METRIC new_month_metric = malloc(sizeof(struct month_metric));

    new_month_metric->exists = false;
    new_month_metric->month = 0;

    for (int i = 0; i < MAX_DAYS; i++)
        new_month_metric->daily_metric[i] = create_metric();

    new_month_metric->unique_users = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);

    return new_month_metric;
}

//                                               Exists
// ===================================================================================================================

bool get_monthly_existence(MONTH_METRIC month_metric)
{
    return month_metric ->exists;
}

void set_monthly_existence(MONTH_METRIC month_metric)
{
    month_metric->exists = true;
}

//                                               Month
// ===================================================================================================================

int get_month(MONTH_METRIC month_metric)
{
    return month_metric->month;
}

void set_month(MONTH_METRIC month_metric, int month)
{
    month_metric->month = month;
}

//                                               Lookup a metric
// ===================================================================================================================

METRIC lookup_metric(MONTH_METRIC month_metric, int day)
{
    if (day < 1 || day > MAX_DAYS)
        return NULL;

    METRIC found_metric = month_metric->daily_metric[day - 1];

    return found_metric;
}

//                                               Destroy month metric
// ===================================================================================================================

void free_month_metrics(MONTH_METRIC month_metric)
{
    for (int i = 0; i < MAX_DAYS; i++)
        metric_destroy_function(month_metric->daily_metric[i]);
    g_hash_table_destroy(month_metric->unique_users);

    free(month_metric);
}

//                                               Unique users
// ===================================================================================================================

int get_month_unique_users_size(MONTH_METRIC month_metric)
{
    return g_hash_table_size(month_metric->unique_users);
}

void set_month_unique_users(MONTH_METRIC month_metric, char *id)
{
    if (!g_hash_table_contains(month_metric->unique_users, id))
    {
        char *id_dup = strdup(id);
        g_hash_table_insert(month_metric->unique_users, id_dup, GINT_TO_POINTER(1));
    }
}
