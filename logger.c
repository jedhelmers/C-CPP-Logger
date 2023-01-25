#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include "stdbool.h"

char* unsignedIntToLogTypeString(unsigned type){
    switch (type)
    {
    case 0:
        return (char *)"INFO";
    case 1:
        return (char *)"DEBUG";
    case 2:
        return (char *)"WARNING";
    case 3:
        return (char *)"ERROR";
    case 4:
        return (char *)"FATAL";
    default:
        return (char *)"DEBUG";
    }
}

void SETUP_LOGGER() {}

int shouldDisableLogging(unsigned tag) {
    if(tag == 0 && DISABLE_INFO) {
        return 1;
    } else if(tag == 1 && DISABLE_DEBUG) {
        return 1;
    } else if(tag == 2 && DISABLE_WARNING) {
        return 1;
    } else if(tag == 3 && DISABLE_ERROR) {
        return 1;
    } else if(tag == 4 && DISABLE_FATAL) {
        return 1;
    }
    return 0;
}

pthread_mutex_t logger_mutex = PTHREAD_MUTEX_INITIALIZER;

void LOG(unsigned tag, const char* file, unsigned line, const char* message) {
    if (shouldDisableLogging(tag)) {
        return;
    }

    // pthread_mutex_t logger_mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&logger_mutex);

    FILE *fp;
    fp = fopen(FILENAME, "a");

    time_t now;
    time(&now);
    char *t = ctime(&now);

    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    if (t[strlen(t)-1] == '\n') t[strlen(t)-1] = '\0';

    fprintf(fp, "%s [%s]: %s:%d %s\n", buffer, unsignedIntToLogTypeString(tag), file, line, message);
    fclose(fp);
    pthread_mutex_unlock(&logger_mutex);
}
