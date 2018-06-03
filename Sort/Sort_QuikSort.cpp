/*
	QuikSort 
*/ 
#include<iostream>
using namespace std;

int Partition(int a[],int startIndex,int endIndex){//������Ϊһ��ѭ�� 
	int i=startIndex,j=endIndex;
	int key=a[i];//�õ�һ��Ԫ����Ϊ�ؼ������� 
	while(i<j){
		while(i<j&&a[j]>=key){
			j--;//�Ӻ���ǰ��ֱ���ҵ���һ����keyС�ĵ�Ԫ�� 
		}
		a[i]=a[j];//���Ǹ�С�ڵ�һ��Ԫ��key��Ԫ���Ƶ��Ͷ�
		while(i<j&&a[i]<=key){
			i++;//��ǰ����ֱ���ҳ���һ����key���ֵ 
		} 
		a[j]=a[i];// �Ѵ��ڵ�һ��key��Ԫ�طŵ��ո�j�ճ�����λ�ã���ʱj��ֵ�Ѿ��浽a[startIndex]
	}
	//����ٰ�key��ֵ�ŵ�����λ�ã�һ��ѭ������ 
	a[i]=key;//��ʱλ��i��Ϊ���ᣬ���������λ�ã��Ա���QuikSort�и�������λ�û����������߽��еݹ� 
	return i; 
}

void QuikSort(int a[],int startIndex,int endIndex){
	if(startIndex>=endIndex){//�ݹ�ֱ�������ٻ���Ϊֹ����ʱʣһ��Ԫ�أ� startIndex=endIndex
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
