#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/670/D2
using namespace std;

void Solve(){
	int n, k;
	cin>>n>>k;
	vector<long long> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < n; i++)
		cin>>b[i];
	int res = 0;
	int low = 0, high = INT_MAX;
	int exit = 0;
	while(low < high){
		long long mid = low + (high - low) / 2;
		if(exit == 2) mid = high;
		long long remain = k;
		bool good = true;
		for(int i = 0; i < n; i++){
			if(a[i] * mid <= b[i]) continue;
			long long need = a[i] * mid - b[i];
			if(need > remain){
				good = false;
				break;
			}
			remain -= need;
		}
		if(good){
			res = mid;
			low = mid;
		}
		else high = mid;
		if(high - low == 1) exit++;
		if(exit == 3) break;
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}