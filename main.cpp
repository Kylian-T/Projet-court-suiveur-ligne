#include "mbed.h"
#include <math.h>
 
PwmOut E1(p22);
PwmOut E2(p23);
PwmOut M1(p21);
PwmOut M2(p24);
InterruptIn button(D3);
DigitalOut led(LED1);
DigitalOut flash(LED4);

AnalogIn photoresistor1(p20);
AnalogIn photoresistor2(p19);
AnalogIn photoresistor3(p18);
AnalogIn photoresistor4(p17);
AnalogIn photoresistor5(p16);

int max_vol[5];
int min_vol[4];


void read_photoresistor(int * vol) {

    vol[0] = floor(photoresistor1.read()*100);
	vol[1] = photoresistor2.read();
	vol[2] = photoresistor3.read();
	vol[3] = photoresistor4.read();
	vol[4] = photoresistor5.read();

}

int read_line(float * vol) {



}

 
int main() {
		
    float vol[5];
	E1 = 0.2f;
	E2 = 0.2f;
	M1 = 0;
	M2 = 1;
	
	while(1){
		
		
		float vol1 = photoresistor1.read();
		float vol2 = photoresistor2.read();
		float vol3 = photoresistor3.read();
		float vol4 = photoresistor4.read();
		float vol5 = photoresistor5.read();
		if (vol1 == vol2) {
			E1 = 0.8f;
			E2 = 0.8f;
		} else if (vol1 > vol2){
			E1 = 0.0f;
			E2 = 0.8f;
		} else {
			E1 = 0.8f;
			E2 = 0.0f;
		}
		wait(0.5);
		
	}
	
}
