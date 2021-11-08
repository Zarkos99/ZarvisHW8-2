#include "Analogin.h"
#include<iostream>
using std::cout;
using std::endl;
using std::string;

int main(){
	Analogin tmp36(0);

	cout << "Reading ADC: " << tmp36.getNumber() << endl;
	cout << "Current temperature: " << tmp36.getTempF(tmp36.readADCsample()) << endl;

}
