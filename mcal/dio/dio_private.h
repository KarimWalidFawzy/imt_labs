#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H
    #include "../../lib/STD_TYPES.h"
    #pragma pack(1)
    struct DIO_port
    {
        u8 PIN;
        u8 DDR;
        u8 PORT;        
    };
    #pragma pack()
    typedef struct DIO_port DIO_port_t;
    static volatile DIO_port_t* const PORTA = (DIO_port_t*)0x39ULL;
    static volatile DIO_port_t* const PORTB = (DIO_port_t*)0x36ULL;
    static volatile DIO_port_t* const PORTC = (DIO_port_t*)0x33ULL;
    static volatile DIO_port_t* const PORTD = (DIO_port_t*)0x30ULL;    
#endif