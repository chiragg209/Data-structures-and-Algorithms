// https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

int Solution::solve(int A) {
    int mod=1e9+7;
   if(A==0)
        return 0;
    int dpu[A+1],dps[A+1];
    dpu[1]=24;
    dps[1]=12;
    for(int i=2;i<=A;i++){
        dpu[i]=((dpu[i-1]*11)%mod + (dps[i-1]*10)%mod)%mod;
        dps[i]=((long long)dpu[i-1]*5+(long long)dps[i-1]*7)%mod ;
        /*dpu[i]=((long long)dpu[i-1]*11+(long long)dps[i-1]*10)%mod;
        dps[i]=((long long)dpu[i-1]*5+(long long)dps[i-1]*7)%mod ;*/
    }
    return ((long long)dpu[A]+dps[A])%mod;
}
