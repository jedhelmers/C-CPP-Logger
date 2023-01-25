# C-CPP-Logger
Dead-simple logger for C/C++

I wanted to create a simple, thread-safe, single header-file logger for C/C++. It's easy to use. Easy to modify.

## Usage
```
#include "logger.h"

int main() {
  LOG(INFO, (char*)"Pimps up. Hoes down.");
  
  return 0;
}
```
Output
```
2023-01-25 13:47:23 [INFO]: main.c:4 Pimps up. Hoes down.
```

## Flags
Logs can be disabled per-env using the following disable flags:
| Flag | Info |
|---|---|
| -DLOG_DISABLE_INFO | Disable INFO logging. |
| -DLOG_DISABLE_DEBUG | Disable DEBUG logging. |
| -DLOG_DISABLE_WARNING | Disable WARNING logging. |
| -DLOG_DISABLE_ERROR | Disable ERROR logging. |
| -DLOG_DISABLE_FATAL | Disable FATAL logging. |

| Flag | Info |
|---|---|
| -DLOG_FILENAME | Set filename.log |
