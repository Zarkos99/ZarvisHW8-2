/*
file name: analogIn.h
* Created by Amer Qouneh on October 30, 2020.
*
* This class wraps the functionality of analog input pins.
*/
#ifndef ANALOGIN_H_
#define ANALOGIN_H_

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

class Analogin{
private:
 unsigned int number;
 
public:
 Analogin();
 Analogin(unsigned int n);
 virtual unsigned int getNumber() {return number; } // inline function implementation.
 virtual void setNumber(unsigned int n);
 virtual int readADCsample();
 virtual float getTempC(int adc_value);
 virtual float getTempF(int adc_value);
 virtual ~Analogin();
};
#endif /* ANALOGIN_H_ */

