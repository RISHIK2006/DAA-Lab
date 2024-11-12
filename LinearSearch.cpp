// Iterative Linear Search
// Worst case TC= O(N)
// Average case TC = O(N/2)
// Best case TC = O(1)


#include <bits/stdc++.h>
using namespace std;

int linearsearch(int arr[],int n,int target){
	for(int i=0;i<n;i++){
		if(arr[i]==target) return i;
	}
	return -1;
}

int main() {
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
	int index=linearsearch(arr,n,target);
	if(index==-1){
		cout<<"\nElement not found";
	}
	else{
		cout<<"Element found at index:"<<index;
	}
	
	return 0;
}

