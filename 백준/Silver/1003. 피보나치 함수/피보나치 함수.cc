    #include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T, ans[43][2];
	cin >> T;

	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		ans[i][0] = ans[i - 1][0] + ans[i - 2][0];
		ans[i][1] = ans[i - 1][1] + ans[i - 2][1];
	}

	for (int i = 0; i < T; i++) {
		int a;
		cin >> a;
		cout << ans[a][0] << " " << ans[a][1] << "\n";
	}

	return 0;
}