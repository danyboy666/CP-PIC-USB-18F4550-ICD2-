////////////////////////////////////////////////////////////////////////////////
//                 Applications des microcontrolleurs              243-444-RK //
//                                                                            //
//                             Projet Final                                   //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                  Decription:                                               //
//                                                                            //
// Partie : A :   Obligatoire                     pour un total de 50 %       //
// 1.   Le syst�me est s�curis� et attend la lecture de votre code num�rique  //
// d'acc�s (NIP). Il vous l'indique par une invitation � introduire votre code// 
// d'acc�s et affiche l'heure. Le code d'acc�s est composer de 6 chiffres     //
// moins si votre programme g�re la touche retour arri�re et la touche entr�e,// 
// voir partie : bonus : C.                                                   //
//                                                                            //
// 2.   Suite � la lecture de celui-ci, votre programme interroge sa banque   //
// de donn�es pour savoir si vous �tes un �tudiant valide                     //
// "   Si c'est le cas, le syst�me vous salue et emmagasine en m�moire interne// 
// interne votre nom ainsi que l'heure (en m�moire externe voir partie : B)   //
// "   Si ce n'est pas le cas le syst�me vous informe que vous n'aurez pas    //
// acc�s au syst�me et le syst�me se r�initialise c. � d. qu'il se met en     //
// attente de lecture de votre code num�rique.                                //
// "   Le syst�me conna�t minimalement 4 personnes, dont Paul avec le         //
// code : 123456                                                              //
//                                                                            //
// 3.   Si vous �tes Paul (administrateur) vous pouvez modifier l'heure du    //
// RTC et savoir les 10 derni�res personnes qui sont entr�es sur le syst�me.  //
// Il peut contr�ler l'affichage des noms � l'�cran                           //
//                                                                            //
// 4.   Si vous �tes une personne autoris�e, vous pouvez avoir acc�s � la     //
// partie E et F                                                              //
//                                                                            //
// 5.   Lors d'une alimentation, affichez le logo ou l'identifiant de         //
// votre compagnie                                                            //
//                                                                            //
// Partie B : au choix                        pour un total de 10 %           //
// Vous m�moriser la date et l'heure de l'acc�s en m�moire EEPROM ext�rieur   //
//                                                                            //
// Partie C: au choix                        pour un total de 10 %            //
// Rendre la lecture sensible � la touche retour arri�re et la touche entr�e  //
//                                                                            //
// Partie D: au choix                        pour un total de 10 %            //
// La banque de donn� conna�t deux personnes qui non pas de NIP               //
// 1.   Si vous n'avez pas de NIP et que vous �tes dans la banque de donn�es! //
// Vous pouvez en choisir un en mettant une entr�e � un niveau z�ro, vous     //
// �tes alors en mode de configuration. Apr�s avoir identifi� votre nom son   //
// num�ro correspondant, fournie dans une liste d�roulante (contr�l� par      //
// l'utilisateur) le syst�me reconna�t que vous n'avez pas de NIP :           //
// o   Le syst�me vous salue, Il vous demande, de choisir un NIP de 6 touches //
// cons�cutif sur le clavier. Qu'il vous demandera de r�p�ter une deuxi�me    //
// fois pour validation et si tout se passe bien le syst�me le m�morise et    //
// vous autorise � continuer.                                                 //
// o   Si un d�lai sup�rieur � 60 secondes se passe entre la mise � un niveau //
// z�ro de l'entr�e et l'introduction de votre NIP une premi�re fois. Le      //
// syst�me se r�initialise, retour � la partie : A.1.                         //
//                                                                            //
// 2.   Si vous avez d�j� un NIP vous pouvez en choisir un autre en mettant   //
// m�me entr�e � niveau z�ro, vous �tes en mode programmation. Apr�s avoir    //
// identifi� votre nom dans une liste d�roulante (contr�l� par l'utilisateur) //
// avec son num�ro correspondant, le syst�me reconna�t que vous avez d�j� un  //
// NIP : le syst�me vous demande de le changer apr�s vous avoir identifi�     //
// avec l'ancien num�ro.                                                      //
// o   Si tout se passe bien le syst�me le m�morise et vous autorise �        //
// continuer.                                                                 //
// o   Si ce n'est pas le cas le syst�me le syst�me se r�initialise.et vous   //
// conserver votre ancien num�ro.                                             //
//                                                                            //
// Partie E: au choix                        pour un total de 10 %            //
// Contr�ler la vitesse d'un moteur CC � l'aide d'un potentiom�tre            //
// (sur toute la page de celui-ci). Afficher la vitesse de celui-ci �         //
// l'aide d'un graphique barre                                                //
//                                                                            //
// Partie F: au choix                        pour un total de 10 %            //
// Afficher la vitesse du moteur avec le tachym�tre                           //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// (c)Copyright 2012 Dany Ferron                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//              _________________                                             //
//            -|1              40|-RB7                                        //
//    RA0/ANA0-|                 |-RB6                                        //
//            -|    PIC18F4550   |-RB5                                        //
//            -|      @20MHz     |-RB4                                        //
//            -|                 |-RB3                                        //
//            -|                 |-RB2/Int2    <- Interrupt                   //
//            -|                 |-RB1                                        //
//            -|                 |-RB0                                        //
//            -|                 |-                                           //
//            -|                 |-                                           //
//            -|                 |-                                           //
//            -|                 |-                                           //
//            -|                 |-                                           //
//            -|                 |-                                           //
//            -|                 |-RC7/RX <- This is the connection to the    //
//            -|                 |-RC6/TX -> MELabs 4X20 serial LCD           //
//            -|                 |-          controller                       //
//            -|                 |-                                           //
//         RD0-|                 |-                                           //
//         RD1-|20             21|-RD2                                        //
//              -----------------                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

//////////////////////////Include header file///////////////////////////////////
#include "Final_Project_TGE_2012.h"

//////////////////Include driver source used in this project////////////////////
#include "Matrix_Keypad4X4_W.INT.c"
#include "RTC_Clock.c"
#include "DS1307_db666.c"
#include "Serial_EXT_EEPROM.c"
#include "SLCD.c"

//#zero_ram // S'assure que le registre interne servant � tenir les variables
          // est � zero
          
////////////////////////////////////////////////////////////////////////////////
// Le d�but de l'addresse m�moire commence � 0xF00000: Il est � not� qu'il    // 
// faut sp�cifier au compilateur quel est le type de variable, par d�fault il //
// stock en m�moire un integer d'une longueur de 16 bits. Donc pas pratique   //  
// si l'on veux lire et stocker un octet � la fois.                           //
////////////////////////////////////////////////////////////////////////////////

#rom int8 0xF00000 = {'1','2','3','4','5','6'} // Code de d�verrouillage.
#rom int8 0xF00012 = {'2','3','4','5','6','7'} // Code de d�verrouillage.
#rom int8 0xF00024 = {'3','4','5','6','7','8'} // Code de d�verrouillage.
#rom int8 0xF00032 = {'4','5','6','7','8','9'} // Code de d�verrouillage.

/////////////////////////////Variable Globales//////////////////////////////////

// D�finition et initialisation des variables servant au stockage de mot de  
// passe en EEPROM.

#define PASSWORD_LENGTH 6
char password[PASSWORD_LENGTH] = {};

char k; // Variable de m�morisation des touches de clavier retourn�s par la 
        // fonction kbd_getc();

char displayID[6];
int8 x;

char userList[10] = {};
int8 len;   
 
#define USER0_ADR 0x00
#define USER1_ADR 0x12
#define USER2_ADR 0x24
#define USER3_ADR 0x32

int8 lcd_adr; 
BOOLEAN getID;
//BOOLEAN getPSW;
BOOLEAN options;
BOOLEAN admin;
//#define ENABLE 1
//#define DISABLED 0

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// L'appui d'une touche provoque un interruption du programme principal.      //
// En mettant au niveau bas les rang�es et les colonnes, on identifie quelle  //
// touche est pes�e en effectuant un OU logique et la fonction appel�e par    //
// l'interruption retourne la valeur de la touche appuy�e.                    //
////////////////////////////////////////////////////////////////////////////////

#int_EXT2 // Utilisation de l'interruption EXT2 cabl� sur le portB bit 2.
void EXT2_isr(void) 
   {  
    k = kbd_getc();
   }
 
char read_from_EEPROM(int8 adr);
void kbd_init();
void read_RTC_from_EXT_EEPROM(int8 EEPROM_adr);
void write_RTC_to_EXT_EEPROM(int8 EEPROM_adr);
void user_validation();
void password_validation();
void general_options();
void user_logs();
void log_user(int8 x);

#define KEYPAD_BS 'b'
#define KEYPAD_ENTER 'e'

//////////////////////////// Programme principal.///////////////////////////////
void main() 
   {
    enable_interrupts(int_EXT2); // Initialisation des interruptions.
    enable_interrupts(GLOBAL);
    ext_int_edge(2,H_TO_L);// Front descendant sur RB2 Interrupt ext 2
    
    LCD_BacklightOn();
    LCD_ClearDisplay(); //Initialisation de l'affichage.
    init_ext_eeprom(); //Initialisation de l'EEPROM externe.
    init_I2C_Clock(); // Initialisation du RTC.
                      // Set time and date:
                      // hh,mm,ss,DD,MM,YY,WD
    set_I2C_Clock(0x23,0x59,0x50,0x20,0x03,0x12,0x03);
    
    user_validation();
    
    if(getID == TRUE)
    {
     password_validation();
    }
    
    if(getID == TRUE && options == TRUE)
    {
     general_options();
    }
    
   }
///////////////////////Fin du programme principal.//////////////////////////////

// Cette fonction lit et retourne le code qui est en EEPROM.
char read_from_EEPROM(int8 adr)
   { 
    int8 i;
    
    for(i = 0;i < PASSWORD_LENGTH;i++) 
       {
        password[i] = read_eeprom(i + adr);
       }  
return password[i];  
   }
   
void write_RTC_to_EXT_EEPROM(int8 EEPROM_adr)
   {
           
    get_I2C_Clock();// Reads date and time
    write_ext_eeprom(EEPROM_adr++,rtc_value.hour);
    write_ext_eeprom(EEPROM_adr++,rtc_value.minute);
    write_ext_eeprom(EEPROM_adr++,rtc_value.second);
    write_ext_eeprom(EEPROM_adr++,rtc_value.day);
    write_ext_eeprom(EEPROM_adr++,rtc_value.month);
    write_ext_eeprom(EEPROM_adr++,rtc_value.year);
   }
                   

// Cette fonction lit et retourne le code qui est en EEPROM.
void read_RTC_from_EXT_EEPROM(int8 EEPROM_adr)
   { 
    //Variables locales.
    BYTE hr;
    BYTE min;
    BYTE sec;
    BYTE day;
    BYTE mth;
    BYTE yr;
/*    
 #define USER0_ADR 0x00
#define USER1_ADR 0x12
#define USER2_ADR 0x24
#define USER3_ADR 0x32 


*/  
    //x = read_ext_eeprom(EEPROM_adr++);
    hr = read_ext_eeprom(EEPROM_adr++);
    min = read_ext_eeprom(EEPROM_adr++);
    sec = read_ext_eeprom(EEPROM_adr++);
    day = read_ext_eeprom(EEPROM_adr++);
    mth = read_ext_eeprom(EEPROM_adr++);
    yr = read_ext_eeprom(EEPROM_adr++);  
    
    
    //printf(" Time:%x:%x:%x\n\r",hr,min,sec);
    //printf(" Date: %x/%x/%x\n\r",day,mth,yr);
    
    switch(x)
    {
    case USER0_ADR:
    printf(" Admin %s:%x:%x:%x\n\r",x,hr,min,sec);
    break;
    
    case USER1_ADR:
    printf(" User1 %s:%x:%x:%x\n\r",x,hr,min,sec);
    break;
    case USER2_ADR:
    printf(" User2 %s:%x:%x:%x\n\r",x,hr,min,sec);
    break;
    case USER3_ADR:
    printf(" User3 %s:%x:%x:%x\n\r",x,hr,min,sec);
    break;
    //printf(" Date: %x/%x/%x\n\r",day,mth,yr);
    }
   
   }
void password_validation()
   {
    int1 passwordValid = false;
    int8 inputCount = 0;
    char userInput[PASSWORD_LENGTH] = {};
    int8 j = 0;
    options = FALSE;
    
    LCD_ClearDisplay();
    LCD_Position(1,5);
    printf("Thank You");
    delay_ms(1000);
    LCD_ClearDisplay();
    LCD_Position(1,2);
    printf("Enter your code");
    lcd_adr = 0xc7;
    do
      {
       kbd_init();
       
       if(k != '\0') // Si une touche est appuy�e, donc si interruption
         {
          if(k == KEYPAD_BS) // Est-ce que la touche retour-arri�re �t� appuy�e? 
            {  
             inputCount--;
             printf("%c%c",0xfe,--lcd_adr);
             printf(" ");
             delay_ms(300); // D�lai servant de fonction anti-rebond(DEBOUNCE)
            }
          else if((k == KEYPAD_ENTER) || (inputCount >= PASSWORD_LENGTH)) 
            {
             
             if(inputCount == PASSWORD_LENGTH)
               {
                passwordValid = TRUE;
                      
                for(j = 0;j < PASSWORD_LENGTH;j++)
                   {
                    // On compare le code entr� par l'utilisateur avec le mot de passe
                    // qui � �t� lut auparavant par la fonction read_from_EEPROM().
                    if(userInput[j] != password[j])
                      {
                       passwordValid = FALSE;
                            
                       LCD_ClearDisplay();
                       printf("%c%c",0xfe,0x97);
                       printf("Votre code est");
                       printf("%c%c",0xfe,0xd9);
                       printf("incorrect!");
                       delay_ms(500);
                       LCD_ClearDisplay();
                       printf("%c%c",0xfe,0xd5);
                       printf("Veuillez reessayer");
                       LCD_ClearDisplay();
                       printf("%c%c",0xfe,0x81);
                       printf("Entrez votre code");
                       lcd_adr = 0xc7;
                      }
                // On remet la chaine entr�e par l'utilisateur a NULL pour 
                // un autre essai.
                userInput[j] = '0';
                   }
                // On remet la variable de touche appuy�e par l'utilisateur � 0 une
                // fois que les 4 touches on �t� valid�es.
                inputCount = 0;
                        
                if(passwordValid == TRUE)
                  {
                   LCD_ClearDisplay();
                   LCD_Position(1,3);
                   printf("Welcome %s",displayID);
                   delay_ms(1000);
                   
                   if(admin == TRUE)
                     {
                      write_RTC_to_EXT_EEPROM(USER0_ADR);
                      log_user(x);
                     }
                     
                   else
                     {
                      switch(x)
                      {
                       case USER1_ADR:
                       write_RTC_to_EXT_EEPROM(USER1_ADR);
                       log_user(x);
                       break;
                      
                       case USER2_ADR:
                       write_RTC_to_EXT_EEPROM(USER2_ADR);
                       log_user(x);
                       break;
                      
                       case USER3_ADR:
                       write_RTC_to_EXT_EEPROM(USER3_ADR);
                       log_user(x);
                       break;
                      }
                     }
                   options = TRUE;  
                  }
               } 
            }
          else
            {
             userInput[inputCount++] = k;
             printf("%c%c",0xfe,lcd_adr);
             printf("%c",k);
             delay_ms(325); // Delai servant de fonction anti-rebond(DEBOUNCE)
             printf("%c%c",0xfe,lcd_adr++);
             printf("*"); // Cache le caract�re entr� par l'utilisateur.
             delay_ms(225);
            }
            
         }
          // On s'assure de remettre une valeur NULL � la variable de lecture.
          k = '\0'; 
      }
    while(options == FALSE);
   }

void user_validation()
   {
    LCD_ClearDisplay();
    printf("Please enter your ID");
    printf("1- Admin   2- User1\n\r");
    printf("3- User2   4- User3\n\r");
    getID = FALSE;
    
    do
     {
      kbd_init();
      if(k != '\0') // Si une touche est appuy�e, donc si interruption
        {
         switch(k) // Switch/case servant � pointer vers la bonne address EEPROM
            {
             case '1':
             admin = TRUE;
             
             strcpy(displayID,"Admin");
             read_from_EEPROM(USER0_ADR);
             x = USER0_ADR;
             getID = TRUE;
             
             
             break;
             
             case '2':
             admin = FALSE;
             
             strcpy(displayID,"User1");
             read_from_EEPROM(USER1_ADR);
             x = USER1_ADR;
             getID = TRUE;
             
             
             break;
             
             case '3':
             admin = FALSE;
             
             strcpy(displayID,"User2");
             read_from_EEPROM(USER2_ADR);
             x = USER2_ADR;
             getID = TRUE;
             
             
             break;
             
             case '4':
             admin = FALSE;
             
             strcpy(displayID,"User3");
             read_from_EEPROM(USER3_ADR);
             x = USER3_ADR;
             getID = TRUE;
             
             
             break;
             
             default:
             getID = FALSE;
            }
        } 
       // On s'assure de remettre une valeur NULL � la variable de lecture.
       k = '\0';
     }
      while(getID == FALSE);
   }
   
void general_options()
   { 
     LCD_ClearDisplay();
     printf("  Choose an option  ");
     printf("%c%c",0xfe,0x94);
     printf("1- Motor    2- Tachy");
     
     if(admin == TRUE)
       {
        printf("%c%c",0xfe,0xd4);
        printf("3- Gestion  4- Logs ");
       }
     delay_ms(1000);
    do
     {
      kbd_init();
      if(k != '\0') // Si une touche est appuy�e, donc si interruption
        {
         switch(k) // Switch/case servant � pointer vers la bonne address EEPROM
            {
             case '1':
               LCD_ClearDisplay();
               printf("  ok1  ");
             break;
             
             case '2':
               LCD_ClearDisplay();
               printf("  ok2  ");
               user_logs();
             break;
             
             case '3':
               if(admin == FALSE)break;
               LCD_ClearDisplay();
               printf("  ok3  ");
               
             break;
             
             case '4':
               if(admin == FALSE)break;
               LCD_ClearDisplay();
               printf("  ok4  ");
               user_logs();
               
             break;
             
             default:
             //menu = FALSE;
             
            }
        } 
       // On s'assure de remettre une valeur NULL � la variable de lecture.
       k = '\0';
     }
      while(TRUE);
   }   

void kbd_init()
   {
    // Initialisation du port pour la lecture du clavier
    set_tris_d(0x0f); // Bit0 � bit3 en entr�e et bit 4 � bit7 en sortie
    //output_d(0xf0);
    output_low(pin_D4);
    output_low(pin_D5);
    output_low(pin_D6);
    output_low(pin_D7);
   }

void user_logs()
{
 int count;
 
for(count = 0; count < 10; count++) 
  {
   read_RTC_from_EXT_EEPROM(x);
   printf("%u",userList[0]);
    printf("%u",userList[1]);
    printf("%u",userList[2]);
    printf("%u",userList[3]);
    printf("%u",userList[4]);
    printf("%u",userList[5]);
    printf("%u",userList[6]);
    printf("%u",userList[7]);
    printf("%u",userList[8]);
    printf("%u",userList[9]);
   
  }
  
  
  
/*

getID == FALSE
 printf("%u",userList[0]);
 printf("%u",userList[1]);
 printf("%u",userList[2]);
 printf("%u",userList[3]);
 printf("%u",userList[4]);
 printf("%u",userList[5]);
 printf("%u",userList[6]);
 printf("%u",userList[7]);
 printf("%u",userList[8]);
 printf("%u",userList[9]);
 
*/

//userList[0]



}

void log_user(int8 x) 
{
 if(len >= 10)
   {
    len = 0;
   }
 userList[len++] = x;
}
                        
