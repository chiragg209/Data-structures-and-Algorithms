// https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            if(A[i][j]!=0)
                A[i][j]=A[i-1][j]+1;
        }
    }
    
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    int maxar=0,ar=0;
    for(int i=0;i<n;i++){
        sort(A[i].begin(),A[i].end());
    }
    for(int i=0;i<n;i++){
        int l=m;
        for(int j=0;j<m;j++){
            ar=A[i][j]*l;
            if(ar>maxar)
                maxar=ar;
            l--;
        }
    }
    return maxar;
}
