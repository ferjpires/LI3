#include "queries/query1.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "entities/flight.h"
#include "entities/reservation.h"
#include "entities/user.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"
#include "data_manager/validater.h"
#include "data_manager/user_stats.h"

// ============================================== User Write =========================================================

void _write_user_resume(char *user_id, USER user, FILE *output, int flag)
{
    // go through the table and when user_id matches we write:
    // name;sex;age;country_code;number_of_flights;number_of_reservations;total_spent
    // Verify account_status is active
    char *account_status = NULL;
    account_status = get_user_account_status(user);

    if (is_user_active(account_status))
    {
        char *name = NULL;
        char *sex = NULL;
        int age = 0;
        char *country_code = NULL;
        char *passport = NULL;
        GArray *flight_list = NULL;
        int number_of_flights = 0;
        int number_of_reservations = 0;
        double total_spent = 0;

        name = get_user_name(user);
        sex = get_user_sex(user);
        age = get_user_age(user);
        country_code = get_user_country_code(user);
        passport = get_user_passport(user);
        flight_list = get_user_flight_list(user);
        if (flight_list != NULL)
            number_of_flights = flight_list->len;
        number_of_reservations = get_user_reservation_number(user);
        total_spent = get_user_total_spent(user);

        // Write in output (replace for output function !!!)
        if (flag == 1)
        { // write the output for query 1F User
            fprintf(output, "--- 1 ---\nname: %s\nsex: %s\nage: %d\ncountry_code: %s\npassport: %s\nnumber_of_flights: %d\nnumber_of_reservations: %d\ntotal_spent: %.3f\n",
                    name,
                    sex,
                    age,
                    country_code,
                    passport,
                    number_of_flights,
                    number_of_reservations,
                    total_spent);
        }
        else
        { // write the output for query 1 User
            fprintf(output, "%s;%s;%d;%s;%s;%d;%d;%.3f\n",
                    name,
                    sex,
                    age,
                    country_code,
                    passport,
                    number_of_flights,
                    number_of_reservations,
                    total_spent);
        }

        // free memory
        free(name);
        free(sex);
        free(country_code);
        free(passport);
        g_array_free(flight_list, TRUE);
    }
    // free memory
    free(account_status);
}

// ============================================== Reservation Write =========================================================
void _write_reservation_resume(char *reservation_id, RESERVATION reservation, FILE *output, int flag)
{
    // go through the table and when reservation_id matches we write:
    // (hotel_id;hotel_name;hotel_stars;begin_date;end_date;includes_breakfast;nights;total_price)

    char *hotel_id = NULL;
    char *hotel_name = NULL;
    char *hotel_stars = NULL;
    char *begin_date = NULL;
    char *end_date = NULL;
    char *includes_breakfast = NULL;
    int number_of_nights = 0;
    double total_price = 0;

    hotel_id = get_reservation_hotel_id(reservation);
    hotel_name = get_reservation_hotel_name(reservation);
    hotel_stars = get_reservation_hotel_stars(reservation);
    begin_date = get_reservation_begin_date(reservation);
    end_date = get_reservation_end_date(reservation);
    includes_breakfast = get_reservation_includes_breakfast(reservation);
    number_of_nights = get_reservation_number_of_nights(reservation);
    total_price = get_reservation_total_price(reservation);

    // Write in output (replace for output function !!!)
    if (flag == 1)
    { // write the output for query 1F Reservation
        fprintf(output, "--- 1 ---\nhotel_id: %s\nhotel_name: %s\nhotel_stars: %s\nbegin_date: %s\nend_date: %s\nincludes_breakfast: %s\nnights: %d\ntotal_price: %.3f\n",
                hotel_id,
                hotel_name,
                hotel_stars,
                begin_date,
                end_date,
                includes_breakfast,
                number_of_nights,
                total_price);
    }
    else
    { // write the output for query 1 Reservation
        fprintf(output, "%s;%s;%s;%s;%s;%s;%d;%.3f\n",
                hotel_id,
                hotel_name,
                hotel_stars,
                begin_date,
                end_date,
                includes_breakfast,
                number_of_nights,
                total_price);
    }

    // free memory
    free(hotel_id);
    free(hotel_name);
    free(hotel_stars);
    free(begin_date);
    free(end_date);
    free(includes_breakfast);
}

// ============================================== Flight Write =========================================================
void _write_flight_resume(char *flight_id, FLIGHT flight, FILE *output, int flag)
{
    // go through the table and when flight_id matches we write:
    // (airline;plane_model;origin;destination;schedule_departure_date;schedule_arrival_date;passengers;delay)

    char *airline = NULL;
    char *plane_model = NULL;
    char *origin = NULL;
    char *destination = NULL;
    char *schedule_departure_date = NULL;
    char *schedule_arrival_date = NULL;
    int passenger_number = 0;
    int delay = 0;

    airline = get_flight_airline(flight);
    plane_model = get_flight_plane_model(flight);
    origin = get_flight_origin(flight);
    destination = get_flight_destination(flight);
    schedule_departure_date = get_flight_schedule_departure_date(flight);
    schedule_arrival_date = get_flight_schedule_arrival_date(flight);
    passenger_number = get_flight_passenger_number(flight);
    delay = get_flight_delay(flight);

    // Write in output (replace for output function !!!)
    if (flag == 1)
    { // write the output for query 1F Flight
        fprintf(output, "--- 1 ---\nairline: %s\nplane_model: %s\norigin: %s\ndestination: %s\nschedule_departure_date: %s\nschedule_arrival_date: %s\npassengers: %d\ndelay: %d\n",
                airline,
                plane_model,
                origin,
                destination,
                schedule_departure_date,
                schedule_arrival_date,
                passenger_number,
                delay);
    }
    else
    { // write the output for query 1 Flight
        fprintf(output, "%s;%s;%s;%s;%s;%s;%d;%d\n",
                airline,
                plane_model,
                origin,
                destination,
                schedule_departure_date,
                schedule_arrival_date,
                passenger_number,
                delay);
    }

    // free memory
    free(airline);
    free(plane_model);
    free(origin);
    free(destination);
    free(schedule_departure_date);
    free(schedule_arrival_date);
}

//                                          Execution of query one
//===================================================================================================================
void exec_query_one(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                    char *args, FILE *output, int flag)
{
    // verifying which identifier was given (User/Flight/Reservation)
    if (_is_flight_id(args))
    {
        if (lookup_flight(flights_catalog, args) != NULL)
        {
            FLIGHT found_flight = lookup_flight(flights_catalog, args);
            _write_flight_resume(args, found_flight, output, flag);
        }
    }
    else if (_is_reservation_id(args))
    {
        if (lookup_reservation(reservations_catalog, args) != NULL)
        {
            RESERVATION found_reservation = lookup_reservation(reservations_catalog, args);
            _write_reservation_resume(args, found_reservation, output, flag);
        }
    }
    else
    {
        if (lookup_user(users_catalog, args) != NULL)
        {
            USER found_user = lookup_user(users_catalog, args);
            _write_user_resume(args, found_user, output, flag);
        }
    }
}