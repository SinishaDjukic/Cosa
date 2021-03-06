#ifndef COSA_BOARD_PLATFORMIO_H
#define COSA_BOARD_PLATFORMIO_H

#if defined(ARDUINO_AVR_DIECIMILA)
#define ARDUINO_DIECIMILA
#elif #defined(ARDUINO_AVR_DUEMILANOVE)
#define ARDUINO_DUEMILANOVE
#elif defined(ARDUINO_AVR_LEONARDO)
#define ARDUINO_LEONARDO
#elif defined(ARDUINO_AVR_MEGA2560)
#define ARDUINO_MEGA
#elif defined(ARDUINO_AVR_MICRO)
#define ARDUINO_MICRO
#elif defined(ARDUINO_AVR_NANO)
#define ARDUINO_NANO
#elif defined(ARDUINO_AVR_PRO)
#define ARDUINO_PRO_MINI
#elif defined(ARDUINO_AVR_PROMICRO8)
#define ARDUINO_PRO_MICRO
#elif defined(ARDUINO_AVR_PROMICRO16)
#define ARDUINO_PRO_MICRO
#elif defined(ARDUINO_AVR_PRO_MINI)
#define ARDUINO_PRO_MINI
#elif defined(ARDUINO_AVR_UNO)
#define ARDUINO_UNO
#elif defined(ARDUINO_AVR_ATtinyX4)
#define BREADBOARD_ATTINYX4
#elif defined(ARDUINO_AVR_ATtinyX5)
#define BREADBOARD_ATTINYX5
#elif defined(ARDUINO_AVR_ATtinyX61)
#define BREADBOARD_ATTINYX61
#elif defined(ARDUINO_AVR_ATmega328)
#define BREADBOARD_ATMEGA328P
#elif defined(ARDUINO_AVR_ATmega1284)
#define BREADBOARD_ATMEGA1284P
#elif defined(ARDUINO_AVR_LILYPAD)
#define LILYPAD_ARDUINO
#elif defined(ARDUINO_AVR_LILYPAD_USB)
#define LILYPAD_ARDUINO_USB
#else
#error "Cosa: board not supported"
#endif

#endif
