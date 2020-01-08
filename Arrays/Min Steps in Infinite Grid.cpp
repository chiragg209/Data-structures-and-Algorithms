// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int l = A.size();
    int a=0,b=0;
    int steps=0;
    for(int i=0;i<l-1;i++){
        a=abs(A[i+1]-A[i]);
        b=abs(B[i+1]-B[i]);
        if(a>b)
            steps+=a;
        else
            steps+=b;
    }
    return steps;
}
