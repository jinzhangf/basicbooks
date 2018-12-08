#include "base.h"

int second_max(const vector<int> &vec)
{
	if (vec.size() < 2) return -1;

	int max = vec[0] > vec[1] ? vec[0] : vec[1];
	int sec_max = vec[0] < vec[1] ? vec[0] : vec[1];

	for (int i = 2; i < vec.size(); ++i) {
		if (vec[i] >= max) {
			sec_max = max;
			max = vec[i];
		}
		else if (vec[i] > sec_max) {
			sec_max = vec[i];
		}
	}

	return sec_max;
}

int main()
{
	cout << second_max({3, 5, 6, 1, 2, 8, 7, 9}) << endl;
	return 0;
}