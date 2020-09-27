/////////////////////////////////////////////////////////////////////////////////
//                 Applications des microcontrolleurs               243-444-RK //
//                         Laboratoire no. 8                                   //
//         Programme no 1: Exp�rimentation avec la m�moire EEPROM interne      //
//                         du microcontrolleur 18F4550                         //
//                                                                             //
//  read_eeprom(addr) - pour faire appel � la fonction de lecture sur l'EEPROM //
//  write_eeprom(addr,var) - pour faire appel � la fonction d'�criture sur     //
//                           l'EEPROM                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// Dany Ferron 2012                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                                                                             //
//              _________________                                              //
//            -|1              40|-RB7                                         //
//            -|                 |-RB6                                         //
//            -|    PIC18F4550   |-RB5                                         //
//            -|      @20MHz     |-RB4                                         //
//            -|                 |-RB3                                         //
//            -|                 |-RB2                                         //
//            -|                 |-RB1                                         //
//            -|                 |-RB0                                         //
//            -|                 |-                                            //
//            -|                 |-                                            //
//            -|                 |-                                            //
//            -|                 |-                                            //
//            -|                 |-                                            //
//            -|                 |-                                            //
//            -|                 |-RC7/RX <- This is the connection to the     //
//            -|                 |-RC6/TX -> MELabs serial LCD controller      //
//            -|                 |-                                            //
//            -|                 |-                                            //
//         RD0-|                 |-                                            //
//         RD1-|20             21|-RD2                                         //
//              -----------------                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#include "lab8_eeprom.h"

void main()
{
   BYTE value, valeur;
   signed long i;
   
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(FALSE);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   setup_oscillator(False);
 
   printf("%c%c",0xfe,0x01);
   
   for(i = 0; i <= 254; ++i) // de 0 � 254
   {      
      value = i +10;
      write_eeprom(i,value);   
   }
      
   while (TRUE){   
      for(i = 254; i >= 0; --i)  // de 254 � 0
      {     
      valeur = read_eeprom(i);
      printf("\f");
      printf("%c%c",0xfe,0xc0);
      printf("A l'adresse %3Ld la",i);
      printf("%c%c",0xfe,0x94);
      printf("valeur a 10 de plus\n\r c'est a dire %3u",valeur);
      delay_ms(250);
      }
   delay_ms(1000);   
   }
} 
