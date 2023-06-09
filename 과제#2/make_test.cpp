#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#define EASY 10
#define HARD 1000000000000

using namespace std;

int case_num;

int main(int argc, char** argv) {
	long long s, l;

	case_num = atoi(argv[1]);
	random_device rd;
	mt19937 rng(rd());

	for (int i=1; i<=case_num; ++i) {
		string txt = "./myInput/myInput" + to_string(i) + ".txt";
		FILE *fp = fopen(txt.c_str(), "w");

		if (i <= case_num / 3) {
			s = (rng() % EASY) + 1;
			l = (rng() % EASY) + 1;
		}
		else {
			s = (rng() % HARD) + 1;
			l = (rng() % 100000) + 1;
		}

		fputs((to_string(s) + " " + to_string(l) + "\n").c_str(), fp);
		fclose(fp);
	}
	return 0;
}
