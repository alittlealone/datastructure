//汉诺塔

#include <stdio.h>
#include <stdlib.h>

///@n   移动n个盘子
///@x   初始位置
///@y   中转位置
///@z   目标位置
void move(int n, char x, char y, char z) {
	if (n == 1) {
		printf("%c-->%c\n", x, z);
	}
	else {
		//将n-1个盘子从x通过z移到y
		move(n - 1, x, z, y);
		//将第n个盘子从x移动z
		printf("%c-->%c\n", x, z);
		//将n-1个盘子从y通过x移到z
		move(n - 1, y, x, z);
	}
}

int main() {
	int n;

	printf("请输入汉诺塔的层数：");
	sancf("%d", &n);
	printf("移动的步骤如下：\n");
	move(n, 'X', 'Y', 'Z');

	return 0;
}