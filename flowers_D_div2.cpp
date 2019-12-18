//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/474/D
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

ll fibo[100005];

void Anivia_kid(){
	int t, k;
	cin>>t>>k;
	fibo[0] = 0;
	for(int i = 1; i < k; i++)
		fibo[i] = 1;
	fibo[k] = 2;
	for(int i = k + 1; i < 100005; i++)
		fibo[i] = (fibo[i - 1] % MOD + fibo[i - k] % MOD) % MOD;
	for(int i = 1; i < 100005; i++)
		fibo[i] = (fibo[i - 1] % MOD + fibo[i] % MOD) % MOD;
	while(t--){
		int a, b;
		cin>>a>>b;
		ll tmp = (fibo[b] - fibo[a - 1]) % MOD;
		if(tmp < 0) tmp += MOD;
		cout<<tmp<<"\n";
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
