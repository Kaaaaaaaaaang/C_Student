#include <stdio.h>
#include <stdlib.h>
// C���_���� ó�� ���α׷�
// ���� ó���� �л����� �������� �ִ� �ؽ�Ʈ ������ �ҷ��� �м��Ѵ�.
// 100�� ������ �л����� ó��
// �л����� �й�, �̸�, ����, ����, ���� ������ �Է¹޴´�.
// �� �л��� ������ ���, �� ������ ����� ����Ѵ�.
// ����� ������ ���� ��(��� ��)���� �Ѵ�.

typedef struct STUDENT
{
	char num[10];
	char name[10];
	int kor, eng, math, sum;
	double avg;
}score;

int main(void)
{
	FILE* open;
	score people[100];
	score total = { "","",0,0,0,0,0 };

	open = fopen("Score.txt","r");

	if (open == NULL) {
		printf("�ش� ������ ã�� �� �����ϴ�.\n");
		exit(1); //�����޽��� ����
	}
}