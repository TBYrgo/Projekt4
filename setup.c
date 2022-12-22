/********************************************************************************
* setup.c: Innehåller funktionalitet för initiering av det inbyggda systemet.
********************************************************************************/
#include "header.h"

/* Definition av globala objekt: */
struct button b1;    /* Tryckknappar. */
struct timer t0, t1; /* Timerkretsar. */
struct tmp36 temp1;

/********************************************************************************
* setup: Initierar det inbyggda systemet. Lysdioder initieras på pin 8 - 9,
*        tryckknappar initieras med aktiverade PCI-avbrott på pin 12 - 13
*        och samtliga timerkretsar konfigureras, där timer 0 sätts till att
*        löpa ut efter 300 ms (för att temporärt inaktivera PCI-avbrott på
*        I/O-port B efter nedtryckning för att undvika multipla avbrott orsakat
*        av kontaktstudsar, medan timer 1 - 2 sätts till att löpa ut efter
*        100 ms (för blinkning via toggling av lysdioder).
********************************************************************************/
void setup(void)
{
	
/*Initieringar av knapp med avbrott, Två timerkretsar med avbrott och temperaturmätaren*/

	button_init(&b1, 13);
	button_enable_interrupt(&b1);
	timer_init(&t0, TIMER_SEL_0, 300);
	timer_init(&t1, TIMER_SEL_1, 60000);
	tmp36_init(&temp1, A2);
	timer_enable_interrupt(&t1);

	return;
}