//--------Anivia_kid---------//
//https://codeforces.com/contest/1279/problem/B
#include<bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	ll n, s;
	cin>>n>>s;
	vector<ll> v(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin>>v[i];
		sum += v[i];
	}
	if(sum <= s){
		cout<<0<<'\n';
		return;
	}
	vector<ll> a(n);
	a[0] = v[0];
	for(int i = 1; i < n; i++){
		a[i] = v[i] + a[i - 1];
	}
	int res = 0;
	int l = INT_MIN;
	for(int i = 0; i < n; i++){
		if(i > 0 && a[i - 1] >= s) break;
		ll x = v[i] + s;
		int low = 0;
		int high = n - 1;
		int mid = 0;
		while(high > low){
			mid = low + (high - low) / 2;
			if(a[mid] == x) break;
			else if(a[mid] > x) high = mid;
			else if(a[mid] < x) low = mid;
			if(high - low == 1) break;
		}
		int tmp;
		if(a[high] <= x) tmp = high;
		else if(a[mid] <= x) tmp = mid;
		else tmp = low;
		if(tmp > l){
			l = tmp;
			res = i + 1;
		}
	}
	cout<<res<<'\n';

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