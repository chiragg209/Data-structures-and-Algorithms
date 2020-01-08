#include<iostream>
#include<cstring>
using namespace std;
string populate(const string &s){
    //cout<<s<<endl;
    string ans="(#";
    for(int i=0;i<s.length();i++){
        ans+=s[i];ans+='#';
        //cout<<ans<<endl;
    }
    ans+=')';
    //ans.pop_back();
    return ans;
}

int main(){
    //int t;cin>>t;while(t--){
    string s;cin>>s;
    string q=populate(s);//cout<<q<<endl;
    //longestPalindromeSubstring(s);
    int ar[q.length()];
    memset(ar,0,sizeof(ar));
    int c=0,r=0;cout<<q<<endl;
    for(int i=1;i<q.size()-1;i++){
        int mrr=2*c-i;
        if(i<r){
            //ar[i]=ar[mrr];
            ar[i]=min(ar[mrr],r-i);
        }
        while(q[ar[i]+1+i]==q[i-ar[i]-1]) ar[i]++;
        if(i+ar[i]>r){
            c=i;
            r=i+ar[i];
        }
        cout<<ar[i]<<" ";
    }
    int mp=0;string ans;
    for(int i=0;i<q.size();i++){
        if(ar[mp]<ar[i]){
            mp=i;
            //ans=s.substr((i-1-ar[i])/2,ar[i]);
        }
    }
    cout<<ar[mp]<<endl<<s.substr((mp-1-ar[mp])/2,ar[mp])<<endl;
    //}
}
