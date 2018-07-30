#include <windows.h>
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

	auto	t1 = GetTickCount64();

	for (int i=0; i < TIMES; i++) {
		memcpy(d, s, SIZE);
	}
	auto	t2 = GetTickCount64();

	auto	diff = t2 - t1;
	double sec = double(diff) / 1000LL;
	double gps = double(SIZE * TIMES) / sec / 1024 / 1024 / 1024;
	printf("%.2fGB/s %.1fsec\n", gps, sec);
}

