// Iterative Binary Search
// Worst case TC= O(logN)
// Average case TC = O(logN)
// Best case TC = O(1)
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int s,int e,int target){
	while(s<=e){
		int mid=(s+e)/2;
		if(arr[mid]==target) return  mid;
		else if(target>arr[mid]){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	return -1;
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
	int index=binarySearch(arr,0,n,target);
	if(index==-1){
		cout<<"\nElement not found";
	}
	else{
		cout<<"Element found at index:"<<index;
	}
	
	return 0;
}
