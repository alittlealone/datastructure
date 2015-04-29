#include <stdio.h>
#include <stdlib.h>

int count = 0;

int Safe(int row, int j, int(*chess)[8]) {
	int i, k, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

	//判断列方向
	for (int i = 0; i < 8; i++) {
		if (*(*(chess + i) + j) != 0) {
			flag1 = 1;
			break;
		}
	}

	//判断左上方
	for (i = row, k = j; i >= 0 && k >= 0; i--, k--) {
		if (*(*(chess + i) + k) != 0) {
			flag2 = 1;
			break;
		}
	}

	//判断右下方
	for (i = row, k = j; i < 8 && k < 8; i++, k++) {
		if (*(*(chess + i) + k) != 0) {
			flag3 = 1;
			break;
		}
	}

	//判断右上方
	for (i = row, k = j; i >= 0 && k < 8; i--, k++) {
		if (*(*(chess + i) + k) != 0) {
			flag4 = 1;
			break;
		}
	}

	//判断左下方
	for (i = row, k = j; i < 8 && k >= 0; i++, k--) {
		if (*(*(chess + i) + k) != 0) {
			flag5 = 1;
			break;
		}
	}

	if (flag1 || flag2 || flag3 || flag4 || flag5)
		return 0;
	else
		return 1;

}

///@row            表示起始行
///@n              表示列数
///@(*chess)[8]    指向每一行的指针数组
EightQueens(int row, int n, int (*chess)[8]) {
	int chess2[8][8], i, j;

	//初始化临时棋盘
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			chess2[i][j] = chess[i][j];
		}
	}

	//row来到第8行，已经成功,打印棋盘
	if (row == 8) {
		printf("第%d种：\n", count + 1);
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				printf("%d ", *(*(chess2 + i) + j));
			}
			printf("\n");
		}
		printf("\n");
		cout++;
	}
	else {
		for (j = 0; j < n; j++) {
			//如果位置第row行第j列不危险
			if (Safe(row, j, chess)) {
				for (i = 0; i < 8; i++) {
					*(*(chess2 + row) + i) = 0;
				}
				*(*(chess2 + row) + j) = 1;
				EightQueens(row + 1, n, chess2);
			}
		}

	}


}

int main() {
	int chess[8][8], i, j;

	//初始化棋盘，有棋子为1，无棋子为0
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			chess[i][j] = 0;
		}
	}

	EightQueens(0, 8, chess);
	printf("总共有%d种解决方法\n", count);

	return 0;
}