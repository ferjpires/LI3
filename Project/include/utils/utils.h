#ifndef UTILS_H
#define UTILS_H

#include <glib.h>
#include <stdio.h>

/**
 * @brief Opens a CSV file given a path and filename.
 *
 * @param path Path to the directory containing the CSV file
 * @param csv Filename of the CSV file
 *
 * @return A pointer to the opened FILE structure, or NULL if an error occurs
 */
FILE *open_csv(char *path, char *csv);

/**
 * @brief Function used to compare dates and if dates are equal compare ids
 *
 * @param date_1 - Pointer to date_1
 * @param date_2 - Pointer to date_2
 * @param id_1- Pointer to id_1
 * @param id_2 - Pointer to id_1
 *
 * @return int - returns a int : >0 if date_1 latest then date_2; <0 if date_2 latest then date_1; if dates are equal returns a int : >0 if id_2>id_1; <0 if id_1>id_2; ids cant be equal
 */
int date_cmp(char *date_1, char *date_2, char *id_1, char *id_2);

/**
 * @brief Compares two elements in a delay list for sorting.
 *
 * This function is used as a comparison function for sorting a delay list. It compares
 * the delays of two elements and returns an integer indicating their order.
 *
 * @param a A pointer to the first delay element.
 * @param b A pointer to the second delay element.
 *
 * @return An integer value: >0 if the delay of 'a' is greater than the delay of 'b',
 *         <0 if the delay of 'b' is greater than the delay of 'a', and 0 if they are equal.
 */
gint sort_delay_list(gconstpointer a, gconstpointer b);

/**
 * @brief Compares two elements in a reservation list for sorting.
 *
 * This function is used as a comparison function for sorting a reservation list. It
 * compares reservations based on specified criteria and returns an integer indicating
 * their order.
 *
 * @param a A pointer to the first reservation element.
 * @param b A pointer to the second reservation element.
 * @param user_data Additional user data if needed for comparison.
 *
 * @return An integer value: >0 if 'a' should come after 'b', <0 if 'a' should come
 *         before 'b', and 0 if they are considered equal.
 */
gint sort_reservation_list2(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Compares two elements in a flight array for sorting based on dates.
 *
 * This function is used as a comparison function for sorting a flight array based on dates.
 * It compares flights based on specified criteria and returns an integer indicating their order.
 *
 * @param a A pointer to the first flight element.
 * @param b A pointer to the second flight element.
 * @param user_data Additional user data if needed for comparison.
 *
 * @return An integer value: >0 if the date of 'a' is later than the date of 'b',
 *         <0 if the date of 'a' is earlier than the date of 'b', and 0 if they are equal.
 */
gint sort_flight_array_by_dates2(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Compares two elements in a flight array for sorting based on dates.
 *
 * This function is used as a comparison function for sorting a flight array based on dates.
 * It compares flights based on specified criteria and returns an integer indicating their order.
 *
 * @param a A pointer to the first flight element.
 * @param b A pointer to the second flight element.
 * @param user_data Additional user data if needed for comparison.
 *
 * @return An integer value: >0 if the date of 'a' is later than the date of 'b',
 *         <0 if the date of 'a' is earlier than the date of 'b', and 0 if they are equal.
 */
gint sort_reservation_list(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Compares two elements in a flight array for sorting based on dates.
 *
 * This function is used as a comparison function for sorting a flight array based on dates.
 * It compares flights based on specified criteria and returns an integer indicating their order.
 *
 * @param a A pointer to the first flight element.
 * @param b A pointer to the second flight element.
 * @param user_data Additional user data if needed for comparison.
 *
 * @return An integer value: >0 if the date of 'a' is later than the date of 'b',
 *         <0 if the date of 'a' is earlier than the date of 'b', and 0 if they are equal.
 */
gint sort_flight_array_by_dates3(gconstpointer a, gconstpointer b, gpointer user_data);

#endif