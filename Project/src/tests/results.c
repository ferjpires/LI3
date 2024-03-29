#include "tests/results.h"

#define MAX_QUERIES 10

void write_results(TEST tests)
{
    double average_time = 0.0;
    double correct_percentage = 0.0;
    double found_time = 0.0;
    int number_of_queries = 0;
    int total_correct_queries = 0;

    for (int i = 1; i <= MAX_QUERIES; i++)
    {
        QUERY found_query = lookup_query(tests, i);

        GArray *failed_queries = get_query_failed_queries(found_query);
        number_of_queries = get_query_number_of_queries(found_query);
        total_correct_queries = get_query_total_correct_queries(found_query);
        found_time = get_query_time(found_query);

        average_time = found_time / number_of_queries;
        correct_percentage = (total_correct_queries / number_of_queries) * 100;

        printf("\033[0;35m[Query%d Analysis]\033[0m\n", i);
        printf("\033[0;34mTotal Time: %f seconds\033[0m\n", found_time);
        printf("\033[0;34mAverage Time Per Query: %f seconds\033[0m\n", average_time);
        printf("\033[0;34mPercentage of Correct Queries: %f%% // %d/%d\033[0m\n\n", correct_percentage, total_correct_queries, number_of_queries);

        if (total_correct_queries != number_of_queries)
        {
            for (int i = 0; i < failed_queries->len; i = i + 2)
            {
                int missing_query = g_array_index(failed_queries, int, i);
                int missing_line = g_array_index(failed_queries, int, i + 1);

                printf("\033[0;41m[TEST INVALID] Input: %d\033[0m\n", missing_query);
                if (missing_line == -1)
                    printf("\t\033[0;31m[Different File Size]\033[0m\n");
                else
                    printf("\t\033[0;41mError in Line: %d\033[0m\n", missing_line);
            }
        }
        printf("\n");
        g_array_free(failed_queries, TRUE);
    }
}