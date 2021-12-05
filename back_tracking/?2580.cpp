// 스도쿠

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int board[9][9];

void col_check(int num, vector<int> check) {
	int cnt = 0, pos = -1, value = 0;
	for (int i = 0; i < 9; i++) {
		if (board[i][num] == 0) {
			pos = i;
			continue;
		}
		else {
			check[board[i][num]] = true;
			cnt++;
		}
	}

	if (cnt == 9) return;

	for (int i = 1; i < 10; i++) {
		if (check[i] == false) {
			value = i;
			break;
		}
	}

	if (cnt == 8) {
		board[pos][num] = value;
	}

}

void row_check(int num, vector<int> check) {
	int cnt = 0, pos = -1, value = 0;
	for (int i = 0; i < 9; i++) {
		if (board[num][i] == 0) {
			pos = i;
			continue;
		}
		else {
			check[board[num][i]] = true;
			cnt++;
		}
	}

	if (cnt == 9) return;

	for (int i = 1; i < 10; i++) {
		if (check[i] == false) {
			value = i;
			break;
		}
	}

	if (cnt == 8) {
		board[num][pos] = value;
	}
}

void box_check(int num, vector<int> check) {
	int cnt = 0, value=0, col = num / 3, row = num % 3;
	int col_pos, row_pos;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[col*3 + i][row*3 + j] == 0) {
				col_pos = col*3 + i, row_pos = row*3 + j;
				continue;
			}
			else {
				check[board[col*3 + i][row*3 + j]] = true;
				cnt++;
			}
		}
	}

	if (cnt == 9) return;

	for (int i = 1; i < 10; i++) {
		if (check[i] == false) {
			value = i;
			break;
		}
	}

	if (cnt == 8) {
		board[col_pos][row_pos] = value;
	}

}

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	vector<int> check(10,0);
	bool isClear = true;

	do {
		int cnt = 0;
		for (int i = 0; i < 9; i++) {
			row_check(i, check);
			col_check(i, check);
			box_check(i, check);
		}

		for (int i = 0; i < 9; i++) {
			if (find(board[i], board[i] + 9, 0) == &board[i][9])
				cnt += 1;
		}

		if (cnt == 9)
			isClear = false;
	} while (isClear);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}
