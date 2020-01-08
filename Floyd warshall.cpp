#include<iostream>
using namespace std;
#define v 9
int dist[v][v];

int main(){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
			 dist[i][j]=0;
			else
			 dist[i][j]=1e9+7;
		}
	}
	int m; cin>>m;
	int i,j,d;
	for(int z=0;z<m;z++){
		cin>>i>>j>>d;
		dist[i][j]=d;
		dist[j][i]=d;
	}
    
    for(int k=0;k<n;k++){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
			}
		}
	}
	cout<<"============="<<endl;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<dist[i][j]<<"  ";
    cout<<endl;
	}
	return 0;
}
