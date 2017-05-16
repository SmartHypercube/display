#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fprog, *fimg;
    char c;
    if (argc != 4 || strcmp(argv[2], "as") != 0) {
        fprintf(stderr, "Usage: display <PROGRAM> as <IMAGE>\n");
        return EXIT_FAILURE;
    }
    if (!(fprog = fopen(argv[1], "r"))) {
        fprintf(stderr, "Cannot open program file.\n");
        return EXIT_FAILURE;
    }
    if (!(fimg = fopen(argv[3], "r"))) {
        fprintf(stderr, "Cannot open program file.\n");
        fclose(fprog);
        return EXIT_FAILURE;
    }
    for (c = fgetc(fprog); !feof(fprog); c = fgetc(fprog))
        putchar(c == '\n' ? '\r' : c);
    printf("\r//\b\b");
    for (c = fgetc(fimg); !feof(fimg); c = fgetc(fimg))
        printf(c == '\n' ? "\x1b[J\n//\b\b" : "%c", c);
    printf("\x1b[J");
    return EXIT_SUCCESS;
}
