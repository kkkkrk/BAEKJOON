#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>	
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[30][30], N;
vector<int> v;
queue<int> q;
void bfs(int a, int b) {
	if (a - 1 > 0 && map[a - 1][b] == 1) {
		q.push(a - 1);
		q.push(b);
		map[a - 1][b] = 0;
	}
	if (a + 1 <= N && map[a + 1][b] == 1) {
		q.push(a + 1);
		q.push(b);
		map[a + 1][b] = 0;
	}
	if (b - 1 > 0 && map[a][b - 1] == 1) {			
		q.push(a);
		q.push(b - 1);
		map[a][b - 1] = 0;
	}
	if (b + 1 <= N && map[a][b + 1] == 1) {
		q.push(a);
		q.push(b + 1);
		map[a][b + 1] = 0;
	}
}
int f(int x, int y) {
	int ans = 0;
	q.push(x);
	q.push(y);
	map[x][y] = 0;
	while (!q.empty()) {
		int size = q.size() / 2;
		for (int i = 0; i < size; i++) {
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			ans += 1;
			bfs(a, b);
		}
	}

	return ans;
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) v.push_back(f(i, j));
		}
	}

	cout << v.size();
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << "\n" << v[i];
	}

	return 0;
}