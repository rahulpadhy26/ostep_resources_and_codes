#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime()
{
    /*
     * The struct timeval structure represents an elapsed time - its declared in sys/time.h and has the following memebrs :
     * long int tv_sec -> This represents the number of whole seconds of elapsed time.
     * long int tv_usec -> This is the rest of the elapsed time (a fraction of a second), represented as the number of micro-seconds, its always less than a million.
    */
    struct timeval t;
    /*
     * int gettimeofday(struct timeval *tp, struct timezone *tz)
     * This function gets the system's clock time.
     * The current time is expressed in elapsed secondsw and microseconds since 00:00:00, January 1, 1970 (Unix Epoch)
     * The 2nd arguments, i.e., the timezone structure is obsolete, hence its set to NULL - the argument is only for backwards compatibility.
     * On success, rc = 0; on failure, rc = -1.
    */
    int rc = gettimeofday(&t, NULL);
    assert (rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec / 1e6;
}

void Spin(int howlong)
{
    double t = GetTime();
    while((GetTime() - t) < (double) howlong)
        ; // do nothing in loop
}

#endif // __common_h__
