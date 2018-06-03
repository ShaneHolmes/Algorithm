/*
	QuikSort 
*/ 
#include<iostream>
using namespace std;

int Partition(int a[],int startIndex,int endIndex){//整体作为一趟循环 
	int i=startIndex,j=endIndex;
	int key=a[i];//用第一个元素作为关键字枢轴 
	while(i<j){
		while(i<j&&a[j]>=key){
			j--;//从后往前，直到找到第一个比key小的的元素 
		}
		a[i]=a[j];//将那个小于第一个元素key的元素移到低端
		while(i<j&&a[i]<=key){
			i++;//从前往后，直到找出第一个比key大的值 
		} 
		a[j]=a[i];// 把大于第一个key的元素放到刚刚j空出来的位置，此时j的值已经存到a[startIndex]
	}
	//最后再把key的值放到枢轴位置，一趟循环结束 
	a[i]=key;//此时位置i作为枢轴，返回枢轴的位置，以便在QuikSort中根据枢轴位置划分左右两边进行递归 
	return i; 
}

void QuikSort(int a[],int startIndex,int endIndex){
	if(startIndex>=endIndex){//递归直到不能再划分为止，此时剩一个元素， startIndex=endIndex
		return ;
	}
	int positionIndex=Partition(a,startIndex,endIndex);
	QuikSort(a,startIndex,positionIndex-1);
	QuikSort(a,positionIndex+1,endIndex);
}

int main(){
	int a[]={45,6,43,46,7,89,54,33,2,78,80,1};
	QuikSort(a,0,11);
	for(int i=0;i<12;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
