/**
	梯度下降法：
	流程:
    
	File Name: Gradient Descent.cpp
	Author: Wangyf
	Format: .cpp
	Date: 2018/4/15/
**/

#include <iostream>
#include <stdio.h>
#include <math>

using namespace std;

double predict(double* w,double* data,int feature_num){  
    double sum=0;  
    for(int i=0;i<feature_num;i++){  
        sum+=w[i]*data[i];  
    }  
    return sum;  
}  
double Theta(double **training_set,int featue_num,int training_num,double* w){  
    double sum=0;  
    for(int i=0;i<training_num;i++){  
        sum+=(training_set[i][featue_num]-predict(w,training_set[i],featue_num))*(training_set[i][featue_num]-predict(w,training_set[i],featue_num));  
    }  
    return sum/(2*training_num);  
}  
void gradient_descent(double** training_set,int feature_num,int training_num,double* w,double a,int iterator_time){  
    while(iterator_time--){  
        double* del_theta=new double[feature_num];  
        for(int i=0;i<feature_num;i++){  
            del_theta[i]=0;  
            for(int j=0;j<training_num;j++){  
                del_theta[i]+=(predict(w,training_set[j],feature_num)-training_set[j][feature_num])*training_set[j][i];  
            }  
        }  
        //w[i]的更新必须等所有的del_theta测算出来了才可以！不然更新的会影响没更新的  
        //上述问题在代码内表示即是下面的for循环不能和上面的合并！  
        for(int i=0;i<feature_num;i++)  
            w[i]-=a*del_theta[i]/(double)training_num;  
        printf("%.3lf\n", Theta(training_set,feature_num,training_num,w));  
        delete[] del_theta;  
    }  
    for(int i=0;i<feature_num-1;i++){  
        printf("%.3lf ", w[i]);  
    }  
    printf("%.3lf\n", w[feature_num-1]);  
    return;  
}  
void feature_normalize(double **feature_set,int feature_num,int training_num){  
//特征归一化，此处特征归一化方法略有不同于梯度下降那篇的特征归一化方法  
//问题：特征归一化Y的值需要归一化么？不需要！  
    double *average=new double[feature_num];  
    double  *stanrd_divition=new double[feature_num];  
    for(int i=1;i<feature_num;i++){  
        double sum=0;  
        for(int j=0;j<training_num;j++){  
            sum+=feature_set[j][i];  
        }  
        average[i]=sum/training_num;  
    }  
    for(int i=1;i<feature_num;i++){  
        double sum=0;  
        for(int j=0;j<training_num;j++){  
            sum+=(feature_set[j][i]-average[i])*(feature_set[j][i]-average[i]);  
        }  
        stanrd_divition[i]=sqrt((sum/(training_num-1)));  
    }  
    for(int i=1;i<feature_num;i++)  
        for(int j=0;j<training_num;j++){  
            feature_set[j][i]=(feature_set[j][i]-average[i])/(double)stanrd_divition[i];  
        }  
    delete[] stanrd_divition;  
    delete[] average;  
}  
int main(){  
    int feature_num,training_num,times;  
    double a;  
    //自己测试时请修改路径  
   freopen("in.txt","r",stdin);  
    while(cin>>feature_num>>training_num>>a>>times){  
        double **featurn_set=new double*[training_num];  
        //int *arr=new int[10] 意味着声明了一个数组，大小为10，类型为int  
        for(int i=0;i<training_num;i++){  
            featurn_set[i]=new double[feature_num+2];  
        }  
        for(int i=0;i<training_num;i++) featurn_set[i][0]=1;  
        for(int i=0;i<training_num;i++){  
            for(int j=1;j<=feature_num+1;j++){  
                cin>>featurn_set[i][j];  
            }  
        }  
        //在特征标准化的时候w0完全一样，就直接赋值为一，不要进行标准化了，不然会出错  
       feature_normalize(featurn_set,feature_num+1,training_num);  
       for(int i=0;i<training_num;i++) featurn_set[i][0]=1;  
        double* w=new double[feature_num+1];  
        for(int i=0;i<=feature_num;i++)  
            w[i]=0;  
        gradient_descent(featurn_set,feature_num+1,training_num,w,a,times);  
        for(int i=0;i<training_num;i++) delete[] featurn_set[i];  
        delete[] featurn_set;  
        delete[] w;  
        //一般情况，需要将w=NULL，原因是为了防止w再次调用delete删除了不该删除的东西  
 }  
    return 0;  
} 