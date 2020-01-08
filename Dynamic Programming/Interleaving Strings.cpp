// https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) {
    int l1=A.length(),l2=B.length(), l3=C.length();
    if(l1+l2!=l3)
        return 0;

    
    vector<vector<int> > temp(l1+1, vector<int>(l2+1, 0));
    
    temp[0][0] = 1;
    
    for(int i = 1; i < temp.size(); i++){
        if(C[i-1] == A[i-1]){
            temp[i][0] = temp[i-1][0];
        }
    }
    
    for(int i = 1; i < temp[0].size(); i++){
        if(C[i-1] == B[i-1]){
            temp[0][i] = temp[0][i-1];
        }
    }
    
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if((C[i+j-1] == A[i-1]) && (C[i+j-1] == B[j-1])){
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
            }
            else if(C[i+j-1] == A[i-1]){
                temp[i][j] = temp[i-1][j];
            }
            else if(C[i+j-1] == B[j-1]){
                temp[i][j] = temp[i][j-1];
            }
        }
    }
        
    
    return temp[l1][l2];   
}
