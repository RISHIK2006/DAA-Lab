#include <bits/stdc++.h>
using namespace std;

int binaryRec(int arr[],int s,int e,int target){
	if(s>e) return -1;
	int mid=(s+e)/2;
	if(arr[mid]==target) return mid;
	else if(target>arr[mid]){
		return binaryRec(arr,mid+1,e,target);
	}
	else{
		return binaryRec(arr,s,mid-1,target);
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
	int index=binaryRec(arr,0,n,target);
	if(index==-1){
		cout<<"\nElement not found";
	}
	else{
		cout<<"Element found at index:"<<index;
	}
}
