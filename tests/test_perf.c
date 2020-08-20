#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "math/mt19937_32.h"
#include "math/mt19937_64.h"
#include "math/xorshift32.h"
#include "math/xorshift64.h"
#include "math/xoshiro256ss.h"

#define LOOPS 5555555

static inline uint64_t DiffTimeUsec(const struct timeval* end,
                                    const struct timeval* begin) {
    struct timeval tmp = *end;
    if (tmp.tv_usec < begin->tv_usec) {
        --tmp.tv_sec;
        tmp.tv_usec += 1000000;
    }
    return (tmp.tv_sec - begin->tv_sec) * 1000000 +
        (tmp.tv_usec - begin->tv_usec);
}

static void test_rand() {
    srand(31415926);

    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    for (int i = 0; i < LOOPS; ++i) {
        rand();
    }
    gettimeofday(&end, NULL);
    printf("rand() cost %f ms.\n", DiffTimeUsec(&end, &begin) / 1000.0);
}

static void test_xorshift32() {
    struct xorshift32 st;
    xorshift32_init(&st, 31415926);

    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    for (int i = 0; i < LOOPS; ++i) {
        xorshift32_rand(&st);
    }
    gettimeofday(&end, NULL);
    printf("xorshift32 cost %f ms.\n", DiffTimeUsec(&end, &begin) / 1000.0);
}

static void test_xorshift64() {
    struct xorshift64 st;
    xorshift64_init(&st, 31415926);

    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    for (int i = 0; i < LOOPS; ++i) {
        xorshift64_rand(&st);
    }
    gettimeofday(&end, NULL);
    printf("xorshift64 cost %f ms.\n", DiffTimeUsec(&end, &begin) / 1000.0);
}

static void test_xoshiro256ss() {
    struct xoshiro256ss st;
    xoshiro256ss_init(&st, 31415926);

    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    for (int i = 0; i < LOOPS; ++i) {
        xoshiro256ss_rand(&st);
    }
    gettimeofday(&end, NULL);
    printf("xoshiro256ss cost %f ms.\n", DiffTimeUsec(&end, &begin) / 1000.0);
}

static void test_mt19937_32() {
    struct mt19937_32 st;
    mt19937_init32(&st, 31415926);

    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    for (int i = 0; i < LOOPS; ++i) {
        mt19937_rand32(&st);
    }
    gettimeofday(&end, NULL);
    printf("mt19937_32 cost %f ms.\n", DiffTimeUsec(&end, &begin) / 1000.0);
}

static void test_mt19937_64() {
    struct mt19937_64 st;
    mt19937_init64(&st, 31415926);

    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    for (int i = 0; i < LOOPS; ++i) {
        mt19937_rand64(&st);
    }
    gettimeofday(&end, NULL);
    printf("mt19937_64 cost %f ms.\n", DiffTimeUsec(&end, &begin) / 1000.0);
}

int main(void) {
    test_rand();
    test_xorshift32();
    test_xorshift64();
    test_xoshiro256ss();
    test_mt19937_32();
    test_mt19937_64();
    return 0;
}
