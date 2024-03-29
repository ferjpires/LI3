#include "utils/utils.h"

#include <glib.h>
#include <stdio.h>
#include "catalogs/reservations_catalog.h"
#include "catalogs/flights_catalog.h"
#include "data_manager/validater.h"

FILE *open_csv(char *path, char *csv)
{
    size_t length = strlen(path) + strlen(csv) + 2;
    char *csv_path = malloc((length) * sizeof(char));
    if (csv_path == NULL)
    {
        printf("Memory allocation failed for file: %s\n", csv);
        return NULL;
    }
    snprintf(csv_path, length, "%s/%s", path, csv);
    FILE *file_csv = fopen(csv_path, "r");
    free(csv_path);

    return file_csv;
}

gint sort_delay_list(gconstpointer a, gconstpointer b)
{
    return (*(int *)a - *(int *)b);
}

// Auxiliar func that compare dates and ids if needed
int date_cmp(char *date_1, char *date_2, char *id_1, char *id_2)
{
    if (g_strcmp0(date_1, date_2) == 0)
        return (g_strcmp0(id_2, id_1));
    else
        return (g_strcmp0(date_1, date_2));
}

gint sort_reservation_list2(gconstpointer a, gconstpointer b, gpointer user_data)
{
    const int *id_reservation_A = (const int *)a;
    const int *id_reservation_B = (const int *)b;
    int int_A = *id_reservation_A;
    int int_B = *id_reservation_B;
    char id_A[16];
    sprintf(id_A, "Book%010d", int_A);
    char id_B[16];
    sprintf(id_B, "Book%010d", int_B);

    RESERVATIONS_CATALOG catalog = (RESERVATIONS_CATALOG)user_data;
    RESERVATION res_A = lookup_reservation(catalog, id_A);
    RESERVATION res_B = lookup_reservation(catalog, id_B);

    char *date_A = get_reservation_begin_date(res_A);
    char *date_B = get_reservation_begin_date(res_B);

    gint compare;

    if (strcmp(date_A, date_B) == 0)
        compare = strcmp(id_A, id_B);
    else
        compare = -(strcmp(date_A, date_B));

    free(date_A);
    free(date_B);

    return compare;
}

gint sort_flight_array_by_dates2(gconstpointer a, gconstpointer b, gpointer user_data)
{
    const int *id_flight_A = (const int *)a;
    const int *id_flight_B = (const int *)b;
    int int_A = *id_flight_A;
    int int_B = *id_flight_B;
    char id_A[11];
    sprintf(id_A, "%010d", int_A);
    char id_B[11];
    sprintf(id_B, "%010d", int_B);

    FLIGHTS_CATALOG catalog = (FLIGHTS_CATALOG)user_data;
    FLIGHT flight_A = lookup_flight(catalog, id_A);
    FLIGHT flight_B = lookup_flight(catalog, id_B);

    char *date_a = get_flight_schedule_departure_date(flight_A);
    char *date_b = get_flight_schedule_departure_date(flight_B);

    gint compare;

    if (strcmp(date_a, date_b) == 0)
        compare = strcmp(id_A, id_B);
    else
        compare = -(strcmp(date_a, date_b));

    free(date_a);
    free(date_b);

    return compare;
}

gint sort_reservation_list(gconstpointer a, gconstpointer b, gpointer user_data)
{
    const int *id_reservation_A = (const int *)a;
    const int *id_reservation_B = (const int *)b;
    int int_A = *id_reservation_A;
    int int_B = *id_reservation_B;
    char id_A[16];
    sprintf(id_A, "Book%010d", int_A);
    char id_B[16];
    sprintf(id_B, "Book%010d", int_B);

    RESERVATIONS_CATALOG catalog = (RESERVATIONS_CATALOG)user_data;
    RESERVATION res_A = lookup_reservation(catalog, id_A);
    RESERVATION res_B = lookup_reservation(catalog, id_B);

    char *date_A = get_reservation_begin_date(res_A);
    char *date_B = get_reservation_begin_date(res_B);

    gint compare;

    if (strcmp(date_A, date_B) == 0)
        compare = strcmp(id_A, id_B);
    else
        compare = -(strcmp(date_A, date_B));

    free(date_A);
    free(date_B);

    return compare;
}

gint sort_flight_array_by_dates3(gconstpointer a, gconstpointer b, gpointer user_data)
{
    const int *id_flight_A = (const int *)a;
    const int *id_flight_B = (const int *)b;
    int int_A = *id_flight_A;
    int int_B = *id_flight_B;
    char id_A[11];
    sprintf(id_A, "%010d", int_A);
    char id_B[11];
    sprintf(id_B, "%010d", int_B);

    FLIGHTS_CATALOG catalog = (FLIGHTS_CATALOG)user_data;
    FLIGHT flight_A = lookup_flight(catalog, id_A);
    FLIGHT flight_B = lookup_flight(catalog, id_B);

    // Compare dates
    char *date_a = get_flight_schedule_departure_date(flight_A);
    char *date_b = get_flight_schedule_departure_date(flight_B);

    gint compare;

    if (date_compare_with_time(date_a, date_b) == 0)
        compare = strcmp(id_A, id_B);
    else
        compare = date_compare_with_time(date_a, date_b);

    // Free dates
    free(date_a);
    free(date_b);

    return compare;
}

