
#include <stdio.h>
#include <stdlib.h>

#include "melon.h"

int main(int argc, char** argv) {

    melon m = melon_create();

    {
        uint8_t u8 = -72;
        melon_add_uint8(&m, u8);
        printf("uint8_t == %s\n", (u8 == melon_get_uint8(&m) ? "YES" : "NO"));
    }
    
    {
        int8_t i8 = 72;
        melon_add_int8(&m, i8);
        printf("int8_t == %s\n", (i8 == melon_get_int8(&m) ? "YES" : "NO"));
    }

    melon_delete(&m);

    return (EXIT_SUCCESS);
}

