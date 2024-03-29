#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <glib.h>

#include "entities/flight.h"

struct flight
{
    int id;
    char *airline;
    char *plane_model;
    int total_seats;
    char *origin;
    char *destination;
    long long schedule_departure_date;
    long long schedule_arrival_date;
    long long real_departure_date;
    long long real_arrival_date;
    char *pilot;
    char *copilot;
    int passenger_number;
    int delay;
};

//                                               Create a flight
// ===================================================================================================================

FLIGHT create_flight(void)
{
    FLIGHT new_flight = malloc(sizeof(struct flight));

    new_flight->id = 0;
    new_flight->airline = NULL;
    new_flight->plane_model = NULL;
    new_flight->total_seats = 0;
    new_flight->origin = NULL;
    new_flight->destination = NULL;
    new_flight->schedule_departure_date = 0;
    new_flight->schedule_arrival_date = 0;
    new_flight->real_departure_date = 0;
    new_flight->real_arrival_date = 0;
    new_flight->pilot = NULL;
    new_flight->copilot = NULL;
    new_flight->passenger_number = 0;

    return new_flight;
}

//                                               ID
// ===================================================================================================================

char *get_flight_id(FLIGHT flight)
{
    char id[11];
    sprintf(id, "%010d", flight->id);
    return g_strdup(id);
}
void set_flight_id(FLIGHT flight, char *id)
{
    flight->id = atoi(id);
}

//                                               Airline
// ===================================================================================================================

char *get_flight_airline(FLIGHT flight)
{
    return g_strdup(flight->airline);
}
void set_flight_airline(FLIGHT flight, char *airline)
{
    free(flight->airline); // release previous one
    flight->airline = g_strdup(airline);
}

//                                               Plane Model
// ===================================================================================================================

char *get_flight_plane_model(FLIGHT flight)
{
    return g_strdup(flight->plane_model);
}
void set_flight_plane_model(FLIGHT flight, char *plane_model)
{
    free(flight->plane_model); // release previous one
    flight->plane_model = g_strdup(plane_model);
}

//                                               Total Seats
// ===================================================================================================================

char *get_flight_total_seats(FLIGHT flight)
{
    char seats[5];
    sprintf(seats, "%d", flight->total_seats);
    return g_strdup(seats);
}
void set_flight_total_seats(FLIGHT flight, char *total_seats)
{
    flight->total_seats = atoi(total_seats);
}

//                                               Origin
// ===================================================================================================================

char *get_flight_origin(FLIGHT flight)
{
    return g_strdup(flight->origin);
}
void set_flight_origin(FLIGHT flight, char *origin)
{
    free(flight->origin); // release previous one
    flight->origin = g_strdup(origin);
}

//                                               Destination
// ===================================================================================================================

char *get_flight_destination(FLIGHT flight)
{
    return g_strdup(flight->destination);
}
void set_flight_destination(FLIGHT flight, char *destination)
{
    free(flight->destination); // release previous one
    flight->destination = g_strdup(destination);
}

//                                               Schedule Departure Date
// ===================================================================================================================

char *get_flight_schedule_departure_date(FLIGHT flight)
{
    char date[35];
    sprintf(date, "%04lld/%02lld/%02lld %02lld:%02lld:%02lld",
            flight->schedule_departure_date / 10000000000LL, (flight->schedule_departure_date % 10000000000LL) / 100000000LL,
            (flight->schedule_departure_date % 100000000LL) / 1000000LL, (flight->schedule_departure_date % 1000000LL) / 10000LL,
            (flight->schedule_departure_date % 10000LL) / 100LL, flight->schedule_departure_date % 100LL);
    return g_strdup(date);
}
void set_flight_schedule_departure_date(FLIGHT flight, char *schedule_departure_date)
{
    int year, month, day, hour, minute, second;
    if (sscanf(schedule_departure_date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) == 6)
        flight->schedule_departure_date = ((long long)year) * 10000000000LL + ((long long)month) * 100000000 + ((long long)day) * 1000000 +
                                          ((long long)hour) * 10000 + ((long long)minute) * 100 + second;
}

//                                               Schedule Arrival Date
// ===================================================================================================================

char *get_flight_schedule_arrival_date(FLIGHT flight)
{
    char date[35];
    sprintf(date, "%04lld/%02lld/%02lld %02lld:%02lld:%02lld",
            flight->schedule_arrival_date / 10000000000LL, (flight->schedule_arrival_date % 10000000000LL) / 100000000LL,
            (flight->schedule_arrival_date % 100000000LL) / 1000000LL, (flight->schedule_arrival_date % 1000000LL) / 10000LL,
            (flight->schedule_arrival_date % 10000LL) / 100LL, flight->schedule_arrival_date % 100LL);
    return g_strdup(date);
}
void set_flight_schedule_arrival_date(FLIGHT flight, char *schedule_arrival_date)
{
    int year, month, day, hour, minute, second;
    if (sscanf(schedule_arrival_date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) == 6)
        flight->schedule_arrival_date = ((long long)year) * 10000000000LL + ((long long)month) * 100000000 + ((long long)day) * 1000000 +
                                        ((long long)hour) * 10000 + ((long long)minute) * 100 + second;
}

//                                               Real Departure Date
// ===================================================================================================================

char *get_flight_real_departure_date(FLIGHT flight)
{
    char date[35];
    sprintf(date, "%04lld/%02lld/%02lld %02lld:%02lld:%02lld",
            flight->real_departure_date / 10000000000LL, (flight->real_departure_date % 10000000000LL) / 100000000LL,
            (flight->real_departure_date % 100000000LL) / 1000000LL, (flight->real_departure_date % 1000000LL) / 10000LL,
            (flight->real_departure_date % 10000LL) / 100LL, flight->real_departure_date % 100LL);
    return g_strdup(date);
}
void set_flight_real_departure_date(FLIGHT flight, char *real_departure_date)
{
    int year, month, day, hour, minute, second;
    if (sscanf(real_departure_date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) == 6)
        flight->real_departure_date = ((long long)year) * 10000000000LL + ((long long)month) * 100000000 + ((long long)day) * 1000000 +
                                        ((long long)hour) * 10000 + ((long long)minute) * 100 + second;
}

//                                               Real Arrival Date
// ===================================================================================================================

char *get_flight_real_arrival_date(FLIGHT flight)
{
    char date[35];
    sprintf(date, "%04lld/%02lld/%02lld %02lld:%02lld:%02lld",
            flight->real_arrival_date / 10000000000LL, (flight->real_arrival_date % 10000000000LL) / 100000000LL,
            (flight->real_arrival_date % 100000000LL) / 1000000LL, (flight->real_arrival_date % 1000000LL) / 10000LL,
            (flight->real_arrival_date % 10000LL) / 100LL, flight->real_arrival_date % 100LL);
    return g_strdup(date);
}
void set_flight_real_arrival_date(FLIGHT flight, char *real_arrival_date)
{
    int year, month, day, hour, minute, second;
    if (sscanf(real_arrival_date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) == 6)
        flight->real_arrival_date = ((long long)year) * 10000000000LL + ((long long)month) * 100000000 + ((long long)day) * 1000000 +
                                        ((long long)hour) * 10000 + ((long long)minute) * 100 + second;
}

//                                               Pilot
// ===================================================================================================================

char *get_flight_pilot(FLIGHT flight)
{
    return g_strdup(flight->pilot);
}
void set_flight_pilot(FLIGHT flight, char *pilot)
{
    free(flight->pilot); // release previous one
    flight->pilot = g_strdup(pilot);
}

//                                               Copilot
// ===================================================================================================================

char *get_flight_copilot(FLIGHT flight)
{
    return g_strdup(flight->copilot);
}
void set_flight_copilot(FLIGHT flight, char *copilot)
{
    free(flight->copilot); // release previous one
    flight->copilot = g_strdup(copilot);
}

//                                               Validation
// ===================================================================================================================

int _is_flight_id(char *id)
{
    while (*id)
    {
        if (!isdigit(*id))
        {
            return 0; // Not a digit
        }
        id++;
    }
    return 1; // All characters are digits
}

//                                               Passenger Number
// ===================================================================================================================

int get_flight_passenger_number(FLIGHT flight)
{
    return flight->passenger_number;
}
void set_flight_passenger_number(FLIGHT flight)
{
    flight->passenger_number++;
}

//                                               Delay
// ===================================================================================================================

int get_flight_delay(FLIGHT flight)
{
    return flight->delay;
}
void set_flight_delay(FLIGHT flight, int delay)
{
    flight->delay = delay;
}

//                                               Free Flight
// ===================================================================================================================
void flight_destroy_function(gpointer data)
{
    FLIGHT flight = (FLIGHT)data; // Cast to the correct type
    // Free dynamically allocated strings
    free(flight->airline);
    free(flight->plane_model);
    free(flight->origin);
    free(flight->destination);
    free(flight->pilot);
    free(flight->copilot);

    // Free the flight structure itself
    free(flight);
}
