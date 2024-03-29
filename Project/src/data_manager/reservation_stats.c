#include "data_manager/reservation_stats.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>

#include "entities/reservation.h"
#include "catalogs/reservations_catalog.h"

double _get_reservation_total_cost(char *price_per_night, int number_of_nights, char *city_tax)
{
    char *endptr;
    double price = strtod(price_per_night, &endptr);
    double tax = strtod(city_tax, &endptr);
    double res = 0;

    res = (price * number_of_nights) + (((price * number_of_nights) / 100) * tax);

    return res;
}

int _get_reservation_total_nights(char *begin_date, char *end_date)
{
    int begin_date_day, end_date_day;
    sscanf(begin_date, "%*d/%*d/%d", &begin_date_day);
    sscanf(end_date, "%*d/%*d/%d", &end_date_day);

    return (end_date_day - begin_date_day);
}
