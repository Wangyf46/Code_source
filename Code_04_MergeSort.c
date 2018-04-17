/**
	归并排序(MergeSort):将数组arr[N]中的第L位置至第R位置采用归并排序，将其从小到大排列(含递归的归并排序)
	TC = O(N*logN)
	SC = O(N)
	计算含递归的归并排序是，采用Master公式
	流程:
	(1)取数组arr[N]中第L、第R位置的中间位置mid，将其分为左右两侧
	(2)左右两边分别调用自己(即递归过程)，将左侧、右侧分别从小到大排序
	(3)对左右两侧排好序的数组使用外排法(未使用指针)，申请额外空间存放排序后的数组
	(4)将额外空间数组复制到原数组中

	外排，即数组合并的过程，以下为越界情况的分析：
	(1)当两者都不越界，help数组依次
	(2)当存在一个数组越界时(必有一个数组越界)，将未越界的剩余部分依次填入help的辅助空间内
	(3)不存在两者同时越界？？？？？当两者一起越界的时候，后面的数据则是空的所以没有考虑的必要

	File Name: Code_04_MergeSort.c
	Author: Wangyf
	Format: .c
	Date: 2018/4/3

**/


#include 	<stdlib.h>
#include	<stdio.h>
#include 	<time.h>

#define 	N 		5
#define     RANGE	100



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


/* 外排法合并数组 */
void merge(int arr[N], int indexL, int mid, int indexR, int size) {
	int help[N];
	int p = indexL;
	int q = mid + 1;
	int i = 0;
	while ((p <= mid) && (q <= indexR)) {
		if (arr[p] < arr[q]) {
			help[i] = arr[p];
			p++;
		}
		else if (arr[p] > arr[q]) {
			help[i] = arr[q];
			q++;
		}
		else {
			help[i] = arr[p];
			p++;
			q++;
		}
		i++;
	}

	while (p <= mid) {
		help[i] = arr[p];
		i++;
		p++;
	}

	while (q <= indexR) {
		help[i] = arr[q];
		i++;
		q++;
	}

	for (i = 0; i < size; i++) {
		arr[i + indexL] = help[i];
	}

}

/* 递归函数将左右两侧分别从小到大排序 */
int recursiveProcess(int arr[N], int indexL, int indexR) {
	int mid;
	if (indexL == indexR)
		return 0;
	mid = indexL + (indexR - indexL) / 2;
	recursiveProcess(arr, indexL, mid);
	recursiveProcess(arr, mid + 1, indexR);
	merge(arr, indexL, mid, indexR, indexR - indexL + 1);
}


/* 归并排序 */
void mergeSort(int arr[N], int indexL, int indexR) {
	recursiveProcess(arr, indexL, indexR);
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
	int L, R;

	L = 0;
	R = N - 1;

	generateRandomArray(arr1);

	copyArray(arr1, arr2);

	mergeSort(arr1, 0, N - 1);

	comparator(arr2);

	isEqual(arr1, arr2);

	return 0;
}