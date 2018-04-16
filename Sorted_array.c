/**
	已知数组ARRAY[N]是有序数组，查找aim在数组中是否存在
	流程一:暴力法
		将数组遍历一遍,aim与ARRAY[i]进行比较,若存在则打印该元素所在位置
		TC = O(N)
	流程二:二分法
		(1)确定此次区间的中间位置mid = (front + end) / 2,将aim与ARRAY[mid]进行比较
		    "=",打印该元素所在位置;
		    "<",在front与mid-1区域找中间位置,比较;
		    ">",在mid+1与end区域找中间位置,比较
		(2)TC = O(logN)
	File Name:Sorted_array.c
	Author:Wangyf
	Format:.c
	Creat Time:18/3/14
**/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N		3		//数组大小
#define	RANGE	100		//元素取值范围1-RANGE
#define aim 	6



//随机数组发生器
int GenerateRandomArray(int a[N]){
	int i;
	srand((unsigned)time(NULL));		//用时间做种，每次产生的随机数不一样
	for(i = 0; i < N; i++){
		a[i] = rand() % RANGE + 1;		//生成1-RANGE范围的随机数
		printf(" %d " ,a[i]);
	}
	return 0;
	
}

//暴力法
int BruteSort(int a[N]){
	int i;
	for(i = 0; i < N; i++){
		if(a[i] == aim){
			printf("the location is = %d\n", i);
			break;
		}
	}
	printf("aim is not found\n");
	return 0;
}

//二分法寻找
int Binary_search(int a[N]){
	int i,front,mid,end;
	front = 0;
	end = N-1;
	mid = (front + end) / 2;
	//未找到数据跳出while，越界条件
	while(front <= right){
		printf("a[mid] = %d\n", a[mid]);
		if(a[mid] == aim){
			printf("the location is = %d\n", mid);
			break;
		}
		if(a[mid] > aim){
			end = mid -1;
		}
		if(a[mid] < aim){
			front = mid + 1;
		}
		mid = (front + end) / 2;
	}
	printf("aim is not found\n");
	return 0;
}


int main(void){
	int i,j,min;
	int ARRAY[N];
	
	GenerateRandomArray(ARRAY);
	printf("\n");

	//暴力法,N次:0~N-1,将整个数组从小到大排序
	for(j = 0; j < N; j++){ 
		//j-N-1遍历寻找最小值min,ARRAY[j] = min
		for(i = j; i < N; i++){
			min = ARRAY[j];
			if(ARRAY[i + 1] < min){
				min = ARRAY[i + 1];
				ARRAY[i + 1] = ARRAY[j];
				ARRAY[j] = min;
			}
		}
	}
	for(i = 0; i < N; i++){
		printf("%d ", ARRAY[i]);
	}
	printf("\n");


	printf("aim = %d\n", aim);

    BruteSort(ARRAY); 

 	Binary_search(ARRAY);

 	printf("That's ok\n");

    return 0;
}