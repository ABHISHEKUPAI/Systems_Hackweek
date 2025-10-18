#include <stdio.h>
#include <stdlib.h>

void print_uptime() {

    char* output = malloc(500 * sizeof(char));

    FILE *fp = popen("uptime -p", "r");
    if (!fp) {
        printf("Could not run uptime command\n");
        free(output);
        return;
    }

    fread(output, 1, 500 * sizeof(char) - 1, fp);
    output[500 * sizeof(char) - 1] = '\0';

    printf("%s\n", output);

    pclose(fp);
    free(output);
}
