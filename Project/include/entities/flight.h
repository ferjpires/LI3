#ifndef FLIGHT_H
#define FLIGHT_H


#include <glib.h>

typedef struct flight *FLIGHT;

/**
 * @brief Creates a new flight
 *
 * @return new_flight - The new flight of type 'FLIGHT'
 */
FLIGHT create_flight(void);

/**
 * @brief Sets the flight id
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param id - The id of type 'char*'
 */
void set_flight_id(FLIGHT flight, char *id);

/**
 * @brief Gets the flight id
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return id - The flight id of type 'char*'
 */
char *get_flight_id(FLIGHT flight);

/**
 * @brief Sets the flight airline
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param airline - The airline of type 'char*'
 */
void set_flight_airline(FLIGHT flight, char *airline);

/**
 * @brief Gets the flight airline
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return airline - The flight airline of type 'char*'
 */
char *get_flight_airline(FLIGHT flight);

/**
 * @brief Sets the flight plane model
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param plane_model - The plane model of type 'char*'
 */
void set_flight_plane_model(FLIGHT flight, char *plane_model);

/**
 * @brief Gets the flight plane model
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return plane model - The flight plane model of type 'char*'
 */
char *get_flight_plane_model(FLIGHT flight);

/**
 * @brief Sets the flight total seats
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param total_seats - The total seats of type 'char*'
 */
void set_flight_total_seats(FLIGHT flight, char *total_seats);

/**
 * @brief Gets the flight total seats
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return total seats - The flight total seats of type 'char*'
 */
char *get_flight_total_seats(FLIGHT flight);

/**
 * @brief Sets the flight origin
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param origin - The origin of type 'char*'
 */
void set_flight_origin(FLIGHT flight, char *origin);

/**
 * @brief Gets the flight origin
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return origin - The flight origin of type 'char*'
 */
char *get_flight_origin(FLIGHT flight);

/**
 * @brief Sets the flight destination
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param destination - The destination of type 'char*'
 */
void set_flight_destination(FLIGHT flight, char *destination);

/**
 * @brief Gets the flight destination
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return destination - The flight destination of type 'char*'
 */
char *get_flight_destination(FLIGHT flight);

/**
 * @brief Sets the flight schedule departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param schedule_departure_date - The schedule departure date of type 'char*'
 */
void set_flight_schedule_departure_date(FLIGHT flight, char *schedule_departure_date);

/**
 * @brief Gets the flight schedule departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return schedule departure date - The flight schedule departure date of type 'char*'
 */
char *get_flight_schedule_departure_date(FLIGHT flight);

/**
 * @brief Sets the flight schedule arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param schedule_arrival_date - The schedule arrival date of type 'char*'
 */
void set_flight_schedule_arrival_date(FLIGHT flight, char *schedule_arrival_date);

/**
 * @brief Gets the flight schedule arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return schedule arrival date - The flight schedule arrival date of type 'char*'
 */
char *get_flight_schedule_arrival_date(FLIGHT flight);

/**
 * @brief Sets the flight real departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param real_departure_date - The real departure date of type 'char*'
 */
void set_flight_real_departure_date(FLIGHT flight, char *real_departure_date);

/**
 * @brief Gets the flight real departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return real departure date - The flight real departure date of type 'char*'
 */
char *get_flight_real_departure_date(FLIGHT flight);

/**
 * @brief Sets the flight real arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param real_arrival_date - The real arrival date of type 'char*'
 */
void set_flight_real_arrival_date(FLIGHT flight, char *real_arrival_date);

/**
 * @brief Gets the flight real arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return real arrival date - The flight real arrival date of type 'char*'
 */
char *get_flight_real_arrival_date(FLIGHT flight);

/**
 * @brief Sets the flight pilot
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param pilot - The pilot of type 'char*'
 */
void set_flight_pilot(FLIGHT flight, char *pilot);

/**
 * @brief Gets the flight pilot
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return pilot - The flight pilot of type 'char*'
 */
char *get_flight_pilot(FLIGHT flight);

/**
 * @brief Sets the flight copilot
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param copilot - The copilot of type 'char*'
 */
void set_flight_copilot(FLIGHT flight, char *copilot);

/**
 * @brief Gets the flight copilot
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return copilot - The flight copilot of type 'char*'
 */
char *get_flight_copilot(FLIGHT flight);

/**
 * @brief Verifies if a flight id is valid
 * 
 * @param id - The flight id of type 'char*'
 */
int _is_flight_id(char *id);

/**
 * @brief Gets the flight passenger number
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return copilot - The flight passenger number of type 'int'
 */
int get_flight_passenger_number(FLIGHT flight);

/**
 * @brief Sets the flight passenger number
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param passenger_number - The passenger number of type 'int'
 */
void set_flight_passenger_number(FLIGHT flight);

/**
 * @brief Gets the flight delay
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return copilot - The flight delay of type 'int'
 */
int get_flight_delay(FLIGHT flight);

/**
 * @brief Sets the flight delay
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param delay - The delay of type 'int'
 */
void set_flight_delay(FLIGHT flight, int delay);

/**
 * @brief Destroys the flight
 *
 * @param data - The flight of type 'gpointer'
 */
void flight_destroy_function(gpointer data);

#endif