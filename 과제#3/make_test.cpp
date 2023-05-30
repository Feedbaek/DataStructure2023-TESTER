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
#include <experimental/filesystem>
#define EASY 10
#define HARD 200

using namespace std;

int case_num;

void TEST(int n, int m, int k, int p, int w, FILE *fp, mt19937 &rng) {
	int edges[202][202] = {};
	string line;
	int u, v, c, s, t;

	line = to_string(n) + " ";
	line += to_string(m) + " ";
	line += to_string(k) + " ";
	line += to_string(p) + "\n";

	fputs(line.c_str(), fp);

	for (int j=0; j<m; ++j) {
		do {
			u = (rng() % n) + 1;
			v = (rng() % n) + 1;
			c = (rng() % w) + 1;
		} while (u == v || edges[u][v] != 0);
		edges[u][v] = c;
		line = to_string(u) + " ";
		line += to_string(v) + " ";
		line += to_string(c) + "\n";
		fputs(line.c_str(), fp);
	}
	for (int j=0; j<p; ++j) {
		s = (rng() % n) + 1;
		t = (rng() % n) + 1;
		line = to_string(s) + " ";
		line += to_string(t) + "\n";
		fputs(line.c_str(), fp);
	}
}

int main(int argc, char** argv) {
	int n, m, k, p, u, v, c, s, t;
	string line;

	case_num = atoi(argv[1]);
	random_device rd;
	mt19937 rng(rd());

	for (int i=1; i<=case_num; ++i) {
		string txt = "./myInput/myInput" + to_string(i) + ".txt";
		FILE *fp = fopen(txt.c_str(), "w");

		if (i <= case_num / 5) {
			n = 5; m = 7; k = 2; p = 3;
			TEST(n, m, k, p, 10, fp, rng);
		}
		else {
			n = 200; m = 10000; k = 100; p = 10000;
			TEST(n, m, k, p, 1000000, fp, rng);
		}
		fclose(fp);
	}
	return 0;
}
