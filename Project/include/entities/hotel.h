#ifndef HOTEL_H
#define HOTEL_H

#include <glib.h>


typedef struct hotel *HOTEL;

/**
 * @brief Creates a new hotel, allocating memory for it
 * 
 * @return new_hotel - The new hotel of type 'HOTEL'
*/
HOTEL create_hotel(void);

/**
 * @brief Gets the hotel id
 * 
 * @param hotel - The hotel of type 'HOTEL'
 * 
 * @return id - The hotel id of type 'char*'
*/
char *get_hotel_id(HOTEL hotel);

/**
 * @brief Sets the hotel id
 * 
 * @param hotel - The hotel of type 'HOTEL'
 * @param id - The id of type 'char*'
*/
void set_hotel_id(HOTEL hotel, char *id);

/**
 * @brief Gets the hotel rating
 * 
 * @param hotel - The hotel of type 'HOTEL'
 * 
 * @return rating - The hotel rating of type 'double'
*/
double get_hotel_rating(HOTEL hotel);

/**
 * @brief Adds a rating to the hotel
 * 
 * @param hotel - The hotel of type 'HOTEL'
 * @param rating - The rating of type 'char*'
*/
void set_hotel_rating(HOTEL hotel, char *rating);

/**
 * @brief Gets the hotel reservation list
 * 
 * @param hotel - The hotel of type 'HOTEL'
 * 
 * @return reservation_list - The hotel reservation list of type 'GArray*'
*/
GArray *get_hotel_reservation_list(HOTEL hotel);

/**
 * @brief Adds a reservation to the hotel reservation list
 * 
 * @param hotel - The hotel of type 'HOTEL'
 * @param reservation_id - The reservation id of type 'char*'
*/
void set_hotel_reservation_list(HOTEL hotel, char *reservation_id);

/**
 * @brief Free's the hotel memory
 * 
 * @param data - The hotel of type 'gpointer'
*/
void hotel_destroy_function(gpointer data);

#endif