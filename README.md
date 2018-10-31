# melon
Melon is a simple binary container to store some data types as: (u)int8_t, (u)int16_t, (u)int32_t and strings (char arrays).

## Example
```C
melon m = melon_create();

char* str = "The meaning of life is";
melon_add_string( &m, str, strlen( str ) );
melon_add_int8( &m, 42 );

size_t str_len;
char* s = melon_get_string( &m, &str_len );
printf( "%s %d", s, melon_get_int8( &m ) );
    
melon_delete(&m);
```

Output:
```
The meaning of life is 42
RUN FINISHED; exit value 0; real time: 0ms; user: 0ms; system: 0ms
```
