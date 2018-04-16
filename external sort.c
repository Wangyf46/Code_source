/**
	已知有序数组a[N]、b[M],查找两数组中公共部分,数值相同即可
	两数组中均未重复值
	流程一:暴力法
		遍历两个数组进行比较查找
		TC = O(N*M)
	流程二:二分法
		从数组A中取数(N个),在数组b中进行二分法查找
		TC = O(N*logM)
	流程三:外排法(external sort)
		(1)分别定义指针p,q,分别指向数组a,b的首地址
		(2)比较两个指针对应的元素值，哪个数值小哪个指针对应的位置向右移动一个;若两只数值相同,则两指针所在的位置共同向前移动
		(3)准备一个额外数组c,用于存放相同的部分;或者将相同部分打印出来
		(4)当有一个数值发生越界时，停止
		TC = O(N+M)(备注:省去常数操作，如比较等)
	File Name:exteral sort.c
	Author:Wangyf
	Format:.c
	Creat Time:18/3/15
**/
/**
	Problem:指针a指的数据有误

**/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N		3							//数组大小
#define	RANGEa	20							//元素取值范围1-RANGE
#define	RANGEb	500



int main(void){
	int i,j,min;
	int a[N],b[N];
	int *p = NULL;
	int *q = NULL;
	p = a;
	q = b;


	srand((unsigned)time(NULL));			//用时间做种，每次产生的随机数不一样
	for(i = 0; i < N; i++){
		a[i] = rand() % RANGEa + 1;
		b[i] = rand() % RANGEb + 1;

	}

	for(j = 0; j < N; j++){ 
		//j-N-1遍历寻找最小值min,a[j] = min
		for(i = j; i < N; i++){
			min = a[j];
			if(a[i + 1] < min){
				min = a[i + 1];
				a[i + 1] = a[j];
				a[j] = min;
			}
		}
	}
	for(i = 0; i < N; i++){
		printf("a[i] = %d ", a[i]);
	}
	printf("\n");


	for(j = 0; j < N; j++){ 
		//j-N-1遍历寻找最小值min,b[j] = min
		for(i = j; i < N; i++){
			min = b[j];
			if(b[i + 1] < min){
				min = b[i + 1];
				b[i + 1] = b[j];
				b[j] = min;
			}
		}
	}
	for(i = 0; i < N; i++){
		printf("b[i] = %d ", b[i]);
	}
	printf("\n");


	printf(" %d\n",*p);
	for(i = 0; i < N; i++){
		printf("*p = %d,*q = %d\n", *p,*q);
		if (*p == *q){
			printf("common is %d,", *q);
			p++;
			q++;
		}
		else if(*p < *q)
			p++;
		else
			q++;			
	}
	
	printf("end\n");

}
