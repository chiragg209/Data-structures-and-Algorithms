// https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &A) {
    int l=A.size();
    if(l<2)
        return 1;
    int c=1;
    for(int i=0;i<l-1;i++){
        if(A[i]==0){
            int z=1,x=0;
            for(int j=i-1;j>=0;j--){
                if(A[j]>z){
                    x=1;
                    break;
                }
                z++;
            }
            if(x==0){c=0; break;}
        }
    }
        
    return c;
}
