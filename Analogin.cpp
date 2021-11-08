#include "Analogin.h"
#include<sstream>
#include<fstream>
using std::stringstream;
using std::fstream;


Analogin::Analogin(){
   this->number = 0;
}

Analogin::Analogin(unsigned int n){
   this->number = n;
}

void Analogin::setNumber(unsigned int n){
   this->number = n;
}

int Analogin::readADCsample(){
   stringstream ss;
   ss << ADC_PATH << this->number << "_raw";
   int val;
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> val;
   fs.close();
   return val;
}

float Analogin::getTempC(int adc_value) {     // from the TMP36 datasheet
   float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
   return (25.0f + diff_degreesC);
}

float Analogin::getTempF(int adc_value) {     // from the TMP36 datasheet
   float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
   float fahr = 32 + (((25.0f + diff_degreesC) * 9)/5);    // convert deg. C to deg. F
   return fahr;
}

Analogin::~Analogin(){

}
