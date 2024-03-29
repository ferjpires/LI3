#include "data_manager/user_stats.h"

#include <stdio.h>

#include "entities/user.h"

//                                               Build User Stats
// ===================================================================================================================

void build_user_stats(USER user, double total_cost, char *reservation_id)
{
    set_user_total_spent(user, total_cost);
    set_user_reservation_number(user);
    set_user_reservation_list(user, reservation_id);
}

//                                               User Age
// ===================================================================================================================

int get_user_age(USER user)
{
    int age = 0;
    char *birth_date = get_user_birth_date(user);
    char *current_date = "2023/10/01";

    struct tm birth_date_tm, current_tm;
    sscanf(birth_date, "%d/%d/%d", &birth_date_tm.tm_year, &birth_date_tm.tm_mon, &birth_date_tm.tm_mday);
    sscanf(current_date, "%d/%d/%d", &current_tm.tm_year, &current_tm.tm_mon, &current_tm.tm_mday);

    // age difference
    age = current_tm.tm_year - birth_date_tm.tm_year;

    // adjusting based on month and day
    if (current_tm.tm_mon < birth_date_tm.tm_mon || (current_tm.tm_mon == birth_date_tm.tm_mon && current_tm.tm_mday < birth_date_tm.tm_mday))
    {
        age--;
    }
    g_free(birth_date);
    return age;
}
