/**
	额外空间复杂(SC):完成一个流程，需要用到多少辅助空间才能完成的流程;
	给定的输入不算额外空间;
	输出不算额外空间;
	已知输入数组A[7] = {'1','2','3','4','5','6','7'},将数组在原数组中调整为---6712345
	流程一：
		(1)给定输入数组A[N],定义左侧尺寸p,右侧尺寸q
		(2)定义额外空间大小为N-----SC = O(N)
	流程二：逆序法
		(1)...
		(2)在给定的数组上逆序法操作，定义两侧指针p、q；分别逆序
		(3)左侧数据逆序
		(4)右侧数据逆序
		(5)整体逆序
		(6)TC = O(1)

	File Name:inverse sort.c
	Author:Wangyf
	Format:.c
	Date:2018/3/27
**/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N		9		//数组大小
#define	RANGE	100		//元素取值范围1-RANGE
#define Lsize   3
#define Rsize   6

//随机数组发生器
int generateRandomArray(int arr[N]) {
	int i;
	
	srand((unsigned)time(NULL));		//用时间做种，每次产生的随机数不一样
	for (i = 0; i < N; i++) {
		arr[i] = rand() % RANGE + 1;		//生成1-RANGE范围的随机数
		printf("%d ", arr[i]);
	}
	return 0;

}

int main(void) {
	int i;
	int var;
	int arr[N];
	int *p = NULL;
	int *q = NULL;

	generateRandomArray(arr);
	printf("\n");

	//左侧逆序
	p = arr;
	q = arr + (Lsize - 1);
	//printf("p = %d, q = %d\n", *p, *q);
	for (i = 0; i < (Lsize / 2); i++) {
		var = *(p + i);
		arr[i] = *(q-i);
		arr[Lsize - 1 - i] = var;
	}
	for (i = 0; i < Lsize; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");


	//右侧逆序
	p = arr + Lsize;
	q = arr + N - 1;
	//printf(" %d, %d\n", *p, *q);
	for (i = 0; i < (Rsize / 2); i++) {
		var = *(p + i);
		arr[i + Lsize] = *(q - i);
		arr[N - 1 - i] = var;
	}
	for (i = Lsize; i < N; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");


	//整体逆序
	p = arr;
	q = arr + N - 1;
	//printf(" %d, %d\n", *p, *q);
	for (i = 0; i < (N / 2); i++) {
		var = *(p + i);
		arr[i] = *(q - i);
		arr[N - 1 - i] = var;
	}

	printf("逆序后:");
	for (i = 0; i < N; i++) {
		printf("%d,", arr[i]);
	}

	return 0;
}