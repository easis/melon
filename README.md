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
```

Also you can disable data ID write by setting the option _use_id_ to reduce the size of container (1 byte per ID). Doing this you should take care of data structure. The default is _use_id = true_ so the ID of data types are stored in the container.


### Using IDs
```C
melon m = melon_create();

char* str = "The meaning of life is";
melon_add_string( &m, str, strlen( str ) );
melon_add_int8( &m, 42 );

printf("size of container is %d bytes\n", m.size);
    
melon_delete(&m);
```

Output:
```
size of container is 29 bytes
```
1 byte (string id) + 4 bytes (string length) + 22 bytes (string) + 1 byte (int8 id) + 1 byte (int8 value) = 29 bytes

### Not using IDs
```C
melon m = melon_create();
m.use_id = false;

char* str = "The meaning of life is";
melon_add_string( &m, str, strlen( str ) );
melon_add_int8( &m, 42 );

printf("size of container is %d bytes\n", m.size);
    
melon_delete(&m);
```

Output:
```
size of container is 27 bytes
```
4 bytes (string length) + 22 bytes (string) + 1 byte (int8 value) = 27 bytes
