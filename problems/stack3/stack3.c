#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void relay_init() {
    char buffer[64];
    FILE *fp;

    printf("Code flow successfully changed, relays restored.\n");
    printf("Scanning for messages...\n");

    fp = fopen("./flag.txt", "r");
    fgets(buffer, 64, (FILE *)fp);
    printf("flag: %s\n", buffer);
    exit(0);
}

int main(int argc, char **argv) {
    char buffer[{{buffsize}}];

    gets(buffer);
}
