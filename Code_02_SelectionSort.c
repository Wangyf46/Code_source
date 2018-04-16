/**
	选择排序法(selectionSort):将数组arr[N]里的元素从小到大排列；冒泡排序(bubbleSort)的改进
	流程：
	(1)将第0个数据逐步和后面的数据比较，如果后面的值小于第0位置的数据，则交换，最终第0位置是最小值；
	(2)将第1个数据逐步和后面的数据比较，如果后面的值小于第1位置的数据，则交换，最终第1位置是最小值；
	...	
	(3)...N-1...
	TC = O(N^2)

	File Name:Code_01_SelectionSort.c
	Author:Wangyf
	Format:.c
	Date:2018/3/28

**/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N		5	//数组大小
#define	RANGE	100		//元素取值范围1-RANGE



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

//交换
int swap(int a, int b) {
	int var;
	var = a;
	a = b;
	b = var;

	return 0;
}

//对数器----绝对正确
int comparator(int arr[N]) {
	int i;
	int temp;
	int var;

	temp = N - 1;
	while (temp >= 0) {
		for (i = 0; i < temp; i++) {
			if (arr[i] > arr[i + 1]) {
				var = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = var;
			}
		}
		temp--;
	}
	return 0;
}
//比较
void isEqual(int arr1[N], int arr2[N]) {
	int i;
	for (i = 0; i < N; i++) {
		if (arr1[i] != arr2[i])
			printf("第%d个数据有误\n", i);
	}
}

int main(void) {
	int i;
	int init;
	int var;
	int arr1[N];
	int arr2[N];


	generateRandomArray(arr1);
	printf("\n");

	for (init = 0; init < N; init++) {
		for (i = init + 1; i < N; i++) {
			if (arr1[init] > arr1[i]) {
				var = arr1[init];
				arr1[init] = arr1[i];
				arr1[i] = var;
			}
				
		}
	}


	//for test
	for (i = 0; i < N; i++)
		arr2[i] = arr1[i];
	//对数器
	comparator(arr2);
	//比较
	isEqual(arr1, arr2);

	for (int i = 0; i < N; i++) {
		printf("%d,", arr1[i]);
	}

	return 0;
}


