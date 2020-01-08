// https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &A) {
    int l=A.size();
    if(l==0)
        return 0;
    unordered_map <int, int> mp[l];
    
    int maxv=1,v=0;
    for(int j=1;j<l;j++){
        for(int i=0;i<j;i++){
            int diff=A[j]-A[i];
            if(i==0)
                mp[j][diff]=2;
            else if(mp[i][diff]>0)
                mp[j][diff]=mp[i][diff]+1;
            else
                mp[j][diff]=2;
            
            if(mp[j][diff] > maxv)
                maxv = mp[j][diff];
        }
    }
    return maxv;
}
