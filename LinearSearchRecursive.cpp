#include<bits/stdc++.h>
using namespace std;

int linearRec(int arr[],int count,int n,int target){
	if(count>n-1) return -1;
	if(arr[count]==target) return count;
	else{
		return linearRec(arr,count+1,n,target);
	}
}

int main(){
	cout<<"Enter number of elements of array:";
	int n;
	cin>>n;
	int arr[n];
	cout<<"\nEnter elements of array:";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int target;
	cout<<"\nEnter element to search:";
	cin>>target;
	int index=linearRec(arr,0,n,target);
		if(index==-1){
		cout<<"\nElement not found";
	}
	else{
		cout<<"Element found at index:"<<index;
	}
	return 0;
}
