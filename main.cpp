#include "mbed.h"

DigitalOut led(LED_BLUE);
Serial serial(USBTX, USBRX);

int main() {
    serial.printf("Hello World!\n");
    while(1) {
        led = 1;
        wait(0.5);
        led = 0;
        wait(0.5);
    }
}
