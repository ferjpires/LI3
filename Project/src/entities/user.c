#include <glib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "entities/user.h"

struct user
{
    char *id;
    char *name;
    int birth_date;
    char *sex;
    char *passport;
    char *country_code;
    int account_creation;
    char *account_status;
    int reservation_number;
    double total_spent;
    GArray *flight_list;
    GArray *reservation_list;
};

//                                               Create an user
// ===================================================================================================================

USER create_user(void)
{
    USER new_user = malloc(sizeof(struct user));
    new_user->id = NULL;
    new_user->name = NULL;
    new_user->birth_date = 0;
    new_user->sex = NULL;
    new_user->passport = NULL;
    new_user->country_code = NULL;
    new_user->account_creation = 0;
    new_user->account_status = NULL;
    new_user->reservation_number = 0;
    new_user->total_spent = 0;
    new_user->flight_list = g_array_new(FALSE, FALSE, sizeof(int));
    new_user->reservation_list = g_array_new(FALSE, FALSE, sizeof(int));

    return new_user;
}

//                                               ID
// ===================================================================================================================

char *get_user_id(USER user)
{
    return strdup(user->id);
}
void set_user_id(USER user, char *id)
{
    free(user->id); // release previous one
    user->id = strdup(id);
}

//                                               Name
// ===================================================================================================================

char *get_user_name(USER user)
{
    return strdup(user->name);
}
void set_user_name(USER user, char *name)
{
    free(user->name); // release previous one
    user->name = strdup(name);
}

//                                               Birth Date
// ===================================================================================================================

char *get_user_birth_date(USER user)
{
    char *date = malloc(20 * sizeof(char));
    sprintf(date, "%04d/%02d/%02d", user->birth_date / 10000, (user->birth_date % 10000) / 100, user->birth_date % 100);
    return date;
}
void set_user_birth_date(USER user, char *birth_date)
{
    int year, month, day;
    if (sscanf(birth_date, "%d/%d/%d", &year, &month, &day) == 3)
        user->birth_date = year * 10000 + month * 100 + day;
}

//                                               Sex
// ===================================================================================================================

char *get_user_sex(USER user)
{
    return strdup(user->sex);
}
void set_user_sex(USER user, char *sex)
{
    free(user->sex); // release previous one
    user->sex = strdup(sex);
}

//                                               Passport
// ===================================================================================================================

char *get_user_passport(USER user)
{
    return strdup(user->passport);
}
void set_user_passport(USER user, char *passport)
{
    free(user->passport); // release previous one
    user->passport = strdup(passport);
}

//                                               Country Code
// ===================================================================================================================

char *get_user_country_code(USER user)
{
    return strdup(user->country_code);
}
void set_user_country_code(USER user, char *country_code)
{
    free(user->country_code); // release previous one
    user->country_code = strdup(country_code);
}

//                                               Account Creation
// ===================================================================================================================

int get_user_account_creation(USER user)
{
    return user->account_creation;
}
void set_user_account_creation(USER user, char *account_creation)
{
    int year, month, day;
    if (sscanf(account_creation, "%d/%d/%d", &year, &month, &day) == 3)
        user->account_creation = year * 10000 + month * 100 + day;
}

//                                               Account Status
// ===================================================================================================================

char *get_user_account_status(USER user)
{
    return strdup(user->account_status);
}
void set_user_account_status(USER user, char *account_status)
{
    free(user->account_status);
    user->account_status = strdup(account_status);
}

//                                               Reservation Number
// ===================================================================================================================

int get_user_reservation_number(USER user)
{
    return user->reservation_number;
}
void set_user_reservation_number(USER user)
{
    user->reservation_number++;
}

//                                               Total Spent
// ===================================================================================================================

double get_user_total_spent(USER user)
{
    return user->total_spent;
}
void set_user_total_spent(USER user, double total_spent)
{
    user->total_spent += total_spent;
}

//                                               Flight List
// ===================================================================================================================

GArray *get_user_flight_list(USER user)
{
    return g_array_copy(user->flight_list);
}

void set_user_flight_list(USER user, char *flight_id)
{
    int id = atoi(flight_id);
    g_array_append_val(user->flight_list, id);
}

//                                               Reservation List
// ===================================================================================================================

GArray *get_user_reservation_list(USER user)
{
    return g_array_copy(user->reservation_list);
}

void set_user_reservation_list(USER user, char *reservation_id)
{
    char *numericPart = reservation_id + strlen("Book");
    int id = atoi(numericPart);
    g_array_append_val(user->reservation_list, id);
}

//                                               Free User
// ===================================================================================================================

void user_destroy_function(gpointer data)
{
    USER user = (USER)data;
    // Free dynamically allocated strings
    free(user->id);
    free(user->name);
    free(user->sex);
    free(user->passport);
    free(user->country_code);
    free(user->account_status);

    g_array_free(user->flight_list, TRUE);
    g_array_free(user->reservation_list, TRUE);

    // Free the user structure itself
    free(user);
}
