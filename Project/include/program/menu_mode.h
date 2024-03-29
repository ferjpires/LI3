#ifndef MENU_MODE_H
#define MENU_MODE_H

#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "stats/metrics_catalog.h"

/**
 * @brief Gets user input for a file path
 *
 * @param path Buffer to store the entered file path
 * @param i Index to keep track of the current position in the file path buffer
 * @param x Start position in cols
 * @param y Start position in lines
 *
 * @return The number of characters entered or -1 if the Escape key is pressed
 */
int get_user_input(char *path, int i, int y, int x);

/**
 * @brief Deletes user input
 *
 * @param path Buffer containing the user input
 * @param i Index indicating the current position in the input buffer
 * @param x Start position in cols
 * @param y Start position in lines
 */
void delete_user_input(char *path, int i, int y, int x);

/**
 * @brief Draws a box without borders in a specified window.
 *
 * @param box_starty Y-coordinate of the top-left corner of the box
 * @param box_startx X-coordinate of the top-left corner of the box
 * @param box_height Height of the box
 * @param box_width Width of the box
 */
void box_draw(int box_starty, int box_startx, int box_height, int box_width);

/**
 * @brief Cleans a line in the ncurses window.
 *
 * @param y Y-coordinate of the line to be cleaned
 */
void clean_line(int y);

/**
 * @brief Prints text centered in the ncurses window.
 *
 * @param text Text to be printed
 * @param starty Y-coordinate of the starting position for the text
 * @param highlight Flag indicating whether to highlight the text (1 for highlight, 0 for regular)
 */
int center_print(char *text, int starty, int highlight);

/**
 * @brief Writes the main instructions of screen 3 (Query write instructions)
 *
 * @param query Query number representing the user's choice
 */
void exec_asked(int query);

/**
 * @brief Prints the results in the terminal
 *
 * @param numPedidos Number of file
 */
int print_result(int numPedidos);

/**
 * @brief Writes the main instructions of screen 2 (Query choice)
 *
 * @param query Query number representing the user's choice
 */
void query_choice(int query);

/**
 * @brief Verifies query input
 *
 * @param query Query number representing the user's choice
 * @param query_input Input of the user
 */
int verify_input(int query, char *query_input);

/**
 * @brief Executes the menu mode and interacts with the user.
 *
 * @param users_catalog Catalog of users
 * @param flights_catalog Catalog of flights
 * @param reservations_catalog Catalog of reservations
 * @param airport_ordered_list Ordered list of airports
 */
void exec_menu_mode(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, METRICS_CATALOG metrics);

#endif