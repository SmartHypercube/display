#include <stdio.h>#include <stdlib.h>#include <string.h>int main(int argc, char *argv[]) {    FILE *fprog, *fimg;    char c;    if (argc != 4 || strcmp(argv[2], "as") != 0) {        fprintf(stderr, "Usage: display <PROGRAM> as <IMAGE>\n");        return EXIT_FAILURE;    }    if (!(fprog = fopen(argv[1], "r"))) {        fprintf(stderr, "Cannot open program file.\n");        return EXIT_FAILURE;    }    if (!(fimg = fopen(argv[3], "r"))) {        fprintf(stderr, "Cannot open program file.\n");        fclose(fprog);        return EXIT_FAILURE;    }    for (c = fgetc(fprog); !feof(fprog); c = fgetc(fprog))        putchar(c == '\n' ? '\r' : c);    printf("\r//\b\b");    for (c = fgetc(fimg); !feof(fimg); c = fgetc(fimg))        printf(c == '\n' ? "\x1b[J\n//\b\b" : "%c", c);    printf("\x1b[J");    return EXIT_SUCCESS;}//_____________________________________________________________[J
//[J
//                 /   ,                /[J
//-------------__-/-------__------__---/----__-----------------[J
//           /   /   /   (_ `   /   ) /   /   ) /   /[J
//__________(___/___/___(__)___/___/_/___(___(_(___/___________[J
//                            /                   /[J
//___________________________/_________________(_/_____________[J
//                                                    __[J
//          __  ______  __  _______   _________  ____/ /__[J
//         / / / / __ \/ / / / ___/  / ___/ __ \/ __  / _ \[J
//        / /_/ / /_/ / /_/ / /     / /__/ /_/ / /_/ /  __/[J
//    _   \__, /\____/\__,_/_/      \___/\____/\__,_/\___/[J
//   (_)_/____/ __  ______  __  _______   _      ______ ___  __[J
//  / / __ \   / / / / __ \/ / / / ___/  | | /| / / __ `/ / / /[J
// / / / / /  / /_/ / /_/ / /_/ / /      | |/ |/ / /_/ / /_/ /[J
///_/_/ /_/   \__, /\____/\__,_/_/       |__/|__/\__,_/\__, /[J
//           /____/                                   /____/[J
//_____________________________________________________________[J
//#include <https://github.com/Smart-Hypercube/display>[J
//[J
//int main() {[J
//    do_the_magic();[J
//    return 0;[J
//}[J
//[J