#include "NBPrint.h"

Serial serial(SERIALTX, SERIALRX);
Ticker nb_printer;

char printbuffer[PRNBUFSZ];
int prnbuf_count = 0; // number of characters in buffer
int prnbuf_pos = 0; // location to store characters

void print_fn() {
  char c;
  int index;
  if (prnbuf_count > 0) { // there are characters to print
    index = prnbuf_pos - prnbuf_count;
    if (index < 0) {
      index = index + PRNBUFSZ; // wrap around
    }
    c = printbuffer[index];

    if (serial.writeable()) { // check in COMTX is empty (ready)
      serial.putc(c);
      prnbuf_count--;
    }
  }
}

void putchar_buf(char c) {
  if (prnbuf_count >= PRNBUFSZ) {
      return; // no room - drop character
  }
  printbuffer[prnbuf_pos] = c;
  prnbuf_pos++;
  prnbuf_count++; // need to make uninterruptable?
  if (prnbuf_pos > (PRNBUFSZ-1)) {
      prnbuf_pos = 0; // wrap index to beginning of buffer
  }
}

void nbprint(const char *format, ...) {
  int i = 0;
  while (true) {
    char c = format[i];
    if (c == '\0') {
      break;
    }
    putchar_buf(c);
    i += 1;
  }
}

void nbprint_setup() {
  serial.printf("Setting up non-blocking print...\r\n");
  nb_printer.attach_us(&print_fn, NBPRINT_US);
  nbprint("Non-blocking print setup complete!\r\n");
}
