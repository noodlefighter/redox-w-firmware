
#include "SEGGER_RTT.h"

#include "log.h"

void log_init(void)
{
    SEGGER_RTT_Init();
}

void log_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    SEGGER_RTT_printf(0, fmt, args);
    va_end(args);
}
