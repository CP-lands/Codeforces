//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1486/problem/B
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Solve(){
	int n;
	cin>>n;
	vector<int> dx(n), dy(n);
	for(int i = 0; i < n; i++){
		cin>>dx[i]>>dy[i];
	}
	sort(dx.begin(), dx.end());
	sort(dy.begin(), dy.end());
	ll min_x = 1e18, min_y = 1e18;
	for(int i = 0; i < n; i++){
		ll tmp = 0;
		ll tmp2 = 0;
		for(int j = 0; j < n; j++){
			tmp += abs(dx[i] - dx[j]);
			tmp2 += abs(dy[i] - dy[j]);
		}
		min_x = min(min_x, tmp);
		min_y = min(min_y, tmp2);
	}
	int l1 = 0, r1 = n - 1, l2 = 0, r2 = n - 1;
	while(l1 < n){
		ll tmp = 0;
		for(int i = 0; i < n; i++){
			tmp += abs(dx[i] - dx[l1]);
		}
		if(tmp == min_x) break;
		l1++;
	}
	while(r1 >= 0){
		ll tmp = 0;
		for(int i = 0; i < n;  i++){
			tmp += abs(dx[i] - dx[r1]);
		}
		if(tmp == min_x) break;
		r1--;
	}
	while(l2 < n){
		ll tmp = 0;
		for(int i = 0; i < n; i++){
			tmp += abs(dy[i] - dy[l2]);
		}
		if(tmp == min_y) break;
		l2++;
	}
	while(r2 >= 0){
		ll tmp = 0;
		for(int i = 0; i < n; i++){
			tmp += abs(dy[i] - dy[r2]);
		}
		if(tmp == min_y) break;
		r2--;
	}
	ll left_x = dx[l1];
	ll right_x = dx[r1];
	ll left_y = dy[l2];
	ll right_y = dy[r2];
	ll res = (right_x - left_x + 1) * (right_y - left_y + 1);
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