///////////////////////////////////////////////////////////////////////////////
// Utilisation simplifi�e du convertisseur analogique-num�rique (ADC)
//
// IUT de Cachan
// Version 06/2014 pour xc8
//
// Fonctions disponibles
//
//   void adc_init(char numero_dernier_canal);
//     Initialisation de l'ADC en pr�cisant le num�ro du dernier canal
//     analogique utilis�
//       adc_init(0); // active un seul canal : AN0.
//       adc_init(3); // active 4 canaux : AN0, AN1, AN2 et AN3
//     Cette fonction permet d'utiliser au maximum 8 canaux : adc_init(7);
//
//   int adc_read(char numero_canal);
//     Lecture de la valeur num�ris�e d'un canal analogique
//     Broches configur�es en analogique par adc_init
//     Temps de conversion : environ 25 us
//
//   Broche - Canal analogique
//     A0   -   AN0
//     A1   -   AN1
//     A2   -   AN2
//     A3   -   AN3
//     A5   -   AN4
//     E0   -   AN5
//     E1   -   AN6
//     E2   -   AN7
//
// Pour plus d'informations, consultez p18f4550_39632e.pdf �21
///////////////////////////////////////////////////////////////////////////////

#include <xc.h>

///////////////////////////////////////////////////////////////////////////////
//  Nom de fonction  :  adc_init
//  Valeur de retour :  aucune
//  Param�tres       :  char numero_dernier_canal
//                        valeur enti�re de 0 � 7, num�ro du dernier canal
//                        configur� en entr�e analogique
//  Description      :  configuration de l'ADC sur la plage 0-5V
//                      et choix du dernier canal analogique
//                      0 indique seul AN0 en analogique
//                      7 indique AN0, AN1,...,AN7 en analogiques
///////////////////////////////////////////////////////////////////////////////
void adc_init(char numero_dernier_canal);

///////////////////////////////////////////////////////////////////////////////
//  Nom de fonction  :  adc_read
//  Valeur de retour :  int  =>  valeur lue sur 10 bits
//  Param�tres       :  char numero_canal
//                        valeur enti�re de 0 � 7, num�ro du canal � convertir
//  Description      :  s�lection d'un canal analogique
//                      attente de la fin de la conversion
//                      renvoi de la valeur lue sur 10 bits
//                      dur�e de la conversion, environ 25us
///////////////////////////////////////////////////////////////////////////////
int adc_read(char numero_canal);
