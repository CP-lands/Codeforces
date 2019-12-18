//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/545/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n;
	cin>>n;
	int tree[100005][2];
	for(int i = 1; i <= n; i++){
		cin>>tree[i][0]>>tree[i][1];
	}
	int res = 1;
	int left = tree[1][0];
	for(int i = 2; i < n; i++){
		if(tree[i][0] - tree[i][1] > left){
			res++;
			left = tree[i][0];
		}
		else if(tree[i][0] + tree[i][1] < tree[i + 1][0]){
			res++;
			left = tree[i][0] + tree[i][1];
		}
		else left = tree[i][0];
	}
	if(n > 1) res++;
	cout<<res<<"\n";

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
}
