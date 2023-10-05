// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 
DigitalOut greenLED(PB_0);
Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
        //On for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 150);

        //Off for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 150);

        //On for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 450);

        //Off for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 450);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 150);

        //On for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 450);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 150);

        //Off for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 450);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 450);

        //On for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 150);

        //Off for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 150);

        //Off for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 150);  //500ms

        //Pause
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 900);
    }
}