// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

int Solution::solve(int A, int B) {
    
    if(B==0 || B>A*9)
        return 0;
        
    int C[A*9+1];
    int D[A*9+1];
    int mod=1e9+7;
    for(int i=1;i<10;i++){
        C[i]=1;
    }
    for(int i=2;i<=A;i++){
        if(i%2==0){
            for(int j=1;j<=i*9 && j<=B;j++){
                D[j]=0;
                for(int k=0;k<10 && k<j;k++){
                    if(j-k<= ((i-1)*9))
                        D[j]= (D[j]+C[j-k])%mod;
                }
            }
            //cout<<i<<" "<<D[19]<<endl;
        }else{
            for(int j=1;j<=i*9 && j<=B;j++){
                C[j]=0;
                for(int k=0;k<10 && k<j;k++){
                    if(j-k<= ((i-1)*9))
                        C[j]= (C[j]+D[j-k])%mod;
                }     
            }
            //cout<<i<<" "<<C[19]<<endl;
        }
        
    }
    if(A%2==0)
        return D[B]%mod;
    else
        return C[B]%mod;
}
