 #include <16F876.h>

#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
#use i2c(master, sda=PIN_C4, scl=PIN_C3)

#include "Define.h"
#include "db_lcd.c"
/*A v�rifier si bonne adresse*/
Byte CONST ACC = 0b00111010;  // Adresse Acc�l�rom�tre [LIS3LV02DL] (0x3A)ici 0011101b (sd0 � 1) (mais �a aurait pu �tre 0011100b) Le dernier bit (0) n'est pas un bit d'adresse mais celui qui indique si le device peut r�pondre ou non


//-------------Lecture  I2C------------------
signed byte lec_i2c(byte device, byte address) {
   signed BYTE data;

   i2c_start();
   i2c_write(device);//device=adresse du device (acc�l�rom�tre)
   i2c_write(address);//address=adresse du registre qui se trouve dans le device
   i2c_start();
   i2c_write(device | 1);//bit le + � droite mis � 1 pour qu'on puisse �crire sur le bus (signale au device qu'il peut r�pondre)
   data=i2c_read(0);
   i2c_stop();//indique que l'on a plus rien � faire au niveau du bus
   return(data);
}

//-------------Read of 2 bytes I2C-----------------
 signed int16 lecdb_i2c(byte device, byte address) {
   BYTE dataM,dataL;
   int16 data;

   i2c_start();
   i2c_write(device);
   i2c_write(address);                               
   i2c_start();
   i2c_write(device | 1);
   dataM = i2c_read(1);				// Read of MSB (8th most significant bit), we want to read 16 bits but we can only transfer 8 bits at a time
   dataL = i2c_read(0);				// Read of LSB (8th less significant bit)
   i2c_stop();
   data=((dataM*256)+dataL);		// We collect de final value (the eight most significant bit, we multiply by 256.
   lcd_gotoxy(1,1);                 // To go on location (1,1) gives the place X and Y we want to be on the lcd
   printf(lcd_char,"MSB:%d  LSB:%d  ",dataM,dataL);	 // Display the data on the lcd
   return(data);
 }

//-------------Ecriture  I2C------------------
void ecr_i2c(byte device, byte address, byte data) {
   i2c_start();
   i2c_write(device);//device=adresse du boitier
   i2c_write(address);//address=adresse du registre qui se trouve dans le boitier
   i2c_write(data);//data=infos que l'on vient stocker
   i2c_stop();//indique que l'on a plus rien � faire au niveau du bus
}

//-------------Lecture Acc�l�rom�tre I2C------------------
void lecture_ACC() {
	signed long byte axe_x, axe_y, axe_z = 0;
	byte tmp=0;
	signed int16 datax, datay, dataz=0;


	ecr_i2c(ACC,0x20,0b01000111);/*Ecriture dans le registre Ctrl_Reg1 (0x20), permet l'activation des 3 axes. ATTENTION full scale a 2g!!*/
	tmp=lec_i2c(ACC,0x27); /*Contient le registre Status_Reg 0x27 qui dit si il y a des nouvelles infos sur l'axe x,y,z, */
	

	if ((tmp&0x0C)==0x0C) axe_z=lec_i2c(ACC,0x2d);/*Si des nouvelles donn�es sont pr�sentes sur l'axe z, on lit*/
	if ((tmp&0x0A)==0x0A) axe_y=lec_i2c(ACC,0x2b);/*Si des nouvelles donn�es sont pr�sentes sur l'axe y, on lit*/
	if ((tmp&0x09)==0x09) axe_x=lec_i2c(ACC,0x29);/*Si des nouvelles donn�es sont pr�sentes sur l'axe x, on lit*/

	datax = axe_x*18; /*multiplication par 18 (car FS byte � 0, c�d full scale � 2g) pour l'avoir en g, 1 correspond � 18mg*/
	datay = axe_y*18;
	dataz = axe_z*18;
	
	
	lcd_gotoxy(1,2);//Endroit du lcd o� on va afficher (2e ligne) (x=colonne y=ligne)
	printf(lcd_char,"X%ld Y%ld Z%ld  ",datax,datay,dataz);//Affichage sur le lcd

}

void main () {

		//Demarrage du lcd
		lcd_init();
	   	lcd_char("\fProjet GPS-PIC\n");
		lcd_char("(C)FPMS - 2008");
		delay_ms(1000);	
	
		//D�but de la mesure sur l'acc�l�rom�tre
		lcd_char("\fLecture I2c...");
		delay_ms(300);	
		lcd_cursor(0);//Curseur d'une forme particuli�re
		
		//Affichage sur le lcd des mesures de l'acc�l�rom�tre
		while(1) {
		
			lecture_ACC();//Lecture Acc�l�rom�tre I2C
			delay_ms(300);
			
		}	
		

}
