#include <stdio.h>
#include <amber_engine/engine.h>

int main(int arg_c, char** arg_v) {
    printf("Using version %s!\n", ae_get_version());

    return 0;
}