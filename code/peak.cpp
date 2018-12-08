#include "base.h"

//https://blog.csdn.net/JiuZhang_ninechapter/article/details/45669273


int findPeakSub(const vector<int> &vec, int start, int end)
{
	if (end == 0 || start == vec.size())
		return -1;
	
	int mid = (start + end) / 2;
	if (vec[mid] > vec[mid - 1] && vec[mid] > vec[mid + 1]) {
		return mid;
	}

	if (vec[mid - 1] > vec[mid]) {
		return findPeakSub(vec, start, mid - 1);
	}

	if (vec[mid + 1] > vec[mid]) {
		return findPeakSub(vec, mid + 1, end);
	}

	return -1;
}

int findPeak(const vector<int> &vec)
{
	return findPeakSub(vec, 0, vec.size() - 1);
}

int main()
{
	cout << findPeak({1,2,5,4,3,0,-1}) << endl;
	return 0;
}