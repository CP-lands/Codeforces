//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>

using namespace std;
//https://codeforces.com/contest/1492/problem/D

#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here"<<nl
typedef long long ll;

void Solve(){
	int a, b, k;
	cin>>a>>b>>k;
	int n = a + b;
	string x = "", y = "";
	for(int i = 0; i < a + b; i++){
		x += '0';
		y += '0';
	}
	if(k == 0){
		int index = 0;
		while(b--){
			x[index] = '1';
			y[index++] = '1';
		}
		cout<<"Yes"<<nl;
		cout<<x<<nl<<y<<nl;
		return;
	}
	if(a + b <= k + 1 || b == 1){
		cout<<"No"<<nl;
		return;
	}
	x[a + b - 1 - k] = '1';
	y[a + b - 1] = '1';
	int high = a + b - 1 - k;
	int low = 0;
	b--;
	int index = 0;
	while(b-- && index < high){
		x[index] = '1';
		y[index++] = '1';
		low++;
	}
	high++;
	b++;
	if(b > 0){
		while(b--){
			x[high] = '1';
			y[high++] = '1';
		}
	}
	if(high >= n){
		cout<<"No"<<nl;
		return;
	}
	cout<<"Yes"<<nl;
	cout<<x<<nl<<y<<nl;

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}