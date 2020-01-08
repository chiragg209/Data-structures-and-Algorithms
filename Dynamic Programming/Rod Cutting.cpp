// https://www.interviewbit.com/problems/rod-cutting/

void backtrack(vector<vector<int>> &E, unordered_map<int,int> &mp, int s,int e, vector<int> &C){
    if(E[s][e]==0)
        return;
    C.push_back(mp[E[s][e]]);
    backtrack(E,mp,s,E[s][e]-1,C);
    backtrack(E,mp,E[s][e],e,C);
    
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    int l=B.size();
    vector<int> C;
    vector<vector<int>> D(l+1,vector<int> (l+1,0));
    vector<vector<int>> E(l+1,vector<int> (l+1,0));
    unordered_map<int,int> mp;
    mp[0]=0;
    mp[l+1]=A;
    for(int i=0;i<l;i++)
        mp[i+1]=B[i];
    
    for(int k=0;k<l+1;k++){
        for(int i=0,j=k; i<l+1,j<l+1; i++,j++){
            if(i==j)
                D[i][j]=0;
            else{
                D[i][j]=mp[j+1]-mp[i];
                int minv=1e7,v=0;
                for(int z=i+1;z<=j;z++){
                    v=D[i][z-1]+D[z][j];
                    if(v<minv){
                        minv=v;
                        E[i][j]=z;
                    }
                }
                D[i][j]+=minv;
            }    
            
        }
    }
    int s=0,e=l;
    backtrack(E,mp,s,e,C);
    
    
    // for(int i=0;i<=l;i++){
    //     for(int j=0;j<=l;j++){
    //         cout<<D[i][j]<<" ";
    //     }cout<<endl;
    // }
    // for(int i=0;i<=l;i++){
    //     for(int j=0;j<=l;j++){
    //         cout<<E[i][j]<<" ";
    //     }cout<<endl;
    // }
 
    return C;
}
