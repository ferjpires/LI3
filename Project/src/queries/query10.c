#include "queries/query10.h"

#include <stdio.h>
#include <stdbool.h>
#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "stats/metrics_catalog.h"

#define AVIATION_START 1903
#define CURRENT_YEAR 2023

void fix_unique_passengers(GArray *unique, GArray *passengers)
{
    // Iterar sobre o segundo array
    for (int i = 0; i < passengers->len; i++)
    {
        // Verificar se a string já está no conjunto
        int jaNoConjunto = 0;
        for (int j = 0; j < unique->len; j++)
        {
            char *id_a = g_array_index(unique, char *, j);
            char *id_b = g_array_index(passengers, char *, i);

            if (strcmp(id_a, id_b) == 0)
            {
                jaNoConjunto = 1;
                break;
            }
        }

        // Se não estiver no conjunto, adicionar e incrementar o contador
        if (!jaNoConjunto)
        {
            char *user_to_add = g_array_index(passengers, char *, i);
            g_array_append_val(unique, user_to_add);
        }
    }
}

void _write_month_metrics(MONTH_METRIC month_metric, FILE *output, int flag)
{
    int printed = 1, total_users, total_flights, total_reservations, total_passengers, total_unique_passengers = 0;
    bool exists = false;
    bool is_first = true;
    for (int i = 1; i < 31; i++)
    {
        METRIC day_metric = lookup_metric(month_metric, i);
        exists = get_daily_existence(day_metric);
        if (!exists)
            continue;

        total_users = get_total_users(day_metric);
        total_flights = get_total_flights(day_metric);
        total_reservations = get_total_reservations(day_metric);
        total_passengers = get_total_passengers(day_metric);

        total_unique_passengers = get_unique_users_size(day_metric);

        if (flag)
        {
            if (is_first)
            {
                fprintf(output, "--- %d ---\nday: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n",
                        printed,
                        i,
                        total_users,
                        total_flights,
                        total_passengers,
                        total_unique_passengers,
                        total_reservations);
                is_first = false;
            }
            else
            {
                fprintf(output, "\n--- %d ---\nday: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n",
                        printed,
                        i,
                        total_users,
                        total_flights,
                        total_passengers,
                        total_unique_passengers,
                        total_reservations);
            }
            printed++;
        }
        else
        {
            fprintf(output, "%d;%d;%d;%d;%d;%d\n",
                    i,
                    total_users,
                    total_flights,
                    total_passengers,
                    total_unique_passengers,
                    total_reservations);
        }
    }
}

void _write_year_metrics(YEAR_METRIC year_metric, FILE *output, int flag)
{
    int printed = 1, total_users, total_flights, total_reservations, total_passengers, total_unique_passengers = 0;
    bool exists = false;
    bool is_first = true;
    int i, j;
    for (i = 1; i < 13; i++)
    {
        exists = false;
        total_users = 0;
        total_flights = 0;
        total_reservations = 0;
        total_passengers = 0;
        total_unique_passengers = 0;

        MONTH_METRIC month_metric = lookup_month_metric(year_metric, i);
        exists = get_monthly_existence(month_metric);
        if (!exists)
            continue;

        for (j = 1; j < 32; j++)
        {
            METRIC day_metric = lookup_metric(month_metric, j);
            exists = get_daily_existence(day_metric);
            if (!exists)
                continue;
            total_users += get_total_users(day_metric);
            total_flights += get_total_flights(day_metric);
            total_reservations += get_total_reservations(day_metric);
            total_passengers += get_total_passengers(day_metric);
        }

        total_unique_passengers = get_month_unique_users_size(month_metric);

        if (flag)
        {
            if (is_first)
            {
                fprintf(output, "--- %d ---\nmonth: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n",
                        printed,
                        i,
                        total_users,
                        total_flights,
                        total_passengers,
                        total_unique_passengers,
                        total_reservations);
                is_first = false;
            }
            else
            {
                fprintf(output, "\n--- %d ---\nmonth: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n",
                        printed,
                        i,
                        total_users,
                        total_flights,
                        total_passengers,
                        total_unique_passengers,
                        total_reservations);
            }
            printed++;
        }
        else
        {
            fprintf(output, "%d;%d;%d;%d;%d;%d\n",
                    i,
                    total_users,
                    total_flights,
                    total_passengers,
                    total_unique_passengers,
                    total_reservations);
        }
    }
}

void _write_metrics(METRICS_CATALOG metrics, FILE *output, int flag)
{
    int printed = 1, total_users, total_flights, total_reservations, total_passengers, total_unique_passengers = 0;
    bool exists = false;
    bool is_first = true;
    int i, j, k;
    char yearString[5];

    for (i = AVIATION_START; i <= CURRENT_YEAR; i++)
    {
        exists = false;
        total_users = 0;
        total_flights = 0;
        total_reservations = 0;
        total_passengers = 0;
        total_unique_passengers = 0;
        sprintf(yearString, "%d", i);
        YEAR_METRIC year_metric = lookup_year_metric(metrics, yearString);
        if (year_metric == NULL)
            continue;

        for (j = 1; j < 13; j++)
        {
            MONTH_METRIC month_metric = lookup_month_metric(year_metric, j);
            exists = get_monthly_existence(month_metric);
            if (!exists)
                continue;

            for (k = 1; k < 32; k++)
            {
                METRIC day_metric = lookup_metric(month_metric, k);
                exists = get_daily_existence(day_metric);
                if (!exists)
                    continue;
                total_users += get_total_users(day_metric);
                total_flights += get_total_flights(day_metric);
                total_reservations += get_total_reservations(day_metric);
                total_passengers += get_total_passengers(day_metric);
            }
        }

        total_unique_passengers = get_year_unique_users_size(year_metric);

        if (flag)
        {
            if (is_first)
            {
                fprintf(output, "--- %d ---\nyear: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n",
                        printed,
                        i,
                        total_users,
                        total_flights,
                        total_passengers,
                        total_unique_passengers,
                        total_reservations);
                is_first = false;
            }
            else
            {
                fprintf(output, "\n--- %d ---\nyear: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n",
                        printed,
                        i,
                        total_users,
                        total_flights,
                        total_passengers,
                        total_unique_passengers,
                        total_reservations);
            }
            printed++;
        }
        else
        {
            fprintf(output, "%d;%d;%d;%d;%d;%d\n",
                    i,
                    total_users,
                    total_flights,
                    total_passengers,
                    total_unique_passengers,
                    total_reservations);
        }
    }
}

void exec_query_ten(METRICS_CATALOG metrics, char *args, FILE *output, int flag)
{
    char *yearString, *monthString;
    int year = 0, month = 0;

    if (args)
    {
        yearString = strsep(&args, " ");
        year = atoi(yearString);
        if (args)
        {
            monthString = strsep(&args, " ");
            month = atoi(monthString);
        }
    }

    if (year != 0)
    {
        if (month != 0)
        {
            YEAR_METRIC year_metric = lookup_year_metric(metrics, yearString);
            MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
            _write_month_metrics(month_metric, output, flag);
        }
        else
        {
            YEAR_METRIC year_metric = lookup_year_metric(metrics, yearString);
            _write_year_metrics(year_metric, output, flag);
        }
    }
    else
    {
        _write_metrics(metrics, output, flag);
    }
}
