#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "std_macros.h"
#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"
#include "SEVENSEGMENT.h"
#include "EEPROM.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "ADC.h"

int main()
{
	int temp;
	//float volt;
	ADC_initialize();
	LCD_initialize();
	LCD_writecmd(0x0c); //hide cursor
	LCD_writestring("Temp=");
	
	while(1)
	{
		/*		volt=(ADC_read()/400);
		volt=volt-1;
		
		if(volt>=0)
		{
			temp=volt*100;
			LCD_movecursor(1,6);
		}
		else if(volt<0)
		{
			temp=-1*volt*100;
			LCD_movecursor(1,6);
			LCD_writecharacter('-');
			LCD_movecursor(1,7);
		}
		*/
		
		temp=   (((float) ADC_read()/400.0) - 1.0)*100;
		
		LCD_movecursor(1,6);
		
		if(temp<0)
		{
			temp=-1*temp;
			LCD_writecharacter('-');
			LCD_movecursor(1,7);
		}
		
		
		if(temp<10)
		{
			
			LCD_writecharacter(temp+48);
			LCD_writecharacter(0xdf);
			LCD_writecharacter('c');
			LCD_writecharacter(0x20);
			LCD_writecharacter(0x20);
			LCD_writecharacter(0x20);
		}
		
		else if(temp<100)
		{
			
			LCD_writecharacter((temp/10)+48);
			LCD_writecharacter((temp%10)+48);
			LCD_writecharacter(0xdf);
			LCD_writecharacter('c');
			LCD_writecharacter(0x20);
			LCD_writecharacter(0x20);
		}
		
		else if(temp<150)
		{
			
			LCD_writecharacter((temp/100)+48);
			LCD_writecharacter(((temp/10)%10)+48);
			LCD_writecharacter((temp%10)+48);
			LCD_writecharacter(0xdf);
			LCD_writecharacter('c');

		}
	}
}









