#include "tests/test_struct/query.h"

struct query
{
    double time;
    int number_of_queries;
    int total_correct_queries;
    GArray *failed_queries;
};

//                                               Create a query
// ===================================================================================================================

QUERY create_query(void)
{
    QUERY new_query = malloc(sizeof(struct query));

    new_query->time = 0.0;
    new_query->number_of_queries = 0;
    new_query->total_correct_queries = 0;
    new_query->failed_queries = g_array_new(FALSE, FALSE, sizeof(int));

    return new_query;
}

//                                               Time
// ===================================================================================================================

double get_query_time(QUERY query)
{
    return query->time;
}

void set_query_time(QUERY query, double time)
{
    query->time += time;
}

//                                               Number of queries
// ===================================================================================================================

int get_query_number_of_queries(QUERY query)
{
    return query->number_of_queries;
}

void set_query_number_of_queries(QUERY query, int number_of_queries)
{
    query->number_of_queries += number_of_queries;
}

//                                               Total correct queries
// ===================================================================================================================

int get_query_total_correct_queries(QUERY query)
{
    return query->total_correct_queries;
}

void set_query_total_correct_queries(QUERY query, int total_correct_queries)
{
    query->total_correct_queries += total_correct_queries;
}

//                                               Failed queries
// ===================================================================================================================

GArray *get_query_failed_queries(QUERY query)
{
    return g_array_copy(query->failed_queries);
}

void set_query_failed_queries(QUERY query, int failed_query, int line_failed)
{
    g_array_append_val(query->failed_queries, failed_query);
    g_array_append_val(query->failed_queries, line_failed);
}

//                                               Free query
// ===================================================================================================================

void query_destroy_function(gpointer data)
{
    QUERY query = (QUERY)data;

    g_array_free(query->failed_queries, TRUE);

    free(query);
}
