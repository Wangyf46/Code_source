/**
递归过程:利用栈自己调用自己;栈--先进后出

问题描述:已知数组arr[N]，将数组分为左右两侧，利用递归找到每一册的最大值m，逐次划分左右两侧逼近，最终找到最大值
流程:
(1)定义一个递归函数，f(0, N-1)找其区间内最大值
(2)子过程1:f(0,N/2)----maxL，左侧最大值
(3)子过程2:f(N/2 + 1, N-1)-----maxR，右侧最大值
.....
(4)比较maxL与maxR，未f(0,N-1)返回最大值max

递归过程需要注意的问题:写递归的时候一定先写base case；base case是递归的终止条件，不需要继续划分了

**/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define		N		10
#define     RANGE	100



/* 随机数组发生器 */
void generateRandomArray(int arr[N]) {
	int i;
	srand((unsigned)time(NULL));						//用时间做种，每次产生的随机数不一样
	for (i = 0; i < N; i++) {
		arr[i] = rand() % RANGE + 1;					//生产1-RANGE范围的随机数
		printf("%d, ", arr[i]);
	}
	printf("\n");
}


/* 数组值复制 */
void copyArray(int arr1[N], int arr2[N]) {
	int i;
	printf("arr2[%d] = {", N);
	for (i = 0; i < N; i++) {
		arr2[i] = arr1[i];
		printf("%d,", arr2[i]);
	}
	printf("}\n");
}

/* 递归函数寻找最大值 */
int funMax(int arr[N], int indexL, int indexR) {
	int mid, maxL, maxR;

	//递归过程的base case
	if (indexL == indexR)
		return arr[indexL];
	mid = indexL + (indexR - indexL) / 2;//////
	maxL = funMax(arr, indexL, mid);
	maxR = funMax(arr, mid + 1, indexR);

	if (maxL >= maxR)
		return maxL;
	else
		return maxR;
}


/* 对数器---暴力法寻找最大值 */
int comparator(int arr[N]) {
	int max, i;
	max = arr[0];
	for (i = 1; i < N; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}



/* for test */
void isEqual(int a, int b) {
	if (a == b)
		printf("right result is %d\n", a);
	else
		printf("arr1[max] = %d, arr2[max] = %d\n", a, b);
}

int main(void) {
	int arr1[N], arr2[N];
	int max1, max2;


	generateRandomArray(arr1);

	copyArray(arr1, arr2);

	max1 = funMax(arr1, 0, N - 1);

	max2 = comparator(arr2);

	isEqual(max1, max2);

	return 0;

}