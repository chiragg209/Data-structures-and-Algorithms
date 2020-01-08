#include<bits/stdc++.h>
using namespace std;
int A[1000];

void max_heapify (int A[], int i, int n){
	int l=2*i;
	int r=2*i+1;
	int maxi=i;
	if(l<=n && A[l]>A[i])
		maxi=l;
	if(r<=n && A[r]>A[i] && A[r]>A[maxi])
		maxi=r;
		
	if(maxi!=i){
		int temp=A[i];
		A[i]=A[maxi];
		A[maxi]=temp;
		max_heapify(A,maxi,n);
	}		
}


void heap_sort(int A[], int n){
	
	for(int i=n;i>1;i--){
		int temp=A[i];
		A[i]=A[1];
		A[1]=temp;
		max_heapify(A,1,i-1);
	}
}

int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	
	for(int i=n/2; i>=1; i--)
            max_heapify (A, i, n) ;
            
	for(int i=0;i<=n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
		
	heap_sort(A,n);	
	
	for(int i=0;i<=n;i++)
		cout<<A[i]<<" ";			
return 0;
}
