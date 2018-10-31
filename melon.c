#include "melon.h"

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

/*
    (DE)SERIALIZATION
 */

/* uint8 */
#define MELON_UINT8_ID (0x01)
#define MELON_UINT8_SIZE (1)

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

/* int8 */
#define MELON_INT8_ID (0x02)
#define MELON_INT8_SIZE (1)

bool melon_add_int8( melon* m, int8_t n ) {
    if(!melon_alloc( m, 1 /* datatype size */ + n )) {
        return false;
    }
    
    m->buffer[ m->write_offset++ ] = MELON_INT8_ID;
    m->buffer[ m->write_offset++ ] = n;
    
    m->size += MELON_INT8_SIZE;
    
    return true;
}

int8_t melon_get_int8( melon* m ) {
    if(!m->buffer || m->size <= 0) {
        return 0;
    }

    if(melon_get_data_id( m ) != MELON_INT8_ID) {
        return 0;
    }
    
    return ( m->buffer[ m->read_offset++ ] );
}

/* uint16 */
#define MELON_UINT16_ID (0x03)
#define MELON_UINT16_SIZE (2)

bool melon_add_uint16( melon* m, uint16_t n ) {
    if(!melon_alloc( m, 1 /* datatype size */ + n )) {
        return false;
    }
    
    m->buffer[ m->write_offset++ ] = MELON_UINT16_ID;
    memcpy( m->buffer + m->write_offset, &n, MELON_UINT16_SIZE ); 
    m->write_offset += MELON_UINT16_SIZE;
    
    m->size += MELON_UINT16_SIZE;
    
    return true;
}

uint16_t melon_get_uint16( melon* m ) {
    if(!m->buffer || m->size <= 0) {
        return 0;
    }

    if(melon_get_data_id( m ) != MELON_UINT16_ID) {
        return 0;
    }
    
    uint16_t n;
    memcpy( &n, m->buffer + m->read_offset, MELON_UINT16_SIZE ); 
    
    m->read_offset += MELON_UINT16_SIZE;
    
    return ( n );
}

/* int16 */
#define MELON_INT16_ID (0x04)
#define MELON_INT16_SIZE (2)

bool melon_add_int16( melon* m, int16_t n ) {
    if(!melon_alloc( m, 1 /* datatype size */ + n )) {
        return false;
    }
    
    m->buffer[ m->write_offset++ ] = MELON_INT16_ID;
    memcpy( m->buffer + m->write_offset, &n, MELON_INT16_SIZE ); 
    m->write_offset += MELON_INT16_SIZE;
    
    m->size += MELON_INT16_SIZE;
    
    return true;
}

int16_t melon_get_int16( melon* m ) {
    if(!m->buffer || m->size <= 0) {
        return 0;
    }

    if(melon_get_data_id( m ) != MELON_INT16_ID) {
        return 0;
    }
    
    int16_t n;
    memcpy( &n, m->buffer + m->read_offset, MELON_INT16_SIZE ); 
    
    m->read_offset += MELON_INT16_SIZE;
    
    return ( n );
}

/* uint32 */
#define MELON_UINT32_ID (0x05)
#define MELON_UINT32_SIZE (4)

bool melon_add_uint32( melon* m, uint32_t n ) {
    if(!melon_alloc( m, 1 /* datatype size */ + n )) {
        return false;
    }
    
    m->buffer[ m->write_offset++ ] = MELON_UINT32_ID;
    memcpy( m->buffer + m->write_offset, &n, MELON_UINT32_SIZE ); 
    m->write_offset += MELON_UINT32_SIZE;
    
    m->size += MELON_UINT32_SIZE;
    
    return true;
}

uint32_t melon_get_uint32( melon* m ) {
    if(!m->buffer || m->size <= 0) {
        return 0;
    }

    if(melon_get_data_id( m ) != MELON_UINT32_ID) {
        return 0;
    }
    
    uint32_t n;
    memcpy( &n, m->buffer + m->read_offset, MELON_UINT32_SIZE ); 
    
    m->read_offset += MELON_UINT32_SIZE;
    
    return ( n );
}

/* int32 */
#define MELON_INT32_ID (0x06)
#define MELON_INT32_SIZE (4)

bool melon_add_int32( melon* m, int32_t n ) {
    if(!melon_alloc( m, 1 /* datatype size */ + n )) {
        return false;
    }
    
    m->buffer[ m->write_offset++ ] = MELON_INT32_ID;
    memcpy( m->buffer + m->write_offset, &n, MELON_INT32_SIZE ); 
    m->write_offset += MELON_INT32_SIZE;
    
    m->size += MELON_INT32_SIZE;
    
    return true;
}

int32_t melon_get_int32( melon* m ) {
    if(!m->buffer || m->size <= 0) {
        return 0;
    }

    if(melon_get_data_id( m ) != MELON_INT32_ID) {
        return 0;
    }
    
    int32_t n;
    memcpy( &n, m->buffer + m->read_offset, MELON_INT32_SIZE ); 
    
    m->read_offset += MELON_INT32_SIZE;
    
    return ( n );
}