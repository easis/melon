#ifndef MELON_H
#define MELON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // memcpy
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct melon_t {
        char* buffer;
        uint32_t size;

        uint32_t write_offset;
        uint32_t read_offset;

        bool use_id;
    } melon;

    melon melon_create();
    void melon_delete(melon*);

    bool melon_add_uint8(melon*, uint8_t);
    uint8_t melon_get_uint8(melon*);

    bool melon_add_int8(melon*, int8_t);
    int8_t melon_get_int8(melon*);

    bool melon_add_uint16(melon*, uint16_t);
    uint16_t melon_get_uint16(melon*);

    bool melon_add_int16(melon*, int16_t);
    int16_t melon_get_int16(melon*);

    bool melon_add_uint32(melon*, uint32_t);
    uint32_t melon_get_uint32(melon*);

    bool melon_add_int32(melon*, int32_t);
    int32_t melon_get_int32(melon*);

    bool melon_add_string(melon*, char*, uint32_t);
    char* melon_get_string(melon*, uint32_t*);


#ifdef __cplusplus
}
#endif

#endif /* MELON_H */

