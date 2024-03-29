#ifndef QUERY9_H
#define QUERY9_H

#include <stdio.h>
#include <glib.h>

#include "catalogs/users_catalog.h"
#include "entities/user.h"

/**
 * @brief Removes the character '"' from a string to validate arguments.
 *
 * This function takes a string as input and removes any occurrences of the character '"' from it. It is specifically
 * designed to validate and correct arguments passed to a query by removing unwanted characters.
 *
 * @param entry - The string to validate and remove the character '"' (type: char*).
 */
void input_corrector(char *entry);

/**
 * @brief Verifies if the name of a user starts with a given prefix.
 *
 * This function checks whether the name of a given user starts with the specified prefix. It is used as a callback
 * function, typically with the g_hash_table_foreach function, to filter users based on a name prefix.
 *
 * @param user - The user to be checked (type: USER).
 * @param arguments - The prefix to be compared with the user's name (type: char*).
 *
 * @return gboolean - Returns TRUE if the name of the user starts with the given prefix, FALSE otherwise.
 */
gboolean _verify_name_prefix(USER user, char *arguments);

/**
 * @brief Executes query 9 and writes the results to the output file.
 *
 * This function executes query 9 based on the provided arguments, utilizing the users catalog to retrieve relevant
 * information. The results, specifically user names that match the given prefix, are then written to the output file.
 * An additional flag is used for query-specific formatting.
 *
 * @param users_catalog - The users catalog containing user information (type: USERS_CATALOG).
 * @param arguments - The prefix to be compared with user names (type: char*).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void exec_query_nine(USERS_CATALOG users_catalog, char *arguments, FILE *output, int flag);

/**
 * @brief Iterates through every user and adds user names containing the given prefix to the GArray.
 *
 * This function is used as a callback to iterate through every user in the system. It adds user names that contain
 * the specified prefix to a GArray. The GArray is typically used to accumulate the results of the query.
 *
 * @param user - The user being checked (type: USER).
 * @param user_data - The GArray to which user names are added (type: void*).
 */
void add_user_to_list(USER user, void *user_data);

#endif