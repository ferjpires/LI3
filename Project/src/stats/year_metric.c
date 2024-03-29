#include "stats/year_metric.h"

#include "stats/month_metric.h"

#define MAX_MONTHS 12

struct year_metric{
    bool exists;
    MONTH_METRIC monthly_metric[MAX_MONTHS];
    GHashTable *unique_users;
};

//                                               Create year metrics
// ===================================================================================================================

YEAR_METRIC create_year_metric()
{
    YEAR_METRIC new_year_metric = malloc(sizeof(struct year_metric));

    new_year_metric->exists = false;

    for (int i = 0; i < MAX_MONTHS; i++)
        new_year_metric->monthly_metric[i] = create_month_metric();
    
    new_year_metric->unique_users = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);

    return new_year_metric;
}

//                                               Exists
// ===================================================================================================================

bool get_yearly_existence(YEAR_METRIC year_metric)
{
    return year_metric->exists;
}

void set_yearly_existence(YEAR_METRIC year_metric)
{
    year_metric->exists = true;
}

//                                               Lookup a month metric
// ===================================================================================================================

MONTH_METRIC lookup_month_metric(YEAR_METRIC year_metric, int month)
{
    if (month < 1 || month > MAX_MONTHS)
        return NULL;

    MONTH_METRIC found_metric = year_metric->monthly_metric[month - 1];

    return found_metric;
}

//                                               Destroy month metric
// ===================================================================================================================

void free_year_metrics(YEAR_METRIC year_metric)
{
    for (int i = 0; i < MAX_MONTHS; i++)
        free_month_metrics(year_metric->monthly_metric[i]);
    g_hash_table_destroy(year_metric->unique_users);

    free(year_metric);
}

//                                               Unique users
// ===================================================================================================================

int get_year_unique_users_size(YEAR_METRIC year_metric)
{
    return g_hash_table_size(year_metric->unique_users);
}

void set_year_unique_users(YEAR_METRIC year_metric, char *id)
{
    if (!g_hash_table_contains(year_metric->unique_users, id))
    {
        char *id_dup = strdup(id);
        g_hash_table_insert(year_metric->unique_users, id_dup, GINT_TO_POINTER(1));
    }
}
