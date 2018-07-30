#include <stdio.h>
#include <memory.h>
#include <time.h>
using namespace std;

int main()
{
	long long SIZE = 1024LL * 1024 * 1024;
	int TIMES = 200;
	char *s = new char [SIZE];
	char *d = new char [SIZE];

	timespec ts = {};
	timespec ts2 = {};
	memcpy(d, s, SIZE);

	clock_gettime(CLOCK_MONOTONIC, &ts);
	for (int i=0; i < TIMES; i++) {
		memcpy(d, s, SIZE);
	}
	clock_gettime(CLOCK_MONOTONIC, &ts2);
	long long ns = (ts2.tv_sec - ts.tv_sec) * 1000LL*1000*1000 + (ts2.tv_nsec - ts.tv_nsec);
	double sec = double(ns) / (1000LL*1000*1000);
	double gps = double(SIZE * TIMES) / sec / 1024 / 1024 / 1024;
	printf("%.2fGB/s %.1fsec\n", gps, sec);
}

