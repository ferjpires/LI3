#include "stats/metric_manager.h"
#include "stats/metrics_catalog.h"
#include "catalogs/users_catalog.h"
#include "entities/user.h"

void flight_metrics(METRICS_CATALOG metrics, char *date)
{
    char *date_copy = strdup(date);
    char *year = strsep(&date_copy, "/");
    char *monthString = strsep(&date_copy, "/");
    char *dayString = strsep(&date_copy, "/");
    int month = atoi(monthString);
    int day = atoi(dayString);

    if (lookup_year_metric(metrics, year) == NULL)
    {
        build_metric(metrics, year);
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_flights(day_metric);
    }
    else
    {
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_flights(day_metric);
    }

    free(date_copy);
    free(year);
}

void user_metrics(METRICS_CATALOG metrics, char *date)
{
    char *date_copy = strdup(date);
    char *year = strsep(&date_copy, "/");
    char *monthString = strsep(&date_copy, "/");
    char *dayString = strsep(&date_copy, "/");
    int month = atoi(monthString);
    int day = atoi(dayString);

    if (lookup_year_metric(metrics, year) == NULL)
    {
        build_metric(metrics, year);
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_users(day_metric);
    }
    else
    {
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_users(day_metric);
    }

    free(date_copy);
    free(year);
}

void reservation_metrics(METRICS_CATALOG metrics, char *date)
{
    char *date_copy = strdup(date);
    char *year = strsep(&date_copy, "/");
    char *monthString = strsep(&date_copy, "/");
    char *dayString = strsep(&date_copy, "/");
    int month = atoi(monthString);
    int day = atoi(dayString);

    if (lookup_year_metric(metrics, year) == NULL)
    {
        build_metric(metrics, year);
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_reservations(day_metric);
    }
    else
    {
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_reservations(day_metric);
    }

    free(date_copy);
    free(year);
}

void passenger_metrics(METRICS_CATALOG metrics, char *date, USER user)
{
    char *date_copy = strdup(date);
    char *year = strsep(&date_copy, "/");
    char *monthString = strsep(&date_copy, "/");
    char *dayString = strsep(&date_copy, "/");
    int month = atoi(monthString);
    int day = atoi(dayString);

    if (lookup_year_metric(metrics, year) == NULL)
    {
        build_metric(metrics, year);
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_passengers(day_metric);
        char *user_id = get_user_id(user);
        set_unique_users(day_metric, user_id);
        set_month_unique_users(month_metric, user_id);
        set_year_unique_users(year_metric, user_id);
        free(user_id);
    }
    else
    {
        YEAR_METRIC year_metric = lookup_year_metric(metrics, year);
        MONTH_METRIC month_metric = lookup_month_metric(year_metric, month);
        set_monthly_existence(month_metric);
        set_month(month_metric, month);
        METRIC day_metric = lookup_metric(month_metric, day);
        set_daily_existence(day_metric);
        set_total_passengers(day_metric);
        char *user_id = get_user_id(user);
        set_unique_users(day_metric, user_id);
        set_month_unique_users(month_metric, user_id);
        set_year_unique_users(year_metric, user_id);
        free(user_id);
    }

    free(date_copy);
    free(year);
}

