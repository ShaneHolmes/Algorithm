/*
	Insert Sort插入排序
	思路：从第二个元素开始往后循环，找到每个元素的插入位置
	找插入位置：将a[i](i=2...length-1)插入到a[0...i-1]的有序数组中，从数组最后元素开始比较，key=a[i] 
	j=i-1...0;
	若key>a[j],说明a[0...i]为有序
	若key<a[j],a[j]往后移一位，j--
	重复上述步骤，直到 key>=a[j]
	至此找到a[i]要插入的位置[j+1],并且大的元素已经往后移了，直接插入即可 
*/
#include<iostream>
using namespace std;
int main(){
	int a[8]={3,4,6,3,2,9,4,1};
	int i=1;
	for(;i<8;i++){
		int key=a[i];//key保存当前i遍历指向的元素的值
		int j=i-1;//j初始是i的前一个下标，往前递减，直到找到当前i下标的位置 
		while(j>=0&&a[j]>key){//j下标的元素比key大 
			a[j+1]=a[j];//往前移一位 
			j--;
		}
		a[j+1]=key;//找到i插入的位置 
	}
	i=0;
	while(i<8){
		cout<<a[i];
		i++;
	}
	return 0;
}
 
