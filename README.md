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

To run
```
gcc main.c logger.c
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

Usage
```
gcc main.c logger.c -DLOG_DISABLE_INFO -DLOG_DISABLE_DEBUG
```

| Flag | Info |
|---|---|
| -DLOG_FILENAME | Set filename.log |
| -DLOG_TIME_FORMAT | Set time format. |

Time formatting
| Specifier |	Replaced By	| Example |
|---|---|---|
| %a |	Abbreviated weekday name | Sun |
| %A |	Full weekday name | Sunday |
| %b |	Abbreviated month name | Mar |
| %B |	Full month name | March |
| %c |	Date and time representation	Sun Aug 19 02:56:02 | 2012 |
| %d |	Day of the month (01-31) | 19 |
| %H |	Hour in 24h format (00-23) | 14 |
| %I |	Hour in 12h format (01-12) | 05 |
| %j |	Day of the year (001-366) | 231 |
| %m |	Month as a decimal number (01-12) | 08 |
| %M |	Minute (00-59) | 55 |
| %p |	AM or PM designation | PM |
| %S |	Second (00-61) | 02 |
| %U |	Week number with the first Sunday as the first day of week one (00-53) | 33 |
| %w |	Weekday as a decimal number with Sunday as 0 (0-6) | 4 |
| %W |	Week number with the first Monday as the first day of week one (00-53) | 34 |
| %x |	Date representation | 08/19/12 |
| %X |	Time representation | 02:50:06 |
| %y |	Year, last two digits (00-99) | 01 |
| %Y |	Year | 2012 |
| %Z |	Timezone name or abbreviation | CDT |
| %% |	A % sign | % |

Usage
```
gcc main.c logger.c -DLOG_FILENAME="pimp_logging.log" -DLOG_TIME_FORMAT="%H:%M:%S"
```
