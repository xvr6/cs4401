#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void recalibration() {
    char buffer[64];
    FILE *fp;

    printf("Code flow successfully changed, navigation recalibrated.\n");
    printf("New dwarf planet detected! Recommend course correction...\n");

    fp = fopen("./flag.txt", "r");
    fgets(buffer, 64, (FILE *)fp);
    printf("flag: %s\n", buffer);
    exit(0);
}

int main(int argc, char **argv) {
    volatile int (*fp)();
    char buffer[{{buffsize}}];

    fp = 0;

    gets(buffer);

    if (fp) {
        printf("Calling function pointer, jumping to %p\n", fp);
        fp();
    }
}