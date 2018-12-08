#include "base.h"
#include <time.h>

char produce()
{
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}

	int num = rand() % 7;
	if (num < 2) {
		return 'A';
	}
	else if (num < 4) {
		return 'B';
	}
	else {
		return 'C';
	}

	return '-';
}

int main()
{
	map<char, int> table;
	for (int i = 0; i < 700000; ++i) {
		table[produce()]++;
	}

	for (auto &item : table) {
		cout << item.first << ":" << item.second << endl;
	}
	return 0;
}