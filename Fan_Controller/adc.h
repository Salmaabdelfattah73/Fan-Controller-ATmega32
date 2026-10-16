#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#define ADC_MAXIMUM_VALUE  1023
#define ADC_REF_VOLT  2.56
typedef uint8                ADC_Prescalar;

typedef enum{
	AREF_OFF,AVCC,INTERNAL_AREF
}ADC_ReverenceVolatge;

typedef struct{
	ADC_ReverenceVolatge ref_volt;
	ADC_Prescalar prescalar;
}ADC_ConfigType;


void ADC_init(const ADC_ConfigType* Config_ptr);
uint16 ADC_readChannel(uint8 num_of_channel);

#endif /* ADC_H_ */
