#ifndef USER_H
#define USER_H

#include <glib.h>

typedef struct user *USER;

/**
 * @brief Creates a new user
 *
 * @return new_user - The new user of type 'USER'
 */
USER create_user(void);

/**
 * @brief Sets the user id
 *
 * @param user - The user of type 'USER'
 * @param id - The id of type 'char*'
 */
void set_user_id(USER user, char *id);

/**
 * @brief Gets the user id
 *
 * @param user - The user of type 'USER'
 *
 * @return id - The user id of type 'char*'
 */
char *get_user_id(USER user);

/**
 * @brief Sets the user name
 *
 * @param user - The user of type 'USER'
 * @param name - The name of type 'char*'
 */
void set_user_name(USER user, char *name);

/**
 * @brief Gets the user name
 *
 * @param user - The user of type 'USER'
 *
 * @return name - The user name of type 'char*'
 */
char *get_user_name(USER user);

/**
 * @brief Sets the user birth date
 *
 * @param user - The user of type 'USER'
 * @param birth_date - The birth date of type 'char*'
 */
void set_user_birth_date(USER user, char *birth_date);

/**
 * @brief Gets the user birth date
 *
 * @param user - The user of type 'USER'
 *
 * @return birth date - The user birth date of type 'char*'
 */
char *get_user_birth_date(USER user);

/**
 * @brief Sets the user sex
 *
 * @param user - The user of type 'USER'
 * @param sex - The sex of type 'char*'
 */
void set_user_sex(USER user, char *sex);

/**
 * @brief Gets the user sex
 *
 * @param user - The user of type 'USER'
 *
 * @return sex - The user sex of type 'char*'
 */
char *get_user_sex(USER user);

/**
 * @brief Sets the user passport
 *
 * @param user - The user of type 'USER'
 * @param passport - The passport of type 'char*'
 */
void set_user_passport(USER user, char *passport);

/**
 * @brief Gets the user passport
 *
 * @param user - The user of type 'USER'
 *
 * @return passport - The user passport of type 'char*'
 */
char *get_user_passport(USER user);

/**
 * @brief Sets the user country code
 *
 * @param user - The user of type 'USER'
 * @param country_code - The country code of type 'char*'
 */
void set_user_country_code(USER user, char *country_code);

/**
 * @brief Gets the user country code
 *
 * @param user - The user of type 'USER'
 *
 * @return country code - The user country code of type 'char*'
 */
char *get_user_country_code(USER user);

/**
 * @brief Sets the user account creation
 *
 * @param user - The user of type 'USER'
 * @param account_creation - The account creation of type 'char*'
 */
void set_user_account_creation(USER user, char *account_creation);

/**
 * @brief Gets the user account creation
 *
 * @param user - The user of type 'USER'
 *
 * @return account creation - The user account creation of type 'int'
 */
int get_user_account_creation(USER user);

/**
 * @brief Sets the user account status
 *
 * @param user - The user of type 'USER'
 * @param account_status - The account status of type 'char*'
 */
void set_user_account_status(USER user, char *account_status);

/**
 * @brief Gets the user account status
 *
 * @param user - The user of type 'USER'
 *
 * @return account status - The user account status of type 'char*'
 */
char *get_user_account_status(USER user);

/**
 * @brief Gets the user reservation number
 *
 * @param user - The user of type 'USER'
 *
 * @return reservation number - The user reservation number of type 'int'
 */
int get_user_reservation_number(USER user);

/**
 * @brief Sets the user reservation number
 *
 * @param user - The user of type 'USER'
 *
 */
void set_user_reservation_number(USER user);
/**
 * @brief Gets the user total spent
 *
 * @param user - The user of type 'USER'
 *
 * @return total spent - The user total spent of type 'double'
 */
double get_user_total_spent(USER user);

/**
 * @brief Sets the user total spent
 *
 * @param user - The user of type 'USER'
 * @param total_spent - The total spent of type 'double'
 */
void set_user_total_spent(USER user, double total_spent);

/**
 * @brief Gets the user in order flight list
 *
 * @param user - The user of type 'USER'
 *
 * @return flight_list - The user in order flight list of type 'GArray*'
 */
GArray *get_user_flight_list(USER user);

/**
 * @brief Sets the user in order flight list
 *
 * @param user - The user of type 'USER'
 *
 * @return reservation number - The user reservation number of type 'int'
 */
void set_user_flight_list(USER user, gchar *flight_id);

/**
 * @brief Gets the user reservation number
 *
 * @param user - The user of type 'USER'
 *
 * @return reservation number - The user reservation number of type 'int'
 */
GArray *get_user_reservation_list(USER user);

/**
 * @brief Sets the user in order reservation list
 *
 * @param user - The user of type 'USER'
 *
 */
void set_user_reservation_list(USER user, char *reservation_id);

/**
 * @brief Free's the user memory
 *
 * @param data - The user of type 'gpointer'
 */
void user_destroy_function(gpointer data);

/**
 * @brief Free's the user in order flight list memory
 *
 * @param user - The user of type 'USER'
 */
void free_user_flight_list(USER user);

/**
 * @brief Free's the user in order reservation list memory
 *
 * @param user - The user of type 'USER'
 */
void free_user_reservation_list(USER user);

#endif