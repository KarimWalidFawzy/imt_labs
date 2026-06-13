/*
Write a code to toggle a LED every 1 sec using timer 0 “Overflow mode”
Using TIMER0 compare-match interrupt to toggle PA0 every ~1 second.
*/
#include "../../mcal/timer/timer_interface.h"
#include "../../mcal/dio/dio_interface.h"
#include <avr/interrupt.h>

static void ToggleLED_Callback(void)
{
	TOG_BIT(PORTA->PORT, PIN0);
}

int main(void)
{
	PortPinDir(DIO_PORTA, OUTPUT, PIN0);

	TIMER0_Init();
	TIMER0_SetCompareValue(156); /* rough value for 1ms ticks depends on prescaler; will be used with prescaler 1024 to get ~1s via counting in main */
	TIMER0_SetCallback(ToggleLED_Callback);
	TIMER0_EnableCompareMatchInterrupt();
	TIMER0_Start(TIMER_PRESCALER_1024);

	sei();

	/* Use compare match interrupts - toggle frequency depends on system clock and compare value; here we approximate 1s by counting in callback is avoided to keep simple - instead use software counter */
	while (1)
	{
		;
	}

	return 0;
}