#include "ASTree.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "No input file specified\n");
        return 1;
    }

    PycModule mod;
    mod.loadFromFile(argv[1]);
    printf("# Source Generated with Decompyle++ pycdc\n");
    printf("# File: %s (Python %d.%d%s)\n", argv[1], mod.majorVer(), mod.minorVer(),
           (mod.majorVer() < 3 && mod.isUnicode()) ? " Unicode" : "");

    ASTree source;
    source.load(&mod);
    source.printSource(&mod);

    return 0;
}