#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int l=t.length();
	int n=s.length();
	int lps[l];
	lps[0]=0;
	int i=1;
	while(i<l){
		int j = lps[i-1];
        while (j > 0 && t[i] != t[j])	j = lps[j-1];
        if (t[i] == t[j])  j++;
        lps[i]=j;
        cout<<lps[i]<<" ";
		i++;
	}
	return 0;
}
