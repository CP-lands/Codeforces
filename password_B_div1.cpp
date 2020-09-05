#include<bits/stdc++.h>
 
//https://codeforces.com/contest/126/problem/B
using namespace std;
 
void error(){
	cout<<"Just a legend"<<'\n';
}
vector<int> prefix(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void Solve(){
	string s;
	cin>>s;
	vector<int> pr = prefix(s);
	int n = s.size();
	if(pr[n - 1] == 0){
		error();
		return;
	}
	for(int i = 1; i < n - 1; i++){
		if(pr[i] == pr[n - 1]){
			for(int j = 0; j < pr[n - 1]; j++) cout<<s[j];
			return;
		}
	}
	if(pr[pr[n - 1] - 1] == 0){
		error();
		return;
	}
	for(int i = 0; i < pr[pr[n - 1] - 1]; i++) cout<<s[i];
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}