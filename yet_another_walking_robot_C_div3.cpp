//--------Anivia_kid---------//
//https://codeforces.com/contest/1296/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n;
	string s;
	cin>>n>>s;
	vector<int> x(n + 1), y(n + 1);
	for(int i = 0; i < n; i++){
		if(s[i] == 'L'){
			x[i + 1] = x[i] - 1;
			y[i + 1] = y[i];
		}
		if(s[i] == 'R'){
			x[i + 1] = x[i] + 1;
			y[i + 1] = y[i];
		}
		if(s[i] == 'D'){
			y[i + 1] = y[i] - 1;
			x[i + 1] = x[i];
		}
		if(s[i] == 'U'){
			y[i + 1] = y[i] + 1;
			x[i + 1] = x[i];
		}
	}
	map<pair<int, int>, int> mp;
	mp[{0, 0}] = 0;
	int res = n;
	int low = 0, high = 0;
	for(int i = 1; i <= n; i++){
		if(!mp.count({x[i], y[i]})){
			mp[{x[i], y[i]}] = i;
		}
		else{
			int tmp = i - mp[{x[i], y[i]}];
			if(tmp <= res){
				res = tmp;
				low = mp[{x[i], y[i]}] + 1;
				high = i;
			}
			mp[{x[i], y[i]}] = i;
		}
	}
	if(low == 0 && high == 0) cout<<-1<<'\n';
	else cout<<low<<" "<<high<<'\n';
 
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
}