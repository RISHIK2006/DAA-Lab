#include<bits/stdc++.h>
using namespace std;

void qsl(int arr[],int low,int high){
	int pivot,i,j;
	if(low<high){
		pivot=high;
		i=low;
		j=high-1;
		while(i<=j){
			
			while(arr[i]<arr[pivot] && i<=high){
				i++;
			}
			
			while(arr[j]>arr[pivot] && j>=low){
				j--;
			}
			if(i<j)
			swap(arr[i],arr[j]);
		}
		swap(arr[i],arr[pivot]);
		qsl(arr,low,i-1);
		qsl(arr,i+1,high);		
	}

}


int main(){
	int arr[6]={10,7,9,20,4,15},k;
	qsl(arr,0,5);
	printf("Sorted array is:");
	for(k=0;k<6;k++){
		cout<<arr[k]<<" ";
	}
}
