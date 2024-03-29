#include "queries/query9.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include <locale.h>

#include "catalogs/users_catalog.h"
#include "entities/user.h"


//============================== Auxiliar Functions ==============================
void input_corrector(char *entry)
{
    int i, j;
    int size = strlen(entry);
    j = 0;

    for (i = 0; i < size; i++)
    {
        if (entry[i] != '"')
        {
            entry[j] = entry[i];
            j++;
        }
    }
    entry[j] = '\0';
}

gboolean _verify_name_prefix(USER user, char *arguments)
{
    char *name = get_user_name(user);
    int result = strncmp(name, arguments, strlen(arguments)) == 0;
    g_free(name);
    return result;
}

//                                          Execution of query nine
//===================================================================================================================
void exec_query_nine(USERS_CATALOG users_catalog, char *arguments, FILE *output, int flag)
{
    // Inits
    char *input = strdup(arguments);
    GArray *list = g_array_new(FALSE, FALSE, sizeof(char *));

    input_corrector(input);

    g_array_append_val(list, input);
    iterate_users(users_catalog, add_user_to_list, list);
    g_array_remove_index(list, 0);

    char *name;
    USER user_a;
    char *id;

    order_users_array_by_name(list, users_catalog);

    // Flag
    if (flag == 1)
    {
        for (int i = 0; i < list->len; i++)
        {
            id = g_array_index(list, char *, i);
            name = get_user_name(lookup_user(users_catalog, id));
            fprintf(output, "--- %d ---\n", i + 1);
            fprintf(output, "id: %s\n", id);
            if (i == list->len - 1)
                fprintf(output, "name: %s\n", name);
            else
                fprintf(output, "name: %s\n\n", name);
            g_free(name);
            name = NULL;
            g_free(id);
            id = NULL;
        }
    }
    // Not Flag
    else
    {
        for (int i = 0; i < list->len; i++)
        {
            id = g_array_index(list, char *, i);
            user_a = lookup_user(users_catalog, id);
            name = get_user_name(user_a);
            fprintf(output, "%s;%s\n", id, name);
            g_free(name);
            name = NULL;
            g_free(id);
            id = NULL;
        }
    }
    free(input);
    g_array_free(list, TRUE);
}

void add_user_to_list(USER user, void *user_data)
{
    GArray *list = user_data;
    char *status = get_user_account_status(user);
    if (_verify_name_prefix(user, g_array_index(list, gchar *, 0)) && strcasecmp(status, "active") == 0)
    {
        char *id = get_user_id(user);
        g_array_append_vals(list, &id, 1);
    }
    g_free(status);
    status = NULL;
}