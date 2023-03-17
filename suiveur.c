#include <xc.h>
#include "iut_lcd.h"
#include "iut_adc.h"
#include "iut_pwm.h"
int potent = 0;
int etatLectureCapteur = 0;
    int CD, CG, position;
    //int setdc1, setdc2
void suiviLigne(void) {
    switch (etatLectureCapteur) {
        case 0:                     // tout droit
           //if ((CD < 900)&(CG < 200)) etatLectureCapteur = 1;
            if (position > -142) etatLectureCapteur = 1;  // tourne à droite
            //if ((CG < 900)&(CD < 200)) etatLectureCapteur = 2;
            if (position <-292) etatLectureCapteur = 2;  // tourne à gauche
            pwm_setdc1(150); // moteur droit
            pwm_setdc2(150); // moteur gauche
            break
        case 1:                    // tourner à droite
            if (position < -217) etatLectureCapteur = 0;
                pwm_setdc1(200); // moteur droit
                pwm_setdc2(100); // moteur gauche  
            break;
        case 2:                     // tourner à gauche
            if (position > -217) etatLectureCapteur = 0;
               pwm_setdc1(100); //moteur droit
               pwm_setdc2(200); //moteur gauche
            break;
            
        default:
            // ce cas ne devrait jamais se produire
            etatLectureCapteur = 0;
    } // fin du switch*
}
void main(void) {
    // declarations des variables
    char JCK, FDC;
    int etat;
    // initialisation    
    lcd_init();
    lcd_position(0, 0);
    adc_init(5);
    pwm_init(149, 2); // initialisation de la période 50µs
    pwm_setdc1(0); // 0,25 pour PWM1 (broche C2)
    pwm_setdc2(0); // 0,75 pour PWM2 (broche C1)
    TRISB = 0xFF;
    TRISE = 0xFF;
    while (1) {
        // initialisation    
        //lcd_position(0, 0);
        // acquisition entrée
        potent = adc_read(0);
        FDC = PORTBbits.RB2;
        JCK = PORTEbits.RE2;
        // lecture des capteurs
        CG = adc_read(3);
        CD = adc_read(1);
        position = CD - CG;     // positif si sortie vers la gauche
                                // négatif si sortie vers la droite
        // affichage
        lcd_position(0, 0);
        lcd_printf(" Pos %4d  ", position);
        lcd_position(1, 0);
        lcd_printf("CD%4d CG%4d", CD, CG);
        switch (etat) {
            case 0:                 // arret des moteurs
                //lcd_position(0, 0);
                pwm_setdc1(0);
                pwm_setdc2(0);
                if (FDC != 0) {
                    etat = 1;
                    etatLectureCapteur = 0;
                }
                break;  
            case 1:                 // course
                if (JCK == 0) etat = 2;
               // lcd_position(0, 0);
               // lcd_printf("Etat = 1");
                suiviLigne();
                break;
            case 2:                 // fin de course
                pwm_setdc1(0); // 0,25 pour PWM1 (broche C2)
                pwm_setdc2(0); // 0,75 pour PWM2 (broche C1)

                if (FDC == 0) etat = 0;
                //lcd_position(0, 0);
                //lcd_printf("Etat = 0");
                break;
            default:
                // ce cas ne devrait jamais se produire
                etat = 0    }   
 }  
}
