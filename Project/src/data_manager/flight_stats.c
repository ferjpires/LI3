#include "data_manager/flight_stats.h"

#include <string.h>
#include <stdlib.h>
#include <glib.h>

int _get_flight_delay(char *date1, char *date2)
{
    int begin_date = date_with_time_to_number(date1);
    int end_date = date_with_time_to_number(date2);
    return end_date - begin_date;
}
