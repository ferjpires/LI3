#include "data_manager/validater.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>


int is_valid_date(char *date)
{
    int year, month, day;
    if (sscanf(date, "%4d/%2d/%2d", &year, &month, &day) == 3)
        if (year >= 1900 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
            return 1;
    return 0;
}

int is_valid_date_with_time(char *date)
{
    int year, month, day, hour, minute, second;
    if (sscanf(date, "%4d/%2d/%2d %2d:%2d:%2d", &year, &month, &day, &hour, &minute, &second) == 6)
        if (year >= 1900 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31 &&
            hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59)
            return 1;
    return 0;
}

int date_to_number(char *date)
{
    int year, month, day;
    sscanf(date, "%d/%d/%d", &year, &month, &day);
    return year * 31536000 + month * 2678400 + day * 86400;
}

int date_compare(char *date1, char *date2)
{
    int result = g_strcmp0(date1, date2);

    if (result < 0)
        return 1; // date 2 bigger than date 1
    else if (result > 0)
        return -1; // date 1 bigger than date 2
    else
        return 0; // equal dates
}

int date_with_time_to_number(char *date)
{
    int year, month, day, hour, minute, second;
    sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    long long date_number = year * 31536000 + month * 2678400 + day * 86400 + hour * 3600 + minute * 60 + second;

    return date_number;
}

int date_compare_with_time(char *date1, char *date2)
{
    int result = g_strcmp0(date1, date2);

    if (result < 0)
        return 1; // date 2 bigger than date 1
    else if (result > 0)
        return -1; // date 1 bigger than date 2
    else
        return 0; // equal dates
}

// flight arrival > flight departure
int flight_departure_arrival_validation(char *departure_time, char *arrival_time)
{
    if (date_compare_with_time(departure_time, arrival_time) == 1)
        return 1;
    else
        return 0;
}

// reservation end date > begin date
int reservation_date_validation(char *begin_date, char *end_date)
{
    if (date_compare(begin_date, end_date) == 1)
        return 1;
    else
        return 0;
}

// email validating
int is_email_valid(char *email)
{
    int i, atpos = -1, dotpos = -1;
    int len = strlen(email);

    for (i = 0; i < len; i++)
        if (email[i] == '@')
        {
            if (atpos != -1)
                return 0;
            atpos = i;
        }

    for (i = atpos + 1; i < len; i++)
        if (email[i] == '.')
        {
            dotpos = i;
            break;
        }

    if (atpos > 0 && dotpos - atpos > 1 && dotpos < len - 1 && len - dotpos > 2)
        return 1;
    else
        return 0;
}

// validating country code
int is_country_code_valid(char *country_code)
{
    if (strlen(country_code) == 2)
        return 1;
    else
        return 0;
}

// validating account status
int is_account_status_valid(char *account_status)
{
    if ((strcasecmp(account_status, "active") == 0) ||
        (strcasecmp(account_status, "inactive") == 0))
        return 1;
    else
        return 0;
}

// validating user active
int is_user_active(char *account_status)
{
    if (strcasecmp(account_status, "active") == 0)
        return 1;
    else
        return 0;
}

// validating total seats
int is_total_seats_valid(char *total_seats)
{
    char *endptr;
    long int seats = strtol(total_seats, &endptr, 10);
    if (*endptr != '\0' && *endptr != '\n')
        return 0;
    if (seats < 0)
        return 0;
    return 1;
}

// validating flight seats
int is_flight_total_seats_valid(char *total_seats, int number_of_passengers)
{
    int seats = atoi(total_seats);
    if (number_of_passengers > seats)
        return 0;
    else
        return 1;
}

// validating airport
int is_airport_name_valid(char *airport)
{
    if (strlen(airport) == 3)
        return 1;
    else
        return 0;
}

// validating hotel star number
int is_hotel_stars_valid(char *hotel_stars)
{
    char *endptr;
    long int stars = strtol(hotel_stars, &endptr, 10);
    if (*endptr != '\0' && *endptr != '\n')
        return 0;
    if (stars < 1 || stars > 5)
        return 0;
    return 1;
}

// validating city tax
int is_city_tax_valid(char *city_tax)
{
    if (strlen(city_tax) < 1)
        return 0;
    char *endptr;
    long int tax = strtol(city_tax, &endptr, 10);
    if (*endptr != '\0' && *endptr != '\n')
        return 0;
    if (tax < 0)
        return 0;
    return 1;
}

// validating price per night
int is_price_per_night_valid(char *price_per_night)
{
    if (strlen(price_per_night) < 1)
        return 0;
    char *endptr;
    long int price = strtol(price_per_night, &endptr, 10);
    if (*endptr != '\0' && *endptr != '\n')
        return 0;
    if (price < 0)
        return 0;
    return 1;
}

// validating includes breakfast
int is_includes_breakfast_valid(char *includes_breakfast)
{
    if ((strcasecmp(includes_breakfast, "false") == 0) || (strcasecmp(includes_breakfast, "f") == 0) ||
        (strcasecmp(includes_breakfast, "0") == 0) || (strcmp(includes_breakfast, "") == 0))
        return 0;
    if ((strcasecmp(includes_breakfast, "true") == 0) || (strcasecmp(includes_breakfast, "t") == 0) ||
        (strcasecmp(includes_breakfast, "1") == 0))
        return 1;
    else
        return -1;
}

// validating rating
int is_rating_valid(char *rating)
{
    if (strcmp(rating, "") == 0)
        return 1;
    char *endptr;
    long int rate = strtol(rating, &endptr, 10);
    if (*endptr != '\0' && *endptr != '\n')
        return 0;
    if (rate < 1 || rate > 5)
        return 0;
    return 1;
}

// validating camps > 0
// User: id, name, phone_number, sex, passport, address, pay_method;
// Flight : id, airline, plane_model, pilot, copilot;
// Reservation: id, user_id, hotel_id, hotel_name, address;
int is_param_valid(char *param)
{
    if (strlen(param) > 0)
        return 1;
    else
        return 0;
}

int is_user_valid(char **info)
{
    if (is_param_valid(info[0]) == 1 &&          // id
        is_param_valid(info[1]) == 1 &&          // name
        is_email_valid(info[2]) == 1 &&          // email
        is_param_valid(info[3]) == 1 &&          // phone number
        is_valid_date(info[4]) == 1 &&           // birth date
        is_param_valid(info[5]) == 1 &&          // sex
        is_param_valid(info[6]) == 1 &&          // passport
        is_country_code_valid(info[7]) == 1 &&   // country code
        is_param_valid(info[8]) == 1 &&          // address
        is_valid_date_with_time(info[9]) == 1 && // account creation
        is_param_valid(info[10]) == 1 &&         // pay method
        is_account_status_valid(info[11]) == 1   // account status
    )
        return 1;
    else
        return 0;
}

int is_flight_valid(char **info)
{
    if (is_param_valid(info[0]) == 1 &&                               // id
        is_param_valid(info[1]) == 1 &&                               // airline
        is_param_valid(info[2]) == 1 &&                               // plane model
        is_total_seats_valid(info[3]) == 1 &&                         // total seats
        is_airport_name_valid(info[4]) == 1 &&                        // origin
        is_airport_name_valid(info[5]) == 1 &&                        // destination
        is_valid_date_with_time(info[6]) == 1 &&                      // schedule departure date
        is_valid_date_with_time(info[7]) == 1 &&                      // schedule arrival date
        is_valid_date_with_time(info[8]) == 1 &&                      // real departure date
        is_valid_date_with_time(info[9]) == 1 &&                      // real arrival date
        is_param_valid(info[10]) == 1 &&                              // pilot
        is_param_valid(info[11]) == 1 &&                              // copilot
        flight_departure_arrival_validation(info[6], info[7]) == 1 && // schedule departure and arrival date
        flight_departure_arrival_validation(info[8], info[9]) == 1    // real departure and arrival date
    )
        return 1;
    else
        return 0;
}

int is_reservation_valid(char **info)
{
    if (is_param_valid(info[0]) == 1 &&                                                               // id
        is_param_valid(info[1]) == 1 &&                                                               // user id
        is_param_valid(info[2]) == 1 &&                                                               // hotel id
        is_param_valid(info[3]) == 1 &&                                                               // hotel name
        is_hotel_stars_valid(info[4]) == 1 &&                                                         // hotel stars
        is_city_tax_valid(info[5]) == 1 &&                                                            // city tax
        is_param_valid(info[6]) == 1 &&                                                               // address
        is_valid_date(info[7]) == 1 &&                                                                // begin date
        is_valid_date(info[8]) == 1 &&                                                                // end date
        is_price_per_night_valid(info[9]) == 1 &&                                                     // price per night
        (is_includes_breakfast_valid(info[10]) == 1 || is_includes_breakfast_valid(info[10]) == 0) && // includes breakfast
        is_rating_valid(info[12]) == 1 &&                                                             // rating
        reservation_date_validation(info[7], info[8]) == 1                                            // end date after begin date
    )
        return 1;
    else
        return 0;
}