#ifndef LOGGER_H
#define LOGGER_H

#define INFO 0, __FILE__, __LINE__
#define DEBUG 1, __FILE__, __LINE__
#define WARNING 2, __FILE__, __LINE__
#define ERROR 3, __FILE__, __LINE__
#define FATAL 4, __FILE__, __LINE__

#define DISABLE_INFO 0
#define DISABLE_DEBUG 0
#define DISABLE_WARNING 0
#define DISABLE_ERROR 0
#define DISABLE_FATAL 0

#define FILENAME "sample.log"

#define Q(x) #x
#define QUOTE(x) Q(x)

#ifdef LOG_FILENAME
    #undef FILENAME
    #define FILENAME QUOTE(LOG_FILENAME)
#endif

#ifdef LOG_DISABLE_INFO
    #undef DISABLE_INFO
    #define DISABLE_INFO 1, __FILE__, __LINE__
#endif

#ifdef LOG_DISABLE_DEBUG
    #undef DISABLE_DEBUG
    #define DISABLE_DEBUG 1, __FILE__, __LINE__
#endif

#ifdef LOG_DISABLE_WARNING
    #undef LOSABLE_WARNING
    #define SABLE_WARNING 1, __FILE__, __LINE__
#endif

#ifdef LOG_DISABLE_ERROR
    #undef DISABLE_ERROR
    #define DISABLE_ERROR 1, __FILE__, __LINE__
#endif

#ifdef LOG_DISABLE_FATAL
    #undef DISABLE_FATAL
    #define DISABLE_FATAL 1, __FILE__, __LINE__
#endif

void LOG(unsigned tag, const char* file, unsigned line, const char* message);

void SETUP_LOGGER();

#endif
