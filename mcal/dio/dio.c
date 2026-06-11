#include "dio_interface.h"
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
void PortPinDir(u8 PortName,u8 direction,u8 pin)
{   
    switch (PortName%4)
    {
    case DIO_PORTA:
    {
        if(direction)
        SET_BIT(PORTA->DDR,pin);
        else 
        CLR_BIT(PORTA->DDR,pin);
    }
    break;
    case DIO_PORTB:
    {
        if(direction)
        SET_BIT( PORTB->DDR,pin);
        else 
        CLR_BIT(PORTB->DDR,pin);
    }
    break;
    case DIO_PORTC:
    {        
        if(direction)
        SET_BIT( PORTC->DDR,pin);
        else 
        CLR_BIT(PORTC->DDR,pin);
    }
    break;
    case DIO_PORTD:
    {
        if(direction)
        SET_BIT( PORTD->DDR,pin);
        else 
        CLR_BIT(PORTD->DDR,pin);
    }
    break;
    }
}
void PortSetPin(u8 PortName,u8 state,u8 pin)
{
    switch (PortName%4)
    {
    case DIO_PORTA:
    {
        if(state)
        SET_BIT(PORTA->PORT,pin);
        else 
        CLR_BIT(PORTA->PORT,pin);
    }
    break;
    case DIO_PORTB:
    {
        if(state)
        SET_BIT(PORTB->PORT,pin);
        else 
        CLR_BIT(PORTB->PORT,pin);
    }
    break;
    case DIO_PORTC:
    {        
        if(state)
        SET_BIT(PORTC->PORT,pin);
        else 
        CLR_BIT(PORTC->PORT,pin);
    }
    break;
    case DIO_PORTD:
    {
        if(state)
        SET_BIT(PORTD->PORT,pin);
        else 
        CLR_BIT(PORTD->PORT,pin);
    }
    break;
    }
}
u8 PortGetPin(u8 PortName,u8 pin)
{
    switch (PortName%4)
    {
    case DIO_PORTA:
    {
        return GET_BIT(PORTA->PIN,pin);
    }
    break;
    case DIO_PORTB:
    {
        
        return GET_BIT(PORTB->PIN,pin);
    }
    break;
    case DIO_PORTC:
    {        
        return GET_BIT(PORTC->PIN,pin);
    }
    break;
    case DIO_PORTD:
    {
        return GET_BIT(PORTD->PIN,pin);
    }
    break;
    }
}