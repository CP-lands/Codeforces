#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1515/problem/D
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define bug cout<<"bug here!\n"
typedef long long ll;
 
void Solve(){
	int n, l, r;
	cin>>n>>l>>r;
	vector<int> L(l), R(r);
	vector<bool> used(n + 1);
	map<int, int> myMap;
	for(int i = 0; i < l; i++){
		cin>>L[i];
		used[L[i]] = true;
	}
	for(int i = 0; i < r; i++){
		cin>>R[i];
		used[R[i]] = true;
	}
	int cnt = 0;
	int countt = 0;
	for(int i = 1; i <= n; i++){
		if(used[i]){
			cnt++;
			myMap[i] = countt++;
		}
	}
	vector<pair<int, int>> color(cnt);
	for(int i = 0; i < l; i++){
		color[myMap[L[i]]].fi++;
	}
	for(int i = 0; i < r; i++){
		color[myMap[R[i]]].se++;
	}
 
 
	ll res = 0;
	ll left = 0, right = 0;
	int sameLeft = 0, sameRight = 0;
	for(auto x: color){
		if(x.fi > x.se){
			left += x.fi - x.se;
			sameLeft += ((x.fi - x.se) / 2) * 2;
		}
		else{
			right += x.se - x.fi;
			sameRight += ((x.se - x.fi) / 2) * 2;
		}
	}
	//cout<<res<<" "<<left<<" "<<right<<nl;
 
	res += min(left, right);
	ll k = min(left, right);
	left -= k;
	right -= k;
 
	//cout<<res<<" "<<left<<" "<<right<<" "<<sameLeft<<" "<<sameRight<<nl;
 
	if(left > 0){
		if(sameLeft >= left){
			res += left / 2;
		}
		else{
			res += sameLeft / 2;
			left -= ((sameLeft / 2) * 2);
			res += left;
		}
	}
 
	if(right > 0){
		if(sameRight >= right){
			res += right / 2;
		}
		else{
			res += sameRight / 2;
			right -= ((sameRight / 2) * 2);
			res += right;
		}
	}
 
	cout<<res<<nl;
 
 
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
 
}