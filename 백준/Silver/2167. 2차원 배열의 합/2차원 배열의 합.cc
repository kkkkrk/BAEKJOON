#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, M, K;
	vector<vector<int>> map;
	vector<vector<int>> v;
	vector<vector<int>> q;
	cin >> N >> M;
	map.assign(303, vector<int>(303, 0));
	v.assign(303, vector<int>(303, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> K;
	q.assign(10001, vector<int>(5, 0));
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> q[i][j];
			q[i][j] -= 1;
		}
	}
	v[0][0] = map[0][0];
	for (int i = 1; i < N; i++) {
		v[i][0] = v[i - 1][0] + map[i][0];
	}
	for (int i = 1; i < M; i++) {
		v[0][i] = v[0][i -1] + map[0][i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int ans = 0;
		if (q[i][0] == 0 && q[i][1] == 0) {
			ans = v[q[i][2]][q[i][3]];
		}
		else if (q[i][0] == 0 && q[i][1] > 0) {
			ans = v[q[i][2]][q[i][3]] - v[q[i][2]][q[i][1] - 1];
		}
		else if (q[i][0] > 0 && q[i][1] == 0) {
			ans = v[q[i][2]][q[i][3]] - v[q[i][0] - 1][q[i][3]];
		}
		else {
			ans = v[q[i][2]][q[i][3]] + v[q[i][0] - 1][q[i][1] - 1] - v[q[i][2]][q[i][1] - 1] - v[q[i][0] - 1][q[i][3]];
		}
		cout << ans << "\n";
	}

	return 0;
}