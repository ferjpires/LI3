#ifndef USER_STATS_H
#define USER_STATS_H

#include "entities/user.h"

/**
 * @brief Builds user statistics based on the provided parameters.
 *
 * This function constructs user statistics using the given user, total cost, and reservation ID.
 * The user statistics may include information such as total spending and associated reservation details.
 *
 * @param user The user for whom the statistics are being built of type 'USER'.
 * @param total_cost The total cost associated with the user's reservations of type 'double'.
 * @param reservation_id The ID of the reservation contributing to the statistics of type 'char*'.
 */
void build_user_stats(USER user, double total_cost, char *reservation_id);

/**
 * @brief Retrieves the age of a user.
 *
 * This function returns the age of the provided user. The age is calculated based on the user's
 * date of birth, and the result is an integer representing the user's age.
 *
 * @param user The user for whom the age is to be retrieved of type 'USER'.
 *
 * @return The age of the user as an integer.
 */
int get_user_age(USER user);

#endif