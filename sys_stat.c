#include <stdio.h>
#include "cpu.h"
#include "memory.h"
#include "uptime.h"

int main() {
    printf("---------- SYSTEM STATS --------\n");
    int limit = 25;
    while(limit>0){
        print_cpu_info();
        print_memory_info();
        print_uptime();
        printf("--------------");
        limit++;
    }
}
