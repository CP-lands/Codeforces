#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1536/problem/C
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define bug cout<<"bug here!\n"
typedef long long ll;
 
void Solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<pair<int, int>> prefix(n);
	for(int i = 0; i < n; i++){
		if(i > 0){
			prefix[i].fi = prefix[i - 1].fi;
			prefix[i].se = prefix[i - 1].se;
		}
		if(s[i] == 'D') prefix[i].fi++;
		else prefix[i].se++;
	}
	map<double, int> myMap;
	for(int i = 0; i < n; i++){
		double a = prefix[i].fi;
		double b = prefix[i].se;
		if(a == 0 || b == 0){
			if(a == 0) cout<<b<<" ";
			else cout<<a<<" ";
		}
		else{
			myMap[a / b]++;
			cout<<myMap[a / b]<<" ";
		}
	}
	cout<<nl;
 
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
 
}