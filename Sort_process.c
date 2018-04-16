/**
	将数组ARRAY[N]从小到大排列
	流程:
		(1)利用暴力法(遍历法)在0-N-1位置寻找最小值A[i],将A[i]与A[0]交换
		(2)1-N-1位置寻找最小值A[i],将A[i]与A[1]交换
	流程代价 = (N + (N-1) + (N -2) + ... + 1) * C
	TC = O(N^2)
	File Name:Sort_processing.c
	Author:Wangyf
	Format:.c
	Creat Time:18/3/12 
**/

/**
	int rand(void)						//返回一个[0,RAND_MAX]间的随机数
	void srand(unsigned seed)			//seed是srand()的种子用来初始化srand()的起始值，seed必须是整数
**/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define N	10		//数组大小
#define	RANGE	100		//元素取值范围1-RANGE

int main(void){
	int i,j,min;
	int ARRAY[N];
	srand((unsigned)time(NULL));	//用时间做种，每次产生的随机数不一样
	
	//生成1-RANGE范围的随机数
	for (i = 0; i < N; i++){
		ARRAY[i] = rand() % RANGE + 1;
		printf("%d,",ARRAY[i]);
	}
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
		printf("%d,",ARRAY[i]);
	}
	return 0;
}