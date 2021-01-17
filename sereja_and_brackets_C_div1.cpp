//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
 
//https://codeforces.com/contest/380/problem/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
typedef long long ll;
 
const int N = 1e6 + 1;
int tree[4 * N];
int l[4 * N];
int r[4 * N];
int n;
string s;
 
void build(int u, int low, int high){
	if(low == high){
		tree[u] = 0;
		if(s[low] == ')'){
			r[u] = 1;
			l[u] = 0;
		}
		else{
			r[u] = 0;
			l[u] = 1;
		}
		return;
	}
	int mid = low + (high - low) / 2;
	build(2 * u, low, mid);
	build(2 * u + 1, mid + 1, high);
	tree[u] = tree[2 * u] + tree[2 * u + 1];
	int newAdded = min(l[2 * u], r[2 * u + 1]);
	tree[u] += newAdded;
	l[u] = l[2 * u] - newAdded + l[2 * u + 1];
	r[u] = r[2 * u + 1] - newAdded + r[2 * u];
}
pair<int, pair<int, int>> get(int u, int low, int high, int left, int right){
	if(left > high || right < low) return {0, {0, 0}};
	if(low >= left && high <= right){
		return {tree[u], {l[u], r[u]}};
	}
	int mid = low + (high - low) / 2;
	pair<int, pair<int, int>> p1 = get(2 * u, low, mid, left, right);
	pair<int, pair<int, int>> p2 = get(2 * u + 1, mid + 1, high, left, right);
	int newAdded = min(p1.se.fi, p2.se.se);
	return {p1.fi + p2.fi + newAdded, {p1.se.fi - newAdded + p2.se.fi, p2.se.se - newAdded + p1.se.se}};
}
 
void Solve(){
	cin>>s;
	n = s.size();
	build(1, 0, n - 1);
	int q;
	cin>>q;
	while(q--){
		int left, right;
		cin>>left>>right;
		left--; right--;
		pair<int, pair<int, int>> p = get(1, 0, n - 1, left, right);
		cout<<p.fi * 2<<nl;
	}
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}
