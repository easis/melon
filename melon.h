#ifndef MELON_H
#define MELON_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct melon_t {
        char* buffer;
        size_t size;
        
        uint8_t write_offset;
        uint8_t read_offset;
    } melon;
    
    melon melon_create();
    void melon_delete( melon* );
    
    bool melon_add_uint8( melon*, uint8_t );
    uint8_t melon_get_uint8( melon* );
    
     bool melon_add_int8( melon*, int8_t );
    int8_t melon_get_int8( melon* );


#ifdef __cplusplus
}
#endif

#endif /* MELON_H */

