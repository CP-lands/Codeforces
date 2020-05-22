#include<bits/stdc++.h>
 
//https://codeforces.com/contest/832/problem/D
using namespace std;

const int N = 1e5 + 1;
int v[2 * N];
int depth[N];
vector<int> g[N];
int countt = 0;
int tree[8 * N];
int ver[N];
int n, q;

void dfs(int u, int p = -1){
	ver[u] = countt;
    v[countt++] = u;
    for(auto x: g[u]){
        if(x == p) continue;
        depth[x] = depth[u] + 1;
        dfs(x, u);
        v[countt++] = u;
    }
}
void build(int u, int a, int b){
	if(a == b){
		tree[u] = v[a];
		return;
	}
	int mid = a + (b - a) / 2;
	build(2 * u, a, mid);
	build(2 * u + 1, mid + 1, b);
	if(depth[tree[2 * u]] < depth[tree[2 * u + 1]]) tree[u] = tree[2 * u];
	else tree[u] = tree[2 * u + 1];
}
int lca(int u, int a, int b, int l, int r){
	if(a > r || b < l) return INT_MAX;
	if(a >= l && b <= r){
		return tree[u];
	}
	int mid = a + (b - a) / 2;
	int left = lca(2 * u, a, mid, l, r);
	int right = lca(2 * u + 1, mid + 1, b, l, r);
	if(left == INT_MAX) return right;
	if(right == INT_MAX) return left;
	if(depth[left] < depth[right]) return left;
	else return right;
	
}
int res(int s, int f, int t){
	int l = ver[s], r = ver[f];
	if(l > r) swap(l, r);
	int sf = lca(1, 0, 2 * n - 2, l, r);
	l = ver[t]; r = ver[f];
	if(l > r) swap(l, r);
	int tf = lca(1, 0, 2 * n - 2, l, r);
	if(sf == tf){
		l = ver[s]; r = ver[t];
		if(l > r) swap(l, r);
		int st = lca(1, 0, 2 * n - 2, l, r);
		return depth[st] + depth[f] - 2 * depth[sf];
	}
	else{
		int final;
		if(depth[sf] > depth[tf]) final = sf;
		else final = tf;
		return depth[f] - depth[final];
	}
}
void Solve(){
    cin>>n>>q;
    for(int i = 2; i <= n; i++){
    	int u;
    	cin>>u;
    	g[u].push_back(i);
    	g[i].push_back(u);
    }
    depth[1] = 0;
    dfs(1);
    build(1, 0, 2 * n - 2);
    while(q--){
    	int a, b, c;
    	int ans = 0;
    	cin>>a>>b>>c;
    	//aaaaaaaa
    	if(ans < res(a, b, c)) ans = res(a, b, c);
    	if(ans < res(a, c, b)) ans = res(a, c, b);
    	if(ans < res(b, a, c)) ans = res(b, a, c);
    	cout<<ans + 1<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}