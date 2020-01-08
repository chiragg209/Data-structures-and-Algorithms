// https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int l=A.size();
    int I[l],D[l];
    
    for(int i=0;i<l;i++){
        I[i]=1;
        D[i]=1;    
        }
    for(int i=1;i<l;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j])
                I[i]=max(I[i],I[j]+1);
        }
    }
    for(int i=l-2;i>=0;i--){
        for(int j=l-1;j>i;j--){
            if(A[i]>A[j])
                D[i]=max(D[i],D[j]+1);
        }
    }
    int maxsum=1,sum=1;
    for(int i=0;i<l;i++){
        sum=D[i]+I[i];
        if(sum>maxsum)
            maxsum=sum;
    }
    return maxsum-1;
}
