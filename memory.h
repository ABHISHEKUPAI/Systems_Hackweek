#include <stdio.h>
#include <stdlib.h>

void print_memory_info() {
    printf("--------------\n");

    char *output = malloc(1000 * sizeof(char));
    if (!output) {
        printf("Memory allocation failed\n");
        return;
    }

    FILE *fp = popen("free -m", "r");
    if (!fp) {
        printf("Could not run free command\n");
        free(output);
        return;
    }

    fread(output, 1, 1000 * sizeof(char) - 1, fp);
    output[1000 * sizeof(char) - 1] = '\0';

    printf("%s\n", output);

    pclose(fp);
    free(output);
}
