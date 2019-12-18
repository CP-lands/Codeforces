//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/489/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	if(n == 1 && m == 0){
		cout<<0<<" "<<0<<"\n";
		return;
	}
	if(m == 0 || n * 9 < m){
		cout<<-1<<" "<<-1<<"\n";
		return;
	}
	string maxx = "";
	string minn = "";
	int k = m - 1;
	for(int i = 0; i < n - 1; i++){
		int tmp = min(9, k);
		minn += tmp + '0';
		k -= tmp;
	}
	minn += max(1, k + 1) + '0';
	for(int i = 0; i < n; i++){
		int tmp = min(9, m);
		maxx += tmp + '0';
		m -= tmp;
	}
	for(int i = n - 1; i >= 0; i--)
		cout<<minn[i];
	cout<<" "<<maxx<<"\n";

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
