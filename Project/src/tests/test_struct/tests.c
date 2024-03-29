#include "tests/test_struct/tests.h"

#define MAX_QUERIES 10

struct test
{
    double parser_time;
    double queries_time;
    double total_time;
    QUERY queries[MAX_QUERIES];
};

//                                               Create Tests
// ===================================================================================================================
TEST create_test()
{

    TEST new_test = malloc(sizeof(struct test));
    
    for (int i = 0; i < MAX_QUERIES; i++)
    {
        new_test->queries[i] = create_query();
    }
    
    return new_test;
}

//                                               Parser Time
// ===================================================================================================================

double get_parser_time(TEST test)
{
    return test->parser_time;
}

void set_parser_time(TEST test, double time)
{
    test->parser_time = time;
}

//                                               Queries Time
// ===================================================================================================================

double get_queries_time(TEST test)
{
    return test->queries_time;
}

void set_queries_time(TEST test, double time)
{
    test->queries_time = time;
}

//                                               Total Time
// ===================================================================================================================

double get_total_time(TEST test)
{
    return test->total_time;
}

void set_total_time(TEST test, double time)
{
    test->total_time = time;
}

//                                               Lookup a query
// ===================================================================================================================

QUERY lookup_query(TEST test, int query_number)
{
    if (query_number < 1 || query_number > MAX_QUERIES) return NULL;
    QUERY found_query = test->queries[query_number - 1];
    return found_query;
}

//                                               Destroy test
// ===================================================================================================================

void free_tests(TEST test)
{
    for (int i = 0; i < MAX_QUERIES; i++)
    {
        query_destroy_function(test->queries[i]);
    }
    
    free(test);
}
