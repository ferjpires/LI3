#include "queries/query_manager.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "queries/query1.h"
#include "queries/query2.h"
#include "queries/query3.h"
#include "queries/query4.h"
#include "queries/query5.h"
#include "queries/query6.h"
#include "queries/query7.h"
#include "queries/query8.h"
#include "queries/query9.h"
#include "queries/query10.h"
#include "utils/output.h"

void process_line(char *line, int input_line, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog,
                  RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog,
                  METRICS_CATALOG metrics)
{
   char *query, *args;

   query = strsep(&line, " "); // setting the query todo

   args = (line != NULL) ? line : ""; // setting the arguments of the query

   char *path = create_output_path(input_line); // creating output path

   FILE *output = fopen(path, "w"); // creating output file
   if (output == NULL)              // checking if file correctly opened
      printf("Error opening file: query manager in line %d\n", input_line);

   // knowing which query needs to be executed
   if (strcmp(query, "1") == 0)
      exec_query_one(users_catalog, flights_catalog, reservations_catalog, args, output, 0);
   else if (strcmp(query, "1F") == 0)
      exec_query_one(users_catalog, flights_catalog, reservations_catalog, args, output, 1);
   else if (strcmp(query, "2") == 0)
      exec_query_two(users_catalog, flights_catalog, reservations_catalog, args, output, 0);
   else if (strcmp(query, "2F") == 0)
      exec_query_two(users_catalog, flights_catalog, reservations_catalog, args, output, 1);
   else if (strcmp(query, "3") == 0)
      exec_query_three(hotels_catalog, args, output, 0);
   else if (strcmp(query, "3F") == 0)
      exec_query_three(hotels_catalog, args, output, 1);
   else if (strcmp(query, "4") == 0)
      exec_query_four(hotels_catalog, reservations_catalog, args, output, 0);
   else if (strcmp(query, "4F") == 0)
      exec_query_four(hotels_catalog, reservations_catalog, args, output, 1);
   else if (strcmp(query, "5") == 0)
      exec_query_five(airports_catalog, flights_catalog, args, output, 0);
   else if (strcmp(query, "5F") == 0)
      exec_query_five(airports_catalog, flights_catalog, args, output, 1);
   else if (strcmp(query, "6") == 0)
      exec_query_six(airports_catalog, args, output, 0);
   else if (strcmp(query, "6F") == 0)
      exec_query_six(airports_catalog, args, output, 1);
   else if (strcmp(query, "7") == 0)
      exec_query_seven(flights_catalog, airports_catalog, args, output, 0);
   else if (strcmp(query, "7F") == 0)
      exec_query_seven(flights_catalog, airports_catalog, args, output, 1);
   else if (strcmp(query, "8") == 0)
      exec_query_eight(hotels_catalog, reservations_catalog, args, output, 0);
   else if (strcmp(query, "8F") == 0)
      exec_query_eight(hotels_catalog, reservations_catalog, args, output, 1);
   else if (strcmp(query, "9") == 0)
      exec_query_nine(users_catalog, args, output, 0);
   else if (strcmp(query, "9F") == 0)
      exec_query_nine(users_catalog, args, output, 1);
   else if (strcmp(query, "10") == 0)
      exec_query_ten(metrics, args, output, 0);
   else if (strcmp(query, "10F") == 0)
      exec_query_ten(metrics, args, output, 1);

   fclose(output); // Closing the output file
   free(path);     // Freeing the output path
}

void read_file(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
               AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file, METRICS_CATALOG metrics)
{
   int input_line = 1;
   char line[1024];
   while (fgets(line, sizeof(line), queries_file) != NULL)
   {
      line[strcspn(line, "\n")] = '\0';
      process_line(line, input_line, users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, metrics);
      input_line++;
   }
}

void query_manager(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                   AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file, METRICS_CATALOG metrics)
{
   read_file(users_catalog, flights_catalog, reservations_catalog, airports_catalog, hotels_catalog, queries_file, metrics);
}
