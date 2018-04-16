/**
	插入排序法(InsertionSort)
	流程:
	(1)将数组arr[N]里的元素从小到大排序
	(2)检查数组中第i个元素(i = 1, 第二个元素)，若左边的数比其大，则两数交换，此动作一致执行知道左边的数值小于该元素为止
	TC = O(N^2)
	SC = O(1)
	该排序法可以做到稳定性, 利用对数器完成此部分代码

	File Name: Code_03_InsertionSort.c
	Author: Wangyf
	Date: 2018/4/3
	Format: .c

**/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define		Length	10
#define 	RANGE	100


/* 随机数组发生器 */
void generateRandomArray(int arr[Length]) {
	int i;
	srand((unsigned)time(NULL));						//用时间做种，每次产生的随机数不一样
	for(i = 0; i < Length; i++){
		arr[i] = rand() % RANGE + 1;					//生产1-RANGE范围的随机数
		printf("%d, ", arr[i]);
	}
	printf("\n");
}


/* 交换数组中两个元素的数值 */
void swap(int arr[Length], int i, int j) {
	int var;
	var = arr[i];
	arr[i] = arr[j];
	arr[j] = var;
}


/* 插入排序法 */
void insertionSort(int arr[Length]) {
	int i, j;
	int var;

	for (i = 1; i < Length; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
				/*
				var = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = var;
				*/
			}
			
		}
	}
	printf("InsertionSort: ");
	for (i = 0; i < Length; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
	

}


/* 数组值复制 */
void copyArray(int arr1[Length], int arr2[Length]) {
	int i;
	printf("arr2[%d] = {", Length);
		for (i = 0; i < Length; i++) {
			arr2[i] = arr1[i];
			printf("%d,", arr2[i]);
		}
	printf("}\n");
}


/* 对数器--BubbleSort */
void comparator(int arr[Length]) {
	int i;
	int temp;

	temp = Length - 1;
	while (temp >= 0) {
		for (i = 0; i < temp; i++) {
			if (arr[i] > arr[i + 1])
				swap(arr, i, i + 1);
		}
		temp--;
	}
}





void comparator1(int arr[Length]) {
	int i, j;
	for (i = 0; i < Length; i++) {
		for (j = i + 1; j < Length; j++) {
			if (arr[i] > arr[j])
				swap(arr, i, j);
		}
	}
}




/* 比较两个数组元素是否相等 */
void isEqual(int arr1[Length], int arr2[Length]) {
	int i;
	for (i = 0; i < Length; i++) {
		if (arr1[i] != arr2[i])
			printf("第%d个元素有误", i);
		else
			printf("%d,", arr2[i]);
	}
	printf("\n");
}


int main(void) {
	int arr1[Length], arr2[Length];
	int i, j;

	generateRandomArray(arr1);

	copyArray(arr1, arr2);

	insertionSort(arr1);

	

	//comparator(arr2);
	comparator1(arr2);

	isEqual(arr1, arr2);

	

	return 0;

}
