#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

#include "uart.h"

#define UNITY_OUTPUT_START()       uart_start()
#define UNITY_OUTPUT_CHAR(c)       uart_putchar(c)
#define UNITY_OUTPUT_COMPLETE()    uart_stop()

#endif /* UNITY_CONFIG_H */
