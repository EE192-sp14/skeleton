#include "mbed.h"
#include "nbprint.h"

DigitalOut led(LED_BLUE);


int main() {
    nbprint_setup();
    while(1) {
        nbprint("HELLO\r\n");
        led = 1;
        wait(0.25);
        led = 0;
        wait(0.25);
    }
}
