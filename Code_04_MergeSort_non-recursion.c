/**
	归并排序_非递归实现：将数组arr[N]采用归并排序的非递归方式实现从小到大排列。
	每次外排的个数是2*k(k=1,2k>N时结束)则不足的部分单独放在右侧
	流程：
		(1)while函数实现相邻数的外排----------2个数
		(2)while函数实现相邻两个数的外排------4个数
		(2)while函数实现相邻四个数的外排------8个数
		(3)while函数实现相邻八个数的外排------16个数

	分别测试N为奇数、偶数的不同情况
	外排一般借助额外数组help，在将额外数组拷贝至原数组里。需要考虑越界的问题
**/



#include 	<stdlib.h>
#include	<stdio.h>
#include 	<time.h>

#define 	N 		11
#define     RANGE	100
#define     L       0
#define     R       N-1


/* 随机数组发生器 */
int generateRandomArray(int arr[N]) {
	int i;
	srand((unsigned)time(NULL));		//用时间做种，每次产生的随机数不一样
	for (i = 0; i < N; i++) {
		arr[i] = rand() % RANGE + 1;		//生成1-RANGE范围的随机数
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}


/* 数组值复制 */
void copyArray(int arr1[N], int arr2[N]) {
	int i;
	for (i = 0; i < N; i++) {
		arr2[i] = arr1[i];
		printf("%d,", arr2[i]);
	}
	printf("\n");
}

void nonrecursionProcess(int arr[N], int L, int R){
	int help[N];
	int i, k;
	for (int k = 1; 2k <= N; k++){
		for (int i = 0; i < N; i = i + 2 * k){
			merge(arr, i)
		}
	}
}


/* 交换数组中两个元素的数值 */
void swap(int arr[N], int i, int j) {
	int var;
	var = arr[i];
	arr[i] = arr[j];
	arr[j] = var;
}


/* 对数器--BubbleSort */
void comparator(int arr[N]) {
	int i;
	int temp;

	temp = N - 1;
	while (temp >= 0) {
		for (i = 0; i < temp; i++) {
			if (arr[i] > arr[i + 1])
				swap(arr, i, i + 1);
		}
		temp--;
	}
}


/* 比较两个数组元素是否相等 */
void isEqual(int arr1[N], int arr2[N]) {
	int i;
	for (i = 0; i < N; i++) {
		if (arr1[i] != arr2[i])
			printf("第%d个元素有误", i);
		else
			printf("%d,", arr1[i]);
	}
	printf("\n");
}


int main(void) {
	int arr1[N], arr2[N], help[N];

	generateRandomArray(arr1);

	copyArray(arr1, arr2);

	mergeSort(arr1, L, R);

	comparator(arr2);

	isEqual(arr1, arr2);

	return 0;
}