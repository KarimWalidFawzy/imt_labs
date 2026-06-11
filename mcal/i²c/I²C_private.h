#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H
    #define TWBR  *((volatile u8*)0x20)
    #define TWSR  *((volatile u8*)0x21)
    #define TWAR  *((volatile u8*)0x22)
    #define TWDR  *((volatile u8*)0x23)
    #define TWCR  *((volatile u8*)0x56)

/* TWCR bit positions */
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
#define TWIE  0

/* TWSR prescaler bits (TWPS1:0 are bits 1:0) */
#define TWPS0 0
#define TWPS1 1
        
#endif 