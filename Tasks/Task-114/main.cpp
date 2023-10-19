#include "mbed.h"

DigitalOut LEDred(PC_2,1);
DigitalOut LEDyel(PC_3,1);
DigitalOut LEDgrn(PC_6,1);

int main()
{

    wait_us(1000000);

    LEDgrn = 0;
    LEDyel = 0;

    while (true) {

        LEDred = 1;
        wait_us(2000000);

        LEDred = 1;
        LEDyel = 1;
        wait_us(2000000);

        LEDred = 0;
        LEDyel = 0;
        LEDgrn = 1;
        wait_us(2000000);

        LEDgrn = 0;
        int count = 0;
        while(count < 4)    {
        LEDyel = 1;
        wait_us(250000);
        LEDyel = 0;
        wait_us(250000);
        count = count + 1;
        }
    }
}

