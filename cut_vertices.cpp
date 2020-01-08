#include <bits/stdc++.h>
using namespace std;

int timer = -1;
void dfs(vector <vector <int> > &A, vector <int> &parent, vector <bool> &visited, vector <int> &disc, vector <int> &low, int node, vector <bool> &ap){
	visited [node]=true;
	timer++;
	disc[node]=timer;
	low[node]=timer;
	int child=0;
	for(int i=0; i<A[node].size(); i++){
		if(visited[A[node][i]]==false){
			child++;
			parent[A[node][i]]= node;
			dfs(A, parent, visited, disc, low, A[node][i], ap);
			low[node] = min(low[node], low[A[node][i]]);
			if(parent[node]==-1 && child>1)
				ap[node] = true;
			else if(low[A[node][i]] >= disc[node])	
				ap[node] = true;
		}else if(parent[node]!= A[node][i]){
			low[node] = min(low[node], disc[A[node][i]]);
		}
	}
}

int main(){
	int n; cin>>n;
	vector <vector <int> > A (n, vector <int> ());
	int m; cin>>m;
	int x,y;
	
	for(int z=0;z<m;z++){
		cin>>x>>y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	vector <bool> visited (n, false);
	vector <int> parent (n,-1);
	vector <int> disc (n,-1);
	vector <int> low (n,-1);
	vector <bool> ap (n,false);
	cout<<"========"<<endl;
	dfs(A, parent, visited, disc, low, 0, ap);
	for(int i=0;i<n;i++){
		cout<<i<<"  "<<ap[i]<<endl;
	}
	return 0;
}

/* testcase
8 9
0 1
1 2
1 3
2 3
0 4
4 6
4 5
5 6
5 7

8 10
0 1
1 2
1 3
2 3
0 4
4 6
4 5
5 6
5 7
1 5
*/
