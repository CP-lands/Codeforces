//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1266/problem/D
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<ll> balance(n + 1);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		balance[a] -= c;
		balance[b] += c;
	}
	vector<vector<ll>> bal(n, vector<ll> (2));
	for(int i = 0; i < n; i++){
		bal[i][0] = balance[i + 1];
		bal[i][1] = i + 1;
	}
	sort(bal.begin(), bal.end());
	int low = 0;
	int high = n - 1;
	vector<tuple<int, int, ll>> res;
	while(high > low){
		if(bal[low][0] == 0) low++;
		else if(bal[high][0] == 0) high--;
		else if(-bal[low][0] == bal[high][0]){
			res.eb(bal[low][1], bal[high][1], -bal[low][0]);
			low++;
			high--;
		}
		else if(-bal[low][0] > bal[high][0]){
			res.eb(bal[low][1], bal[high][1], bal[high][0]);
			bal[low][0] += bal[high][0];
			high--;
		}
		else if(-bal[low][0] < bal[high][0]){
			res.eb(bal[low][1], bal[high][1], -bal[low][0]);
			bal[high][0] += bal[low][0];
			low++;
		}
	}
	cout<<res.size()<<'\n';
	for(auto& x: res){
		cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<'\n';
	}
 
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