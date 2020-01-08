#include <bits/stdc++.h>
using namespace std;

void build(int A[], int segt[], int node, int start, int end){
	if(start == end){
		segt[node]= A[start];
	}else{
		int mid = (start + end)/2;
		build(A,segt, 2*node+1, start, mid);
		build(A,segt, 2*node+2, mid+1, end);
		segt[node]= min(segt[2*node+1],segt[2*node+2]);
	}
	//cout<<node<<" "<<segt[node]<<endl;	
}
void update(int A[], int segt[], int node, int ind, int val, int start, int end){
	if(start==end){
		A[ind]=val;
		segt[node]=val;
	}else{
		int mid = (start+end)/2;
		if(start<=ind && ind<=mid){
			update(A,segt, 2*node+1, ind, val, start, mid);
		}else{
			update(A,segt, 2*node+2, ind, val, mid+1, end);
		}
	
	segt[node]= min(segt[2*node+1],segt[2*node+2]);
	}
}

int query(int A[],int segt[], int node, int left, int right, int start, int end){
	if(start>right || end<left){
		return 1e9+7;
	}else if(left<=start && right>=end){
		return segt[node];
	}else{
		int mid = (start+end)/2;
		int p1 = query(A, segt, 2*node+1, left, right, start, mid);
		int p2 = query(A, segt, 2*node+2, left, right, mid+1, end);
		return min(p1,p2);
	}
	
}
int main(){
	int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++) cin>>A[i];
	int m=pow(2, ceil(log2(n)) +1)-1;
	//cout<<m<<endl;
	int segt[m]={0};
	build(A, segt, 0, 0, n-1);
	for(int i=0;i<m;i++) cout<<segt[i]<<" ";
	cout<<endl;
	int t; cin>>t;
	while(t--){
	    int in, u; cin>>in>>u;
	    update(A,segt,0,in,u,0,n-1);
	    for(int i=0;i<m;i++) cout<<segt[i]<<" ";cout<<endl;
	    int l,r; cin>>l>>r;
	    cout<<query(A,segt,0,l,r,0,n-1)<<"<===="<<endl;
	}
}
/*

*/
