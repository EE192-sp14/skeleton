#include "mbed.h"
#include "rtos.h"
#include "MODSERIAL.h"

MODSERIAL serial(USBTX, USBRX);
DigitalOut led_blue(LED_BLUE);
DigitalOut led_red(LED_RED);


void led_blink_thread(void const *args) {
    led_blue = 1;
    Thread::wait(250);
    led_blue = 0;
    Thread::wait(250);
}


void led_blink(void const *args) {
    led_red = !led_red;
}


int main() {
    serial.printf("Hello world!\r\n");

    // Start threads
    Thread ledBlinkThread(led_blink_thread);
  
    // Start timers
    RtosTimer ledBlinkTimer(led_blink);
    ledBlinkTimer.start(500);

    while(1) { }
}
