#include <avr/io.h>
#include "adc.h"
#include "common_macros.h"

void ADC_init(const ADC_ConfigType* Config_ptr)
{
	//configuration of ADC with polling
	if(Config_ptr->ref_volt==INTERNAL_AREF)
	{
		ADMUX = (1<<REFS0)|(1<<REFS1);
	}
	else if(Config_ptr->ref_volt==AVCC)
	{
		ADMUX = (1<<REFS0);
	}
	else
	{
		ADMUX=0;
	}
	switch(Config_ptr->prescalar){
	case 2:
		ADCSRA =(1<<ADEN);
		break;
	case 4:
		ADCSRA =(1<<ADPS1)|(1<<ADEN);
		break;
	case 8:
		ADCSRA =(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
		break;
	case 16:
		ADCSRA =(1<<ADPS2)|(1<<ADEN);
		break;
	case 32:
		ADCSRA =(1<<ADPS0)|(1<<ADEN);
		break;
	case 64:
		ADCSRA =(1<<ADPS1)|(1<<ADPS2)|(1<<ADEN);
		break;
	case 128:
		ADCSRA =(1<<ADPS1)|(1<<ADPS0)|(1<<ADPS2)|(1<<ADEN);
		break;
	}

}

uint16 ADC_readChannel(uint8 num_of_channel)
{
	ADMUX= ADMUX &(0xE0);
	num_of_channel=num_of_channel &(0x07);
	ADMUX|=num_of_channel;
	SET_BIT(ADCSRA,ADSC);                  //convert data from the analog to digital
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);               //clear the flag to the next time
	return ADC;
}
