#include<bits/stdc++.h>

//https://codeforces.com/contest/295/problem/A
using namespace std;

#define N 100001
long long v[N];
int l[N], r[N];
long long d[N];
long long flag[N + 1];
long long lazy[3 * N];

void update(int u, int a, int b, int low, int high, long long dis){
	if(a > high || b < low) return;
	if(a >= low && b <= high){
		lazy[u] += dis;
		return;
	}
	int mid = a + (b - a) / 2;
	update(2 * u, a, mid, low, high, dis);
	update(2 * u + 1, mid + 1, b, low, high, dis);
	return;
}
void res(int u, int a, int b){
	if(a == b){
		lazy[u] += lazy[u / 2];
		v[a] += lazy[u];
		return;
	}
	lazy[u] += lazy[u / 2];
	int mid = a + (b - a) / 2;
	res(2 * u, a, mid);
	res(2 * u + 1, mid + 1, b);
	return;
}

void Solve(){
	int n, m, k;
	cin>>n>>m>>k;
	memset(flag, 0, N + 1);
	memset(lazy, 0, 3 * N);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	for(int i = 1; i <= m; i++)
		cin>>l[i]>>r[i]>>d[i];
	for(int i = 0; i < k; i++){
		int x, y;
		cin>>x>>y;
		flag[x]++;
		flag[y + 1]--;
	}
	for(int i = 1; i <= m; i++){
		flag[i] += flag[i - 1];
		int low = l[i] - 1;
		int high = r[i] - 1;
		long long dis = (int)d[i] * flag[i];
		update(1, 0, n - 1, low, high, dis);
	}
	res(1, 0, n - 1);
	for(int i = 0; i < n; i++) cout<<v[i]<<" ";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Solve();
}