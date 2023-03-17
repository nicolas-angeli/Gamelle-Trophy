///////////////////////////////////////////////////////////////////////////////
// Configuration mat�rielle du microcontr�leur
//
// IUT de Cachan
// Version 06/2014 pour xc8
//
// Configuration des horloges pour un oscillateur externe � 20MHz
// et utilisation de la PLL
// Le CPU re�oit une horloge Fosc = 48MHz
// Les bits 0 � 4 du port B sont des E/S TOR
//
// Pour plus d'informations, consultez C18_Config_Settings_51537a.pdf
///////////////////////////////////////////////////////////////////////////////

#include <xc.h>

// Diviseur de la PLL pour un oscillateur � 20MHz (4MHz � l'entr�e de PLL)
#pragma config PLLDIV = 5
// PLL(96MHz) / 2 pour le CPU => Fosc=48MHz
#pragma config CPUDIV = OSC1_PLL2
// Horloge source USB PLL(96MHz) / 2
#pragma config USBDIV = 2
// Horloge ext pour CPU, PLL activ�e, RA6 port d'E/S, horloge ext pour USB
#pragma config FOSC = ECPLLIO_EC
// R�gulateur de tension USB activ�
#pragma config VREGEN = ON
// Watchdog Timer d�sactiv�
#pragma config WDT = OFF
// PortB<4:0> E/S TOR apr�s RESET
#pragma config PBADEN = OFF
// Low Voltage ICSP d�sactiv�
#pragma config LVP = OFF
// Debugger activ�
#pragma config DEBUG = ON

#pragma config CONFIG5L = 0x0F
#pragma config CONFIG5H = 0xC0
#pragma config CONFIG6L = 0x0F
#pragma config CONFIG6H = 0xE0
#pragma config CONFIG7L = 0x0F
#pragma config CONFIG7H = 0x40

#pragma warning disable 373    // evite le warning sur les conversions de type
                                // JM juillet 2017
