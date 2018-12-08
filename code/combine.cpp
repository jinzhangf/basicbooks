#include "base.h"

bool cmp(int a, int b)
{
	char buf[1024];
	sprintf(buf, "%d", a);
	string strA(buf);
	sprintf(buf, "%d", b);
	string strB(buf);
	cout << (strA + strB) << " > " << (strB + strA) << " = " << ((strA + strB) > (strB + strA)) << endl;
	return (strA + strB) > (strB + strA);
}

int main()
{
	vector<int> vec({145, 45, 94, 941});
	sort(vec.begin(), vec.end(), cmp);
	for (auto val : vec) {
		cout << val << endl;
	}

	return 0;
}