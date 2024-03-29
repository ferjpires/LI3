#include <glib.h>
#include <stdio.h>

#include "entities/airport.h"


struct airport
{
    char *name;
    GArray *delay_list;
    int median;
    GHashTable *yearly_passengers;
    GArray *flight_list;
};

//                                               Create an airport
// ===================================================================================================================

AIRPORT create_airport(void)
{
    AIRPORT new_airport = malloc(sizeof(struct airport));

    new_airport->name = NULL;
    new_airport->delay_list = g_array_new(FALSE, FALSE, sizeof(int));
    new_airport->median = 0;
    new_airport->yearly_passengers = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
    new_airport->flight_list = g_array_new(FALSE, FALSE, sizeof(int));

    return new_airport;
}

//                                               Free airport
// ===================================================================================================================

void airport_destroy_function(gpointer data)
{
    AIRPORT airport = (AIRPORT)data; // Cast to the correct type
    free(airport->name);
    g_array_free(airport->delay_list, TRUE);
    g_hash_table_destroy(airport->yearly_passengers);
    g_array_free(airport->flight_list, TRUE);
    free(airport);
}

//                                               Name
// ===================================================================================================================

char *get_airport_name(AIRPORT airport)
{
    return strdup(airport->name);
}
void set_airport_name(AIRPORT airport, char *name)
{
    free(airport->name); // release previous one
    airport->name = strdup(name);
}

//                                               Delay List
// ===================================================================================================================

GArray *get_airport_delay_list(AIRPORT airport)
{
    return g_array_copy(airport->delay_list);
}

void set_airport_delay_list(AIRPORT airport, int delay)
{
    g_array_append_val(airport->delay_list, delay);
}

void order_delay_list(AIRPORT airport)
{
    g_array_sort(airport->delay_list, sort_delay_list);
}

//                                               Median
// ===================================================================================================================

int get_airport_median(AIRPORT airport)
{
    return airport->median;
}
void set_airport_median(AIRPORT airport, int median)
{
    airport->median = median;
}

//                                               Passengers
// ===================================================================================================================

int get_airport_yearly_passengers(AIRPORT airport, char *year)
{
    if (g_hash_table_contains(airport->yearly_passengers, year))
    {
        gpointer passengers = g_hash_table_lookup(airport->yearly_passengers, year);
        return GPOINTER_TO_INT(passengers);
    }
    else
        return 0;
}

void set_airport_yearly_passengers(AIRPORT airport, char *year, int additional_passengers)
{
    gpointer existingPassengers = g_hash_table_lookup(airport->yearly_passengers, year);

    if (existingPassengers != NULL)
    {
        int totalPassengers = GPOINTER_TO_INT(existingPassengers) + additional_passengers;
        g_hash_table_replace(airport->yearly_passengers, g_strdup(year), GINT_TO_POINTER(totalPassengers));
    }
    else
    {
        g_hash_table_insert(airport->yearly_passengers, g_strdup(year), GINT_TO_POINTER(additional_passengers));
    }
}

//                                               FLight List
// ===================================================================================================================

GArray *get_airport_flight_list(AIRPORT airport)
{
    return g_array_copy(airport->flight_list);
}

void set_airport_flight_list(AIRPORT airport, char *flight_id)
{
    int id = atoi(flight_id);
    g_array_append_val(airport->flight_list, id);
}
