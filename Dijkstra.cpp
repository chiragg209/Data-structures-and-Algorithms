#include <iostream>
using namespace std;
#define v 9
int dist[v];
bool visited[v];
void dikstra(int n, int *A, int s){
	dist[s]=0;
  for(int k=0;k<n;k++){
  	int minv=1e9+7,minn;
	for(int i=0;i<n;i++){
		if(dist[i]!=-1 && dist[i]<minv && !visited[i]){
			minn=i;
			minv=dist[i];
		}
	}
	visited[minn]=1;
	for(int j=0; j<n; j++){
		if(!visited[j] && *((A+minn*n)+j)!=0 && ((dist[j]!=-1 && dist[minn]+ *((A+minn*n)+j) <dist[j]) || dist[j]==-1)){
			dist[j]=dist[minn]+ *((A+minn*n)+j);
		}
	}
}
}
int main(){
	int n; cin>>n;
	int A[n][n]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i][j]=0;
		}
	}
	int m; cin>>m;
	int i,j,d;
	for(int z=0;z<m;z++){
		cin>>i>>j>>d;
		A[i][j]=d;
		A[j][i]=d;
	}
	for(int i=0;i<n;i++){
		visited[i]= 0;
		dist[i]=-1;
	}
	dist[0]=0;
	cout<<"============="<<endl;
	dikstra(n, (int *)A, 0);
	for(int i=0;i<n;i++){
		cout<<i<<"  "<<dist[i]<<endl;
	}
	return 0;
}

//testcase
/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8 
7 8 7
7 6 1
2 8 2
8 6 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
4 5 10
*/
