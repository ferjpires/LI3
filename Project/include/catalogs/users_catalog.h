#ifndef USERS_CATALOG_H
#define USERS_CATALOG_H

#include <glib.h>
#include "entities/user.h"

typedef struct users_catalog *USERS_CATALOG;

typedef void (*UserIteratorFunc)(USER user, void *user_data);

/**
 * @brief Creates space in memory for the Users Catalog that includes an HashTable
 *
 */
USERS_CATALOG create_users_catalog();

/**
 * @brief Builds the User with a 2D string array parameters
 * @brief This function is used to simplify the construction of an User
 * @brief We call it every time we parse a line from the csv file
 *        It creates space in memory using the create_user function and it also calls
 *        the insert_user function to put the formed User on the catalog
 *
 * @param user_params - The user parameters of type 'char**'
 * @param users - The users catalog of type 'USERS_CATALOG'
 */
void build_user(char **user_params, USERS_CATALOG catalog);

/**
 * @brief Inserts the User in the users HashTable with user_id as the key
 * @brief This function is used inside the build_user function and it acts as middle man to insert
 *        the User on the catalog
 *
 * @param catalog - The users catalog of type 'USERS_CATALOG'
 * @param user - The structured user of type 'USER'
 * @param key - The user id of type 'gpointer'
 */
void insert_user(USERS_CATALOG catalog, USER user, gpointer key);

/**
 * @brief Looks up an User in the users catalog passing user_id as the key
 * @brief This function is used every time we need to search for an user in the catalog
 *
 * @param catalog - The users catalog of type 'USERS_CATALOG'
 * @param user_id - The user id of type 'char*'
 */
USER lookup_user(USERS_CATALOG catalog, char *user_id);

/**
 * @brief Checks if the HashTable in the catalog contains the given key
 * @brief This function is used every time we need to search if an user exists in the catalog
 *
 * @param catalog - The users catalog of type 'USERS_CATALOG'
 * @param key - The key of type 'char*'
 */
int contains_user(USERS_CATALOG catalog, char *key);

/**
 * @brief Destroys the catalog freeing all the memory
 *
 * @param catalog - The users catalog of type 'USERS_CATALOG'
 */
void free_users_catalog(USERS_CATALOG catalog);

/**
 * @brief Iterates through the users table
 *        We use this to iterate through the table to get some data to perform queries
 *
 * @param catalog - The user catalog of type 'USERS_CATALOG'
 * @param iterator_func - The function to apply to every user on the catalog of type 'UserIteratorFunc'
 * @param user_data - The extra data we pass to the function that we need for it to work of type 'void*'
 */
void iterate_users(USERS_CATALOG catalog, UserIteratorFunc iterator_func, void *user_data);

/**
 * @brief Orders an array of user names
 *        We use this function every time we need to order an array filled with user names
 *
 * @param user_array - The array with user names of type 'GArray'
 * @param catalog - The users catalog of type 'USERS_CATALOG'
 */
void order_users_array_by_name(GArray *user_array, USERS_CATALOG catalog);

/**
 * @brief Auxiliary function to sort the GArray by name and if they are tied by ID's
 *
 * @param a - The ID passed by the g_array_sort function of type 'gconstpointer'
 * @param b - The ID passed by the g_array_sort function of type 'gconstpointer'
 * @param user_data - The users catalog passed to go get the dates of each ID of type 'gpointer'
 */
gint sort_user_array_by_name(gconstpointer a, gconstpointer b, gpointer user_data);

#endif