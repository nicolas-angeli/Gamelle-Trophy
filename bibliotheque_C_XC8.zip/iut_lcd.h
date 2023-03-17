///////////////////////////////////////////////////////////////////////////////
// Utilisation simplifi�e d'un �cran LCD � 2 lignes et 16 colonnes
//
// IUT de Cachan
// Version 11/2015 pour xc8
// Source inspir� des biblioth�ques de Microchip MPLAB C18
//
// Fonctions disponibles
//
//   void lcd_init(void);
//     Initialisation de l'�cran LCD.
//     Cette fonction configure l'�cran LCD.
//     
//   void lcd_clear(void);
//     Efface l'�cran.
//
//   void lcd_position(char ligne, char colonne);
//     Positionne le curseur pour l'affichage.
//     Le coin sup�rieur gauche est en (0,0).
//       colonne 0                    colonne 15
//               |                             |
//     ligne 0 - X X X X X X X X X X X X X X X X
//
//     ligne 1 - X X X X X X X X X X X X X X X X
//
//   void lcd_putc(unsigned char lettre);
//     Affiche un caract�re � la position du curseur.
//     Le curseur se d�cale d'une case vers la droite.
//     Les caract�res sp�ciaux sont interpr�t�s (voir ci-dessous).
//
//   int lcd_printf(const char *f, ...);
//     Fonction printf pour l'�cran LCD.
//     Pour une description compl�te des formats autoris�s,
//     voir MPLAB_C18_Libraries_51297f.pdf �4.7
//
// Caract�res sp�ciaux interpr�t�s :
//   \n  passe � la ligne (ne fonctionne que de la ligne 0 � la ligne 1)
//   \b  pour reculer le curseur d'une case
//   \f  pour effacer l'�cran
//
// Connexions :
//   Broche - Ecran LCD
//     D0   -    E
//     D1   -    RS
//     D2   -    RW
//     D3   -    non connect�e
//   D4-D7  -    Data[4..7]
//
///////////////////////////////////////////////////////////////////////////////

#include <xc.h>

///////////////////////////////////////////////////////////////////////////////
//  Nom de fonction  :  lcd_init
//  Valeur de retour :  aucune
//  Param�tres       :  aucun
//  Description      :  bas�e sur le coontroleur d'afficheur Hitachi HD44780
//                      cette fonction initialise l'�cran LCD
///////////////////////////////////////////////////////////////////////////////
void lcd_init(void);

///////////////////////////////////////////////////////////////////////////////
//  Nom de fonction  :  lcd_clear
//  Valeur de retour :  aucune
//  Param�tres       :  aucun
//  Description      :  efface l'�cran LCD
///////////////////////////////////////////////////////////////////////////////
void lcd_clear(void);

///////////////////////////////////////////////////////////////////////////////
//  Nom de fonction  :  lcd_position
//  Valeur de retour :  aucune
//  Param�tres       :  char ligne
//                        num�ro de la ligne (0 ou 1)
//                      char colonne
//                        num�ro de la colonne (de 0 � 15)
//  Description      :  place le curseur sur la case (ligne, colonne)
///////////////////////////////////////////////////////////////////////////////
void lcd_position(char ligne, char colonne);

///////////////////////////////////////////////////////////////////////////////
//  Nom de fonction  :  lcd_putc
//  Valeur de retour :  aucune
//  Param�tres       :  unsigned char lettre
//                        code ASCII du caract�re � afficher
//  Description      :  affiche un caract�re sur l'�cran en g�rant les
//                      caract�res sp�ciaux \n \f \b
///////////////////////////////////////////////////////////////////////////////
void lcd_putc(unsigned char lettre);

///////////////////////////////////////////////////////////////////////////////
//  Nom de fonction  :  lcd_printf
//  Valeur de retour :  aucune
//  Param�tres       :  const char *f
//                        chaine de format
//                        pour une description compl�te des formats autoris�s,
//                        voir MPLAB_C18_Libraries_51297f.pdf �4.7
//                        le format float (%f) est partiellement impl�ment�
//                      ...
//                        variables � convertir
//  Description      :  affiche un message sur l'�cran LCD
///////////////////////////////////////////////////////////////////////////////
void lcd_printf(const char *f, ...);


///////////////////////////////////////////////////////////////////////////////
//
// Obsol�tes
// Fournies pour compatibilit� avec la version pr�c�dente de la biblioth�que.
//
///////////////////////////////////////////////////////////////////////////////
void lcd_gotoyx(char ligne, char colonne);
void lcd_puti(int nombre);
void lcd_putrs(const char *chaine);
void lcd_puts(char *chaine);

