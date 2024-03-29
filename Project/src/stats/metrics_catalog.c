#include "stats/metrics_catalog.h"

#include "stats/year_metric.h"

struct metrics_catalog
{
    GHashTable *metrics;
};

//                                               Create Metrics Catalog
// ===================================================================================================================

METRICS_CATALOG create_metrics_catalog()
{
    METRICS_CATALOG new_catalog = malloc(sizeof(struct metrics_catalog));
    new_catalog->metrics = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)free_year_metrics);
    return new_catalog;
}

//                                               Build a Metric
// ===================================================================================================================

void build_metric(METRICS_CATALOG catalog, char *year)
{
    YEAR_METRIC year_metric = create_year_metric();
    set_yearly_existence(year_metric);

    insert_metric(catalog, year_metric, year);
}

//                                               Insert a metric
// ===================================================================================================================

void insert_metric(METRICS_CATALOG catalog, YEAR_METRIC year_metric, gpointer key)
{
    char *id_dup = g_strdup(key);
    g_hash_table_insert(catalog->metrics, id_dup, GINT_TO_POINTER(year_metric));
}

//                                               Lookup Metric
// ===================================================================================================================

YEAR_METRIC lookup_year_metric(METRICS_CATALOG catalog, char *year)
{
    return g_hash_table_lookup(catalog->metrics, year);
}

//                                               Destroy Catalog
// ===================================================================================================================

void free_metrics_catalog(METRICS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->metrics);
    free(catalog);
}