#ifndef METRIC_H
#define METRIC_H

#include <glib.h>
#include <stdbool.h>

typedef struct metric *METRIC;

/**
 * @brief Creates a new metric
 *
 * @return new_metric - The new metric of type 'METRIC'
 */
METRIC create_metric(void);

/**
 * @brief Destroys a metric instance.
 *
 * This function deallocates the memory associated with a metric instance, including
 * any resources it may have acquired. It is important to call this function when
 * a metric is no longer needed to prevent memory leaks.
 *
 * @param data A pointer to the metric instance to be destroyed.
 */
void metric_destroy_function(gpointer data);

/**
 * @brief Retrieves the daily existence status from a metric.
 *
 * This function returns the daily existence status from the provided metric.
 * The daily existence status indicates whether the metric has been set for the current day.
 *
 * @param metric The metric instance.
 *
 * @return A boolean value: true if the daily existence has been set, false otherwise.
 */
bool get_daily_existence(METRIC metric);

/**
 * @brief Sets the daily existence status in a metric.
 *
 * This function sets the daily existence status in the provided metric, indicating
 * that the metric has been recorded for the current day.
 *
 * @param metric The metric instance.
 */
void set_daily_existence(METRIC metric);

/**
 * @brief Retrieves the total number of users from a metric.
 *
 * This function returns the total number of users recorded in the provided metric.
 *
 * @param metric The metric instance.
 *
 * @return An integer representing the total number of users.
 */
int get_total_users(METRIC metric);

/**
 * @brief Sets the total number of users in a metric.
 *
 * This function sets the total number of users in the provided metric.
 *
 * @param metric The metric instance.
 */
void set_total_users(METRIC metric);

/**
 * @brief Retrieves the total number of flights from a metric.
 *
 * This function returns the total number of flights recorded in the provided metric.
 *
 * @param metric The metric instance.
 *
 * @return An integer representing the total number of flights.
 */
int get_total_flights(METRIC metric);

/**
 * @brief Sets the total number of flights in a metric.
 *
 * This function sets the total number of flights in the provided metric.
 *
 * @param metric The metric instance.
 */
void set_total_flights(METRIC metric);

/**
 * @brief Retrieves the total number of passengers from a metric.
 *
 * This function returns the total number of passengers recorded in the provided metric.
 *
 * @param metric The metric instance.
 *
 * @return An integer representing the total number of passengers.
 */
int get_total_passengers(METRIC metric);

/**
 * @brief Sets the total number of passengers in a metric.
 *
 * This function sets the total number of passengers in the provided metric.
 *
 * @param metric The metric instance.
 */
void set_total_passengers(METRIC metric);

/**
 * @brief Retrieves the total number of unique passengers from a metric.
 *
 * This function returns the total number of unique passengers recorded in the provided metric.
 *
 * @param metric The metric instance.
 *
 * @return An integer representing the total number of unique passengers.
 */
int get_unique_passengers(METRIC metric);

/**
 * @brief Sets the total number of unique passengers in a metric.
 *
 * This function sets the total number of unique passengers in the provided metric.
 *
 * @param metric The metric instance.
 */
void set_total_unique_passengers(METRIC metric);

/**
 * @brief Retrieves the total number of reservations from a metric.
 *
 * This function returns the total number of reservations recorded in the provided metric.
 *
 * @param metric The metric instance.
 *
 * @return An integer representing the total number of reservations.
 */
int get_total_reservations(METRIC metric);

/**
 * @brief Sets the total number of reservations in a metric.
 *
 * This function sets the total number of reservations in the provided metric.
 *
 * @param metric The metric instance.
 */
void set_total_reservations(METRIC metric);

/**
 * @brief Retrieves the size of the unique users list from a metric.
 *
 * This function returns the size of the unique users list recorded in the provided metric.
 *
 * @param metric The metric instance.
 *
 * @return An integer representing the size of the unique users list.
 */
int get_unique_users_size(METRIC metric);

/**
 * @brief Sets the unique users list in a metric.
 *
 * This function sets the unique users list in the provided metric.
 *
 * @param metric The metric instance.
 * @param id The ID of the unique user to be added to the list.
 */
void set_unique_users(METRIC metric, char *id);

#endif