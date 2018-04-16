/**
	冒泡排序法(bubbleSort):将数组arr[N]里的元素从小到大排列
	流程：
		(1)0 - N-1:比较两个相邻的元素，如果前一位置大于后一位置的数值，则交换，找出全局最大值,将此值置于N-1位置；
		(2)0 - N-2:找出全局最大值，将此值置于N-2位置；
		...
		(3)0 - 1:
		(4)0
	TC = O(N^2)
	SC = O(1)

	File Name:Code_00_BubbleSort.c
	Author:Wangyf
	Format:.c
	Date:2018/3/28

**/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N		20		//数组大小
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
int swap(int a, int b){
	int var;
	var = a;
	a = b;
	b = var;

	return 0;
}

int main(void){
	int i;
	int arr1;
	int arr2;
	int temp;

	generateRandomArray(arr);
	printf("\n");

	temp = N - 1;
	while(temp >= 0){
		for(i = 0; i < temp ; i++){
			if(arr1[i] > arr1[i + 1])
				swap(arr1[i], arr1[i + 1]);
		}
		temp--;
	}

}