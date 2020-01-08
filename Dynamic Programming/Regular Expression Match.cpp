// https://www.interviewbit.com/problems/regular-expression-match/

int Solution::isMatch(const string A, const string B) {
    int m=A.length();
    int n=B.length();
    vector<vector<bool> > dp(m+1, vector<bool>(n+1,false));
    // bool dp[m+1][n+1];
    // memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        if(A[i-1]=='*')
            dp[i][0]=dp[i-1][0];
        else
            dp[i][0]=0;
    }
    for(int j=1;j<=n;j++){
        if(B[j-1]=='*')
            dp[0][j]=dp[0][j-1];
        else
            dp[0][j]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]=='*' && B[j-1]=='*'){
                if(dp[i-1][j-1])
                    dp[i][j]=1;
                else{
                    for(int k=0;k<j;k++)
                        if(dp[i][k]){
                            dp[i][j]=1;
                            break;
                        }
                    for(int k=0;k<i;k++)
                        if(dp[k][j]){
                            dp[i][j]=1;
                            break;
                        }    
                }    
            }else if(A[i-1]==B[j-1] || A[i-1]=='?' || B[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(A[i-1]!=B[j-1] && A[i-1]=='*'){
                if(dp[i-1][j])
                    dp[i][j]=1;
                else{
                    dp[i][j]=dp[i][j-1];
                }    
            }else if(A[i-1]!=B[j-1] && B[j-1]=='*'){
                if(dp[i][j-1])
                    dp[i][j]=1;
                else{
                    dp[i][j]=dp[i-1][j];
                    /*for(int k=0;k<i;k++)
                        if(dp[k][j]){
                            dp[i][j]=1;
                            break;
                        }*/
                }    
                
            }
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    if(dp[m][n])
        return 1;
    return 0;
}
