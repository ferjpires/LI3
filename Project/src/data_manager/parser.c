#include "data_manager/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>

#include "data_manager/validater.h"
#include "data_manager/flight_stats.h"
#include "data_manager/reservation_stats.h"
#include "data_manager/airport_stats.h"
#include "data_manager/user_stats.h"
// #include "data_manager/hotel_stats.h"
// #include "data_manager/user_stats.h"
#include "entities/flight.h"
#include "entities/user.h"
#include "entities/reservation.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/users_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "stats/metrics_catalog.h"
#include "stats/metric_manager.h"
#include "utils/parser_utils.h"

#define MAX_FLIGHT_TOKENS 13
#define MAX_USER_TOKENS 12
#define MAX_RESERVATION_TOKENS 13
#define MAX_PASSENGER_TOKENS 2

void parser(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
            AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog,
            FILE *users_file, FILE *flights_file, FILE *reservations_file, FILE *passengers_file,
            METRICS_CATALOG metrics)
{
    set_flight(flights_catalog, airports_catalog, flights_file, metrics);
    set_user(users_catalog, users_file, metrics);
    set_reservation(reservations_catalog, users_catalog, hotels_catalog, reservations_file, metrics);
    set_passenger(flights_catalog, users_catalog, passengers_file, metrics);
    stats_for_seven(airports_catalog);
    stats_for_six(flights_catalog, airports_catalog);
}

void set_flight(FLIGHTS_CATALOG catalog, AIRPORTS_CATALOG airports_catalog, FILE *file, METRICS_CATALOG metrics)
{
    char errorsPath[] = "Resultados/flights_errors.csv";

    FILE *errorsFile = fopen(errorsPath, "a");
    if (errorsFile == NULL)
        printf("Erro ao abrir o arquivo de erros: %s\n", errorsPath);

    int numStrings = MAX_FLIGHT_TOKENS;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1)
    {
        GString *temp_line = g_string_new(line);
        char **info = malloc(numStrings * sizeof(char *));
        if (info == NULL)
        {
            printf("Erro ao alocar memória\n");
            fclose(file);
            fclose(errorsFile);
            g_string_free(temp_line, TRUE);
        }

        for (int i = 0; i < numStrings; i++)
        {
            info[i] = g_malloc(60);
            if (info[i] == NULL)
            {
                printf("Erro ao alocar memória\n");
                fclose(file);
                fclose(errorsFile);
                g_string_free(temp_line, TRUE);
                free_info(info, numStrings);
            }
        }

        gchar **tokens = g_strsplit(temp_line->str, ";", -1);
        for (int i = 0; i < numStrings && tokens[i] != NULL; i++)
        {
            strcpy(info[i], tokens[i]);
            size_t last_char = strlen(info[i]) - 1;
            if (info[i][last_char] == '\n')
                info[i][last_char] = '\0';
        }
        g_strfreev(tokens);
        g_string_free(temp_line, TRUE);

        if (is_flight_valid(info) == 1)
        {
            // Converting the first 3 characters of the airport code to uppercase
            for (int i = 0; i < 3; i++)
            {
                info[4][i] = toupper((unsigned char)info[4][i]);
                info[5][i] = toupper((unsigned char)info[5][i]);
            }
            // Calculating the flight delay
            int delay = _get_flight_delay(info[6], info[8]);
            sprintf(info[12], "%d", delay);
            // Building the flight and airport
            build_flight(info, catalog);
            build_airport(airports_catalog, info[4], delay, info[0]);
            flight_metrics(metrics, info[6]);
        }
        else
            fprintf(errorsFile, "%s", line);

        free_info(info, numStrings);
    }

    free(line);
    fclose(errorsFile);
}

void set_user(USERS_CATALOG catalog, FILE *file, METRICS_CATALOG metrics)
{
    char errorsPath[] = "Resultados/users_errors.csv";

    FILE *errorsFile = fopen(errorsPath, "a");
    if (errorsFile == NULL)
        printf("Erro ao abrir o arquivo de erros: %s\n", errorsPath);

    int numStrings = MAX_USER_TOKENS;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1)
    {

        GString *temp_line = g_string_new(line);

        char **info = malloc(numStrings * sizeof(char *));
        if (info == NULL)
        {
            printf("Erro ao alocar memória\n");
            fclose(file);
            fclose(errorsFile);
            g_string_free(temp_line, TRUE);
        }

        for (int i = 0; i < numStrings; i++)
        {
            info[i] = g_malloc(100);
            if (info[i] == NULL)
            {
                printf("Erro ao alocar memória\n");
                fclose(file);
                fclose(errorsFile);
                g_string_free(temp_line, TRUE);
                free_info(info, numStrings);
            }
        }

        gchar **tokens = g_strsplit(temp_line->str, ";", -1);
        for (int i = 0; i < numStrings && tokens[i] != NULL; i++)
        {
            strcpy(info[i], tokens[i]);
            size_t last_char = strlen(info[i]) - 1;
            if (info[i][last_char] == '\n')
                info[i][last_char] = '\0';
        }
        g_strfreev(tokens);
        g_string_free(temp_line, TRUE);

        if (is_user_valid(info) == 1)
        {
            build_user(info, catalog);
            user_metrics(metrics, info[9]);
        }
        else
            fprintf(errorsFile, "%s", line);

        free_info(info, numStrings);
    }

    free(line);
    fclose(errorsFile);
}

void set_reservation(RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog, HOTELS_CATALOG hotels_catalog,
                     FILE *file, METRICS_CATALOG metrics)
{
    char errorsPath[] = "Resultados/reservations_errors.csv";

    FILE *errorsFile = fopen(errorsPath, "a");
    if (errorsFile == NULL)
        printf("Erro ao abrir o arquivo de erros: %s\n", errorsPath);

    int numStrings = MAX_RESERVATION_TOKENS;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int number_of_nights = 0;
    double total_cost = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {

        GString *temp_line = g_string_new(line);

        char **info = malloc(numStrings * sizeof(char *));
        if (info == NULL)
        {
            printf("Erro ao alocar memória\n");
            fclose(file);
            fclose(errorsFile);
            g_string_free(temp_line, TRUE);
        }

        for (int i = 0; i < numStrings; i++)
        {
            info[i] = g_malloc(80);
            if (info[i] == NULL)
            {
                printf("Erro ao alocar memória\n");
                fclose(file);
                fclose(errorsFile);
                g_string_free(temp_line, TRUE);
                free_info(info, numStrings);
            }
        }

        gchar **tokens = g_strsplit(temp_line->str, ";", -1);
        for (int i = 0; i < numStrings && tokens[i] != NULL; i++)
        {
            strcpy(info[i], tokens[i]);

            size_t last_char = strlen(info[i]) - 1;
            if (info[i][last_char] == '\n')
                info[i][last_char] = '\0';
        }
        g_strfreev(tokens);
        g_string_free(temp_line, TRUE);

        if (is_reservation_valid(info) == 1)
        {
            if (contains_user(users_catalog, info[1]) == 1)
            {
                number_of_nights = _get_reservation_total_nights(info[7], info[8]);
                total_cost = _get_reservation_total_cost(info[9], number_of_nights, info[5]);
                build_reservation(info, number_of_nights, total_cost, reservations_catalog);
                build_user_stats(lookup_user(users_catalog, info[1]), total_cost, info[0]);
                reservation_metrics(metrics, info[7]);
                if (contains_hotel(hotels_catalog, info[2]) == 1)
                {
                    HOTEL found_hotel = lookup_hotel(hotels_catalog, info[2]);
                    set_hotel_rating(found_hotel, info[12]);
                    set_hotel_reservation_list(found_hotel, info[0]);
                }
                else
                    build_hotel(hotels_catalog, info[2], info[12], info[0]);
            }
            else
                fprintf(errorsFile, "%s", line);
        }
        else
            fprintf(errorsFile, "%s", line);

        free_info(info, numStrings);
    }

    free(line);
    fclose(errorsFile);
}

void set_passenger(FLIGHTS_CATALOG flights_catalog, USERS_CATALOG users_catalog, FILE *file, METRICS_CATALOG metrics)
{
    char errorsPathPassengers[] = "Resultados/passengers_errors.csv";
    char errorsPathFlights[] = "Resultados/flights_errors.csv";

    FILE *errorsFilePassengers = fopen(errorsPathPassengers, "a");
    FILE *errorsFileFlights = fopen(errorsPathFlights, "a");

    if (errorsFilePassengers == NULL)
        printf("Erro ao abrir o arquivo de erros: %s\n", errorsPathPassengers);
    if (errorsFileFlights == NULL)
        printf("Erro ao abrir o arquivo de erros: %s\n", errorsPathFlights);

    int numStrings = MAX_PASSENGER_TOKENS;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char flight_id[11];
    GArray *list = g_array_new(FALSE, FALSE, sizeof(char *));

    while ((read = getline(&line, &len, file)) != -1)
    {
        GString *temp_line = g_string_new(line);

        char **info = malloc(numStrings * sizeof(char *));
        if (info == NULL)
        {
            printf("Erro ao alocar memória\n");
            fclose(file);
            fclose(errorsFileFlights);
            fclose(errorsFilePassengers);
            g_string_free(temp_line, TRUE);
        }

        for (int i = 0; i < numStrings; i++)
        {
            info[i] = g_malloc(80);
            if (info[i] == NULL)
            {
                printf("Erro ao alocar memória\n");
                fclose(file);
                fclose(errorsFileFlights);
                fclose(errorsFilePassengers);
                g_string_free(temp_line, TRUE);
                free_info(info, numStrings);
            }
        }
        gchar **tokens = g_strsplit(temp_line->str, ";", -1);
        for (int i = 0; i < numStrings && tokens[i] != NULL; i++)
        {
            strcpy(info[i], tokens[i]);
            size_t last_char = strlen(info[i]) - 1;
            if (info[i][last_char] == '\n')
                info[i][last_char] = '\0';
        }
        g_strfreev(tokens);
        g_string_free(temp_line, TRUE);

        if (contains_flight(flights_catalog, info[0]) == 1)
        {
            if (contains_user(users_catalog, info[1]) == 1)
            {
                if (flight_id != info[0])
                {
                    g_array_free(list, TRUE);
                    list = g_array_new(FALSE, FALSE, sizeof(char *));
                    strcpy(flight_id, info[0]);
                }
                char *seats = get_flight_total_seats(lookup_flight(flights_catalog, info[0]));
                if (list->len < atoi(seats) - 1)
                {
                    g_array_append_val(list, info[1]);
                    set_user_flight_list(lookup_user(users_catalog, info[1]), info[0]);
                    set_flight_passenger_number(lookup_flight(flights_catalog, info[0]));
                    FLIGHT found_flight = lookup_flight(flights_catalog, info[0]);
                    char *date = get_flight_schedule_departure_date(found_flight);
                    USER found_user = lookup_user(users_catalog, info[1]);
                    passenger_metrics(metrics, date, found_user);
                    free(date);
                }
                else
                {
                    // delete struct from table
                    print_passenger_errors(list, info[0], errorsFilePassengers);
                    g_array_free(list, TRUE);
                    print_flight_errors(lookup_flight(flights_catalog, info[0]), errorsFileFlights);
                    remove_flight_from_hashtable(flights_catalog, info[0]);
                }
                g_free(seats);
            }
            else
                fprintf(errorsFilePassengers, "%s", line);
        }
        else
            fprintf(errorsFilePassengers, "%s", line);
        free_info(info, numStrings);
    }

    g_array_free(list, TRUE);
    free(line);
    fclose(errorsFilePassengers);
    fclose(errorsFileFlights);
}
