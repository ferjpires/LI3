#ifndef TEST_VALIDATION_H
#define TEST_VALIDATION_H

/**
 * @brief Function used to check if the output file is correct
 *
 * @param expected_outputs - The expected outputs of type 'char*'
 * @param input_line - The line of the input.txt we're reading of type 'int'
 * @param correct - The number of correct outputs of type 'int*'
 * @param missing_line - The number of missing lines of type 'int*'
 * @param missing_query - The number of missing queries of type 'int*'
 */
void check_files(char *expected_outputs, int input_line, int *correct, int *missing_line, int *missing_query);

#endif