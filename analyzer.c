#include <stdio.h>
#include <string.h>

int main() {

    FILE *file;
    char line[256];

    int add_count = 0;
    int sub_count = 0;
    int and_count = 0;
    int or_count  = 0;
    int lw_count  = 0;
    int sw_count  = 0;
    int branch_count = 0;
    int jump_count = 0;

    file = fopen("sample.dump", "r");

    if (file == NULL) {
        printf("Could not open sample.dump\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {

        if (strstr(line, "\tadd ") || strstr(line, "\taddi") || strstr(line, "\taddw"))
            add_count++;

        if (strstr(line, "\tsub") || strstr(line, "\tsubw"))
            sub_count++;

        if (strstr(line, "\tand"))
            and_count++;

        if (strstr(line, "\tor "))
            or_count++;

        if (strstr(line, "\tlw"))
            lw_count++;

        if (strstr(line, "\tsw"))
            sw_count++;

        if (strstr(line, "\tbge") || strstr(line, "\tbeq") || strstr(line, "\tbne"))
            branch_count++;

        if (strstr(line, "\tj "))
            jump_count++;
    }

    fclose(file);

    // Simple energy model
    int energy =
        (add_count * 1) +
        (sub_count * 1) +
        (and_count * 1) +
        (or_count  * 1) +
        (lw_count  * 3) +
        (sw_count  * 3) +
        (branch_count * 2) +
        (jump_count * 2);

    printf("\nInstruction Count:\n");
    printf("ADD  : %d\n", add_count);
    printf("SUB  : %d\n", sub_count);
    printf("AND  : %d\n", and_count);
    printf("OR   : %d\n", or_count);
    printf("LW   : %d\n", lw_count);
    printf("SW   : %d\n", sw_count);
    printf("Branch : %d\n", branch_count);
    printf("Jump   : %d\n", jump_count);

    printf("\nEstimated Energy: %d units\n", energy);

    return 0;
}
