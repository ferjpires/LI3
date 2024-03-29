#ifndef OUTPUT_H
#define OUTPUT_H

/**
 * @brief Creates the output path to create a file
 *
 * @param line - The line of the input.txt we're reading of type 'int'
 *
 * @return path - The correct path to open and write the file
 */
char *create_output_path(int line);

/**
 * @brief Creates the output path to create a file
 *
 * @param line - The line of the input.txt we're reading of type 'int'
 *
 * @return path - The correct path to open and write the test file
 */
char *create_test_output_path(int line);

#endif