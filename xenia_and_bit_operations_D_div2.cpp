#include<bits/stdc++.h>

//https://codeforces.com/contest/339/problem/D
using namespace std;

const int N = 150000;
int v[N];
int tree[3 * N];

void build(int node, int a, int b, int operation){
	if(a == b){
		tree[node] = v[a];
		return;
	}
	int mid = a + (b - a) / 2;
	if(operation == -1){
		build(2 * node + 1, a, mid, operation * (-1));
		build(2 * node + 2, mid + 1, b, operation * (-1));
		tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
	}
	else{
		build(2 * node + 1, a, mid, operation * (-1));
		build(2 * node + 2, mid + 1, b, operation * (-1));
		tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
	}
	return;
}
void update(int node, int a, int b, int i, int val, int operation){
	if(a == b){
		v[i] = val;
		tree[node] = val;
		return;
	}
	int mid = a + (b - a) / 2;
	if(mid >= i){
		if(operation == -1){
			update(2 * node + 1, a, mid, i, val, operation * (-1));
			tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
		}
		else{
			update(2 * node + 1, a, mid, i, val, operation * (-1));
			tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
		}
	}
	else{
		if(operation == -1){
			update(2 * node + 2, mid + 1, b, i, val, operation * (-1));
			tree[node] = tree[2 * node + 2] | tree[2 * node + 1];
		}
		else{
			update(2 * node + 2, mid + 1, b, i, val, operation * (-1));
			tree[node] = tree[2 * node + 2] ^ tree[2 * node + 1];
		}
	}
	return;
}
void Solve(){
	int n, q, operation;
	cin>>n>>q;
	if(n % 2 == 0) operation = 1;
	else operation = -1;
	memset(v, 0, pow(2, n) * 2 - 1);
	for(int i = 0; i < pow(2, n); i++)
		cin>>v[i];
	build(0, 0, pow(2, n) - 1, operation);
	while(q--){
		int i, val;
		cin>>i>>val;
		update(0, 0, pow(2, n) - 1, i - 1, val, operation);
		cout<<tree[0]<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Solve();
}