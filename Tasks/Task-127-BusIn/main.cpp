#include "mbed.h"

 	BusIn bus(PG_0, PG_1, PG_2, PG_3);
    int Allbtns;
// BusIn bus(PG_0, PG_1, PG_2, PG_3);

DigitalOut redLED(PC_2); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    bus[2].mode(PinMode::PullDown);
    bus[3].mode(PinMode::PullDown);
    // Turn OFF the red LED
    redLED = 0;

    // bus[2].mode(PinMode::PullDown);
    // bus[3].mode(PinMode::PullDown);
    
        do {
            Allbtns = bus;
        } while (Allbtns < 15);

        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);

        do {
            //Read all inputs
            Allbtns = bus;
        } while (Allbtns > 0);

        //Wait for noise to settle
        wait_us(10000);
    }   



