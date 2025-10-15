#include <stdio.h>
#include <stdlib.h>

void print_memory_info() {

    char *output = malloc(1000 * sizeof(char));
    FILE *fp = popen("free -m", "r");

    fread(output, 1, 1000 * sizeof(char) - 1, fp);
    output[1000 * sizeof(char) - 1] = '\0';

    printf("%s\n", output);

    pclose(fp);
    free(output);
}
