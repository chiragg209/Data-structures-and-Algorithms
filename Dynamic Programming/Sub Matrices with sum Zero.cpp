// https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    if(n==0)
        return 0;
    int m=A[0].size();
    int c=0;
    vector<vector<int> > B;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            B=A;
            for(int k=i;k<n;k++){
                for(int l=j;l<m;l++){
                    if (l!=j)
                        B[k][l]=B[k][l-1]+B[k][l];
                    //cout<<B[k][l]<<" ";    
                }
                //cout<<endl;
            }
            //cout<<"===="<<endl;
                for(int l=j;l<m;l++){
                    for(int k=i;k<n;k++){
                        if(k!=i)
                            B[k][l]=B[k-1][l]+B[k][l];
                        if(B[k][l]==0)
                            c++;
                        //cout<<B[k][l]<<" ";     
                        //cout<<c<<endl;    
                }
                //cout<<endl<<"a"<<c<<endl;
            }
            
            
        }
    }
    return c;
}
