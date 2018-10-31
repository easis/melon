
#include <stdio.h>
#include <stdlib.h>

#include "melon.h"

int main(int argc, char** argv) {

    melon m = melon_create();

    {
        uint8_t u8 = -72;
        melon_add_uint8( &m, u8 );
        printf("uint8_t == %s\n", (u8 == melon_get_uint8( &m ) ? "YES" : "NO"));
    }
    
    {
        int8_t i8 = 72;
        melon_add_int8(&m, i8);
        printf("int8_t == %s\n", (i8 == melon_get_int8( &m ) ? "YES" : "NO"));
    }
    
    {
        uint16_t u16 = -1337;
        melon_add_uint16( &m, u16 );
        printf("uint16_t == %s\n", (u16 == melon_get_uint16( &m ) ? "YES" : "NO"));
    }
    
    {
        int16_t i16 =1337;
        melon_add_int16( &m, i16 );
        printf("int16_t == %s\n", (i16 == melon_get_int16( &m ) ? "YES" : "NO"));
    }
    
    {
        uint32_t u32= -13371337;
        melon_add_uint32( &m, u32 );
        printf("uint32_t == %s\n", (u32 == melon_get_uint32( &m ) ? "YES" : "NO"));
    }
    
    {
        int32_t i32 =13371337;
        melon_add_int32( &m, i32 );
        printf("int32_t == %s\n", (i32 == melon_get_int32( &m ) ? "YES" : "NO"));
    }
    
    {
        char* str ="Blau";
        melon_add_string(&m, str, strlen( str ) );
        size_t str_len;
        printf("str == %s\n", ( strcmp( melon_get_string( &m, &str_len ), str ) == 0 ? "YES" : "NO"));
    } 

    melon_delete(&m);

    return (EXIT_SUCCESS);
}

