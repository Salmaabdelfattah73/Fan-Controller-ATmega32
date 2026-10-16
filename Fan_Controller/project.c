#include "dc_motor.h"
#include "LCD.h"
#include "lm.h"
#include "adc.h"

int main(void)
{
	ADC_ConfigType ADC_Config;
	ADC_Config.ref_volt=INTERNAL_AREF;
	ADC_Config.prescalar=8;
	ADC_init(&ADC_Config);
	LCD_init();
	DcMotor_init();
	uint8 tem;
	LCD_displayStringRowColumn(1,5,"Temp =    C");
	while(1){
	    tem = LM35_GetTemperature();
	    if(tem<100)
	    {
	    	LCD_moveCursor(1,13);
	    	LCD_displayCharacter(' ');
	    }
	    if(tem<10)
	    {
	    	LCD_moveCursor(1,12);
	    	LCD_displayCharacter(' ');
	    }
	    LCD_moveCursor(1,11);
	    LCD_intgerToString(tem);
	    if(tem<30)
	    {
	    	DcMotor_Rotate(stop,0);
	    	LCD_displayStringRowColumn(0,5,"FAN is OFF");

	    }
	    else if(tem>=30 && tem<60)
	    {
	    	DcMotor_Rotate(clock_wise,25);
	    	LCD_displayStringRowColumn(0,5,"FAN is ON");
	    	LCD_displayCharacter(' ');

	    }
	    else if(tem>=60 && tem<90)
	    {
	    	DcMotor_Rotate(clock_wise,50);
	    	LCD_displayStringRowColumn(0,5,"FAN is ON");
	    	LCD_displayCharacter(' ');

	    }
	    else if(tem>=90 && tem<120)
	    {
	    	DcMotor_Rotate(clock_wise,75);
	    	LCD_displayStringRowColumn(0,5,"FAN is ON");
	    	LCD_displayCharacter(' ');
	    }
	    else if(tem>=120)
	    {
	    	DcMotor_Rotate(clock_wise,100);
	    	LCD_displayStringRowColumn(0,5,"FAN is ON");
	    	LCD_displayCharacter(' ');
	    }


	}
	return 0;
}



