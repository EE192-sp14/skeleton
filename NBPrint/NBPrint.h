#ifndef NBPRINT_H
#define NBPRINT_H

#include "mbed.h"

#define PRNBUFSZ 0x1000
#define SERIALRX USBRX
#define SERIALTX USBTX
#define NBPRINT_US 5000

void nbprint_setup();
void nbprint(const char *format, ...);

#endif
