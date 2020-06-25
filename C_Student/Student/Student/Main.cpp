#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct STUDENT
{
	char num[10];
	char name[10];
	int kor, eng, math, sum;
	double avg;
}score;

void swap(score* n, score* m);
int main(void)
{
	FILE* open;
	score people[100];
	score total = { "","",0,0,0,0,0 };
	int i = 0;

	open = fopen("Score.txt","r");

	if (open == NULL) {
		printf("해당 파일을 찾을 수 없습니다.\n");
		exit(1); //에러메시지 종료
	}

	while (1) {
		if (fscanf(open, "%s %s %d %d %d\n", people[i].num, people[i].name, &people[i].kor, &people[i].eng, &people[i].math) == EOF) {
			break;
		} //EOF = End Of File
		people[i].sum = people[i].kor + people[i].eng + people[i].math;
		people[i].avg = people[i].sum / 3;
		total.kor = total.kor + people[i].kor;
		total.eng = total.eng + people[i].eng;
		total.math = total.math + people[i].math;
		total.sum = total.sum + people[i].sum;
		total.avg = total.avg + people[i].avg;
		i++;
	}
	fclose(open);

	for (int n = 0; n < i - 1; n++) {
		for (int m = n + 1; m < i; m++) {
			if (people[n].sum < people[m].sum) {
				swap(&people[n], &people[m]);
			}
		}
	}
	printf("\n                             성적처리                        \n\n");
	printf("=======================================================================\n");
	printf("   학번      이름      국어      영어      수학      총점       평균 \n");
	printf("=======================================================================\n");
	for (int k = 0; k < i; k++) {
		//%7d 폭 = 7, 우측으로 출력 %7.2f 소수점 첫자리로 반올림
		printf("  %s  %12s  %8d  %8d  %8d  %8d  %8.1f\n",
			people[k].num, people[k].name, people[k].kor, people[k].eng, people[k].math, people[k].sum, people[k].avg);
	}
	printf("=======================================================================\n");
	printf("  과목당 평균 점수 %5.1f점  %5.1f점  %5.1f점   전체 평균 점수 %5.1f점\n",
		total.kor / (double)i, total.eng / (double)i, total.math / (double)i, total.avg / (double)i);
	printf("=======================================================================\n");
	return 0;
}

void swap(score* n, score* m)
{
	score temp;
	temp = *n;
	*n = *m;
	*m = temp;
}