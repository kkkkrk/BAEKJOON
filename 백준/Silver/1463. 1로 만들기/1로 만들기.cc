#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
	int N;
	vector<int> v;
	cin >> N;

	v.push_back(INT_MAX);
	v.push_back(0);

	for (int i = 2; i <= N; i++) {
		int a = v[0], b = v[0], c = v[0];
		if (i % 3 == 0) a = v[i / 3];
		if (i % 2 == 0) b = v[i / 2];
		c = v[i - 1];
		int min = a;
		if (min > b) min = b;
		if (min > c) min = c;
		v.push_back(min + 1);
	}

	cout << v[N];


	return 0;
}