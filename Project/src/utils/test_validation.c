#include "utils/test_validation.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include "utils/output.h"

void check_files(char *expected_outputs, int input_line, int *correct, int *missing_line, int *missing_query)
{
    char *output_path = create_output_path(input_line);
    char *test_output_path = create_test_output_path(input_line);

    // Opens expected output
    size_t length = strlen(expected_outputs) + strlen(test_output_path) + 2;
    char *path = malloc((length) * sizeof(char));
    if (path == NULL)
    {
        printf("Memory allocation failed for file: users.csv\n");
        return;
    }
    snprintf(path, length, "%s/%s", expected_outputs, test_output_path);

    FILE *expected_output = fopen(path, "r");
    if (expected_output == NULL)
        perror("Error opening file: expected output"); // File opening failed
    free(path);

    FILE *output = fopen(output_path, "r");
    if (output == NULL)
        perror("Error opening file: output"); // File opening failed

    free(output_path);
    free(test_output_path);

    char line_output[1024], line_expected[1024];
    int line = 0;

    if (feof(output) && feof(expected_output))
    {
        printf("Ambos os arquivos estão vazios.\n");
    }

    while (1)
    {

        // Ler linhas de ambos os arquivos
        fgets(line_output, sizeof(line_output), output);
        fgets(line_expected, sizeof(line_expected), expected_output);

        line_output[strcspn(line_output, "\n")] = '\0';
        line_expected[strcspn(line_expected, "\n")] = '\0';

        // Verificar se pelo menos um dos arquivos chegou ao final
        if (feof(output) && feof(expected_output))
        {
            // printf("\033[0;42m[VALID TEST]\033[0m\n");
            break;
        }
        else if (feof(output) || feof(expected_output))
        {
            // printf("\033[0;41m[NOT VALID TEST] Different File Size\033[0m\n");
            *correct = 0;
            *missing_line = -1;
            *missing_query = input_line;
            break;
        }

        line++;

        if (strcmp(line_output, line_expected) != 0)
        {
            // printf("\033[0;41m[NOT VALID TEST] Line: %d\033[0m\n", line);
            *correct = 0;
            *missing_line = line;
            *missing_query = input_line;
            break;
        }
    }

    fclose(expected_output);
    fclose(output);
}