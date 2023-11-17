#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;
extern int getAverageDelay(double alpha);

AnalogIn pot(AN_POT_PIN);
AnalogIn ldr(AN_LDR_PIN);
DigitalOut redLED(TRAF_RED1_PIN);
PwmOut blueLED(LED2);
LCD_16X2_DISPLAY disp;
PwmOut dispBackLight(LED1);

int main()
{
    //Configure the PWM for the backlight 
    dispBackLight.period(0.001f);   // 1ms
    dispBackLight.write(1.0);       // 100% duty
    blueLED.period(0.001f);
    blueLED.write(1.0);

    //Update display
    disp.cls();
    disp.printf("PwmOut");

    //Implement a delay (BLOCKING)
    wait_us(2000000);

    //Update display
    disp.locate(1, 0);
    disp.printf("Turn the POT");

    //Implement another delay (BLOCKING)
    wait_us(2000000);

    //Timer for the pot
    Timer tmr;
    tmr.start();

    while(true) {
        
        //Once every 100ms, re-read the POT and update the duty
        if ((tmr.elapsed_time() >= 250ms) && (ldr <= 9000)) {
            float u = pot;              // Every 250ms, read the pot... 
            float x = ldr;
            dispBackLight.write(x && u);     // ... and update the brightness.
            blueLED.write(x && u);
            tmr.reset();

            wait_us(1000000);

            disp.cls();
            disp.printf("POT = %f", u);
            disp.locate(1, 0);
            disp.printf("LDR = %f", x);
        }
        
        //Other non-blocking code could go here
        
    }

}




