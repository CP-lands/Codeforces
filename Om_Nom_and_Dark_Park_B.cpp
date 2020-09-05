//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/526/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> lights(pow(2, n + 1));
	for(int i = 2; i < pow(2, n + 1); i++){
		cin>>lights[i];
	}
	ll res = 0;
	for(int i = pow(2, n + 1) - 1; i > 1; i = i - 2){
		int add = abs(lights[i] - lights[i - 1]);
		res += add;
		lights[i / 2] += max(lights[i], lights[i - 1]);
	}
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
