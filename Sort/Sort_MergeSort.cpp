/*
	MergeSort
	
*/
#include<iostream>
using namespace std;
void MergeSort(int source[],int temp[],int startIndex,int midIndex,int endIndex){
	int i=startIndex,j=midIndex+1,k=startIndex;
	while(i!=midIndex+1&&j!=endIndex+1){
		if(source[i]<=source[j]){
			temp[k++]=source[i++];
		}else{
			temp[k++]=source[j++];
		}
	}
	while(i!=midIndex+1){
		temp[k++]=source[i++];
	}
	while(j!=endIndex+1){
		temp[k++]=source[j++];
	}
	for(i=startIndex;i<=endIndex;i++){
		source[i]=temp[i];
	}
}

void Merge(int source[],int temp[],int startIndex,int endIndex){
	int midIndex=(startIndex+endIndex)/2;
	if(startIndex<endIndex){
		Merge(source,temp,startIndex,midIndex);
		Merge(source,temp,midIndex+1,endIndex);
		MergeSort(source,temp,startIndex,midIndex,endIndex);
	}
}

int main(){
	int source[9]={4,5,3,2,7,4,0,8,9};
	int temp[9];
	Merge(source,temp,0,7);
	for(int i=0;i<9;i++){
		cout<<source[i]<<" ";
	}
	return 0;
} 
