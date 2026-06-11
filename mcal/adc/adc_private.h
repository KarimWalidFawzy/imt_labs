#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H
    #include "../../lib/STD_TYPES.h"
    struct ADC_s
    {
        u8 ADCL;
        u8 ADCH;
        u8 ADCSRA;
        u8 ADMUX;
    };
    typedef struct ADC_s ADC_t;
    static volatile ADC_t* const ADC_REG=(volatile ADC_t* const)0x24;

    #define ADEN  7
    #define ADSC  6
    #define ADLAR 5

    // SFIOR 
    // #define SFIOR *((volatile u8*)0x50)
#endif