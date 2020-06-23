#include <stdio.h>
#include <stdlib.h>
// C언어_성적 처리 프로그램
// 성적 처리할 학생들의 정보들이 있는 텍스트 파일을 불러와 분석한다.
// 100명 이하의 학생들을 처리
// 학생들의 학번, 이름, 국어, 영어, 수학 성적을 입력받는다.
// 각 학생의 총점과 평균, 각 과목의 평균을 출력한다.
// 출력은 총점이 높은 순(등수 순)으로 한다.

typedef struct STUDENT
{
	char num[10];
	char name[10];
	int kor, eng, math, sum;
	double avg;
}score;