#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1354/problem/D
using namespace std;
 
const int N = 1e6 + 1;
int st[4 * N];
 
void update(int u, int low, int high, int x, int val){
	if(low == high){
		st[u] += val;
		return;
	}
	int mid = low + (high - low) / 2;
	if(x <= mid) update(2 * u, low, mid, x, val);
	else update(2 * u + 1, mid + 1, high, x, val);
	st[u] = st[2 * u] + st[2 * u + 1];
}
int get(int u, int low, int high, int x){
	if(low == high){
		return low;
	}
	int mid = low + (high - low) / 2;
	if(st[2 * u] >= x) return get(2 * u, low, mid, x);
	else return get(2 * u + 1, mid + 1, high, x - st[2 * u]);
}
void Solve(){
 	int n, q;
 	cin>>n>>q;
 	memset(st, 0, 4 * N);
 	for(int i = 0; i < n; i++){
 		int x;
 		cin>>x;
 		update(1, 1, n, x, 1);
 	}
 	while(q--){
 		int x;
 		cin>>x;
 		if(x > 0) update(1, 1, n, x, 1);
 		else{
 			x = -x;
 			int y = get(1, 1, n, x);
 			update(1, 1, n , y, -1);
 		}
 	}
 	if(st[1] == 0) cout<<0<<'\n';
 	else cout<<get(1, 1, n, 1);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}