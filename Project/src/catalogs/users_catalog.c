#include <glib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>

#include "entities/user.h"
#include "catalogs/users_catalog.h"

struct users_catalog
{
    GHashTable *users;
};

//                                               Create Users Catalog
// ===================================================================================================================
USERS_CATALOG create_users_catalog()
{
    USERS_CATALOG new_catalog = malloc(sizeof(struct users_catalog));
    new_catalog->users = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)user_destroy_function);
    return new_catalog;
}

//                                               Build an user
// ===================================================================================================================

void build_user(char **user_params, USERS_CATALOG catalog)
{
    USER user = create_user();

    set_user_id(user, user_params[0]);
    set_user_name(user, user_params[1]);
    set_user_birth_date(user, user_params[4]);
    set_user_sex(user, user_params[5]);
    set_user_passport(user, user_params[6]);
    set_user_country_code(user, user_params[7]);
    set_user_account_creation(user, user_params[9]);
    set_user_account_status(user, user_params[11]);

    // to insert we give the hashtable which we're going to insert in, the struct to insert and the key (we pass the string and then change it)
    insert_user(catalog, user, user_params[0]);
}

//                                               Insert an user
// ===================================================================================================================

void insert_user(USERS_CATALOG catalog, USER user, gpointer key)
{
    char *id_dup = g_strdup(key);
    g_hash_table_insert(catalog->users, id_dup, GINT_TO_POINTER(user));
}

//                                               Lookup User
// ===================================================================================================================

USER lookup_user(USERS_CATALOG catalog, char *user_id)
{
    return g_hash_table_lookup(catalog->users, user_id);
}

//                                               Contains User
// ===================================================================================================================

int contains_user(USERS_CATALOG catalog, char *key)
{
    if (g_hash_table_contains(catalog->users, key))
        return 1;
    else
        return 0;
}

//                                               Destroy Catalog
// ===================================================================================================================

void free_users_catalog(USERS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->users);
    free(catalog);
}

//                                               Iterate the HashTable
// ===================================================================================================================

void iterate_users(USERS_CATALOG catalog, UserIteratorFunc iterator_func, void *user_data)
{
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->users);

    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        USER user = value;
        iterator_func(user, user_data);
    }
}

//                                               Order Arrays of Users
// ===================================================================================================================

void order_users_array_by_name(GArray *user_array, USERS_CATALOG catalog)
{
    g_array_sort_with_data(user_array, sort_user_array_by_name, catalog);
}

gint sort_user_array_by_name(gconstpointer a, gconstpointer b, gpointer user_data)
{
    setlocale(LC_COLLATE, "en_US.UTF-8");

    USERS_CATALOG catalog = (USERS_CATALOG)user_data;
    GHashTable *users_table = catalog->users;

    gchar *id_a = *((gchar **)a);
    gchar *id_b = *((gchar **)b);
    USER user1 = g_hash_table_lookup(users_table, id_a);
    USER user2 = g_hash_table_lookup(users_table, id_b);
    char *str1 = get_user_name(user1);
    char *str2 = get_user_name(user2);
    int value = strcoll(str1, str2);
    g_free(str1);
    g_free(str2);
    if (value != 0)
        return value;
    else
    {
        return strcoll(id_a, id_b);
    }
}
