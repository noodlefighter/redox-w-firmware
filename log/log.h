#ifndef LOG_H_
#define LOG_H_

#include <stdint.h>

//todo: log lv
#ifdef LOG_MODULE_LV
#else
    #define _LOG_LV
#endif

#define LOG_EN      1


#ifdef LOG_EN
    #define LOG_ERR(fmt, ...)     log_printf(fmt, ##__VA_ARGS__)
    #define LOG_INF(fmt, ...)     log_printf(fmt, ##__VA_ARGS__)
    #define LOG_WRN(fmt, ...)     log_printf(fmt, ##__VA_ARGS__)
    #define LOG_DBG(fmt, ...)     log_printf(fmt, ##__VA_ARGS__)
    #define LOG_BST(fmt, ...)     log_printf(fmt, ##__VA_ARGS__)
#else
    #define LOG_ERR(fmt, ...)     ((void)0)
    #define LOG_INF(fmt, ...)     ((void)0)
    #define LOG_WRN(fmt, ...)     ((void)0)
    #define LOG_DBG(fmt, ...)     ((void)0)
    #define LOG_BST(fmt, ...)     ((void)0)
#endif

#define LOG     LOG_INF

/*
#if ASSERT_EN
    #define STRIPPATH(s)\
        (sizeof(s) > 2 && (s)[sizeof(s)-2] == '/' ? (s) + sizeof(s) - 1 : \
        sizeof(s) > 3 && (s)[sizeof(s)-3] == '/' ? (s) + sizeof(s) - 2 : \
        sizeof(s) > 4 && (s)[sizeof(s)-4] == '/' ? (s) + sizeof(s) - 3 : \
        sizeof(s) > 5 && (s)[sizeof(s)-5] == '/' ? (s) + sizeof(s) - 4 : \
        sizeof(s) > 6 && (s)[sizeof(s)-6] == '/' ? (s) + sizeof(s) - 5 : \
        sizeof(s) > 7 && (s)[sizeof(s)-7] == '/' ? (s) + sizeof(s) - 6 : \
        sizeof(s) > 8 && (s)[sizeof(s)-8] == '/' ? (s) + sizeof(s) - 7 : \
        sizeof(s) > 9 && (s)[sizeof(s)-9] == '/' ? (s) + sizeof(s) - 8 : \
        sizeof(s) > 10 && (s)[sizeof(s)-10] == '/' ? (s) + sizeof(s) - 9 : \
        sizeof(s) > 11 && (s)[sizeof(s)-11] == '/' ? (s) + sizeof(s) - 10 : (s))

    #define __JUSTFILE__ STRIPPATH(__FILE__)

    #define ASSERT(e)       ((e) ? (void)0 : log_assert(__JUSTFILE__, __LINE__))
#else
    #define ASSERT(e)       ((void)0)
#endif
*/

#ifdef __cplusplus
extern "C"
{
#endif


void log_init(void);
void log_printf(const char *fmt, ...);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LOG_H_ */
