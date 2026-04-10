#include <iostream>
using namespace std;
int A[12];
int main()
{
	int T,t[1001];

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> t[i];
	}

	A[1] = 1;
	A[2] = 2;
	A[3] = 4;

	for (int i = 4; i <= 11; i++) {
		A[i] = A[i - 1] + A[i - 2] + A[i - 3];
	}

	for (int i = 1; i <= T; i++) {
		cout << A[t[i]] << "\n";
	}

	return 0;
}