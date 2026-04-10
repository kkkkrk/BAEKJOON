#include <iostream>
#include <queue>
using namespace std;
int N, M, map[2000][2000];
queue<int> q;
void bfs(int i, int j, int L) {
	if (i - 1 > 0 && map[i - 1][j] == 0) {
		map[i - 1][j] = L + 1;
		q.push(i - 1);
		q.push(j);
	}
	if (i + 1 <= N && map[i + 1][j] == 0) {
		map[i + 1][j] = L + 1;
		q.push(i + 1);
		q.push(j);
	}
	if (j - 1 > 0 && map[i][j - 1] == 0) {
		map[i][j - 1] = L + 1;
		q.push(i);
		q.push(j - 1);
	}
	if (j + 1 <= M && map[i][j + 1] == 0) {
		map[i][j + 1] = L + 1;
		q.push(i);
		q.push(j + 1);
	}
}
int main()
{
	int flag = 1, L = 0;
	
	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(i);
				q.push(j);
			}
		}
	}

	while (!q.empty()) {
		L += 1;
		int size = q.size()/2;
		for (int i = 0; i < size; i++) {
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			bfs(a, b, L);
		}
	}

	int biggest = 0;
	flag = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) flag = 1;
			else if (map[i][j] > biggest) biggest = map[i][j];
		}
	}

	if (flag) cout << -1;
	else cout << biggest - 1;
	cout << endl;

	return 0;
}