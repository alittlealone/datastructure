//��ŵ��

#include <stdio.h>
#include <stdlib.h>

///@n   �ƶ�n������
///@x   ��ʼλ��
///@y   ��תλ��
///@z   Ŀ��λ��
void move(int n, char x, char y, char z) {
	if (n == 1) {
		printf("%c-->%c\n", x, z);
	}
	else {
		//��n-1�����Ӵ�xͨ��z�Ƶ�y
		move(n - 1, x, z, y);
		//����n�����Ӵ�x�ƶ�z
		printf("%c-->%c\n", x, z);
		//��n-1�����Ӵ�yͨ��x�Ƶ�z
		move(n - 1, y, x, z);
	}
}

int main() {
	int n;

	printf("�����뺺ŵ���Ĳ�����");
	sancf("%d", &n);
	printf("�ƶ��Ĳ������£�\n");
	move(n, 'X', 'Y', 'Z');

	return 0;
}