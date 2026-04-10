#include <iostream>
#include <vector>
using namespace std;

int N = 8; // 체스판 크기
int result = 0;

bool isSafe(const vector<int>& board, int row, int col) {
    // 같은 열 체크
    for (int i = 0; i < row; i++) {
        if (board[i] == col || // 같은 열
            board[i] - i == col - row || // 대각선
            board[i] + i == col + row) { // 반대 대각선
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int row) {
    if (row == N) { // 모든 퀸이 배치된 경우
        result += 1;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         if (board[i] == j) {
        //             cout << "Q ";
        //         } else {
        //             cout << ". ";
        //         }
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // 퀸을 배치
            solveNQueens(board, row + 1); // 다음 행으로 재귀 호출
            board[row] = -1; // 백트래킹: 퀸을 제거
        }
    }
}

int main() {
    cin >> N;
    vector<int> board(N, -1); // 체스판 초기화
    // cout << "8퀸 문제의 모든 해결책:\n";
    solveNQueens(board, 0);
    cout << result;
    return 0;
}
