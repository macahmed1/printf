#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

typedef struct Cspecs {
        char cs;
        void (*f)();
} cs_t;

int _printf(const char *format, ...);

#endif /* MAIN_H */


