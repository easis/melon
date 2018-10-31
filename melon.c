#include "melon.h"

#define MELON_UINT8_ID (0x01)
#define MELON_UINT8_SIZE (1)

bool melon_alloc( melon*, size_t );
uint8_t melon_get_data_id( melon* );

melon melon_create() {
    melon m;

    m.buffer = 0;
    m.size = 0;
    m.write_offset = 0;
    m.read_offset = 0;

    return m;
}

void melon_delete( melon* m ) {
    free( m->buffer );
    m->size = 0;
    m->read_offset = 0;
    m->write_offset = 0;
}

bool melon_alloc( melon* m, size_t n ) {
    if(m->buffer) {
        m->buffer = realloc( m->buffer, m->size + n );
    } else {
        m->buffer = malloc( 0 );
    }
    
    return ( m->buffer );
}

uint8_t melon_get_data_id( melon* m ) {
    return ( m->buffer[ m->read_offset++ ] );
}

bool melon_add_uint8( melon* m, uint8_t n ) {
    if(!melon_alloc( m, 1 /* datatype size */ + n )) {
        return false;
    }
    
    m->buffer[ m->write_offset++ ] = MELON_UINT8_ID;
    m->buffer[ m->write_offset++ ] = n;
    
    m->size += MELON_UINT8_SIZE;
    
    return true;
}

uint8_t melon_get_uint8( melon* m ) {
    if(!m->buffer || m->size <= 0) {
        return 0;
    }

    if(melon_get_data_id( m ) != MELON_UINT8_ID) {
        return 0;
    }
    
    return ( m->buffer[ m->read_offset++ ] );
}