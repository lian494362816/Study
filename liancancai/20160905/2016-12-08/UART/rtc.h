
/*
 * Generic RTC interface.
 */
#ifndef _RTC_H_
#define _RTC_H_

/* bcd<->bin functions are needed by almost all the RTC drivers, let's include
 * it there instead of in evey single driver */

#include "bcd.h"

/*
 * The struct used to pass data from the generic interface code to
 * the hardware dependend low-level code ande vice versa. Identical
 * to struct rtc_time used by the Linux kernel.
 *
 * Note that there are small but significant differences to the
 * common "struct time":
 *
 *		struct time:		struct rtc_time:
 * tm_mon	0 ... 11		1 ... 12
 * tm_year	years since 1900	years since 0
 */

struct rtc_time {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

#define    BCDDATE(X)	(((X)&0xF)+(((X)>>4)&0xF)*10)
#define    DATEBCD(X)	(((X)%10) | (((X)/10)<<4))

void read_RTC_date(void);
void set_RTC_date(void);
int rtc_get (struct rtc_time *);
int rtc_set (struct rtc_time *);
void rtc_reset (void);


#endif	/* _RTC_H_ */
