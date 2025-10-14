#include <stdio.h>
#include <stdlib.h>

void print_cpu_info() {
    printf("----------------\n");

    char *output = malloc(1000*sizeof(char)); 
    if (!output) {
        printf("Memory allocation failed\n");
        return;
    }

    FILE *fp = popen("lscpu", "r");
    if (!fp) {
        printf("Could not run lscpu command\n");
        free(output);
        return;
    }

    fread(output, 1, 1000*sizeof(char)-1, fp);
    output[1000*sizeof(char)] = '\0';

    printf("%s\n", output);

    pclose(fp);
    free(output);
}
