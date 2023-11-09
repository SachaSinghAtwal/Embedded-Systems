#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;
int sum = 0;

int main()
{
    unsigned short samples[100];
    //int mean;
    //int sum = 0;

    for (unsigned int m=0; m<100; m++) {
        printf(" %X ", samples[m]);
    }

    // Automatic headlamp 
    //while (true) {
    for (unsigned int m=0; m<100; m++) {
        unsigned short ldrVal   = ldr.read_u16();
        samples[m] = ldrVal;
        wait_us(10000);          // 10ms
        sum = sum + samples[m];
    }

    float mean = float(sum) / float(100);

    printf("\nsum = %d\n", sum);
    printf("mean = %.1f\n", mean);

    while(true) {
        if (ldr.read_u16()<9000) {
        greenLED = 1;
        }
        else{
            greenLED = 0;
        }
    }

}  
//}


