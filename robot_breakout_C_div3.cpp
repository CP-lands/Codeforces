//--------Anivia_kid---------//
//https://codeforces.com/contest/1196/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n;
	cin>>n;
	int x_max = 100000, x_min = -100000;
	int y_max = 100000, y_min = -100000;
	for(int i = 0; i < n; i++){
		int a, b, f1, f2, f3, f4;
		cin>>a>>b>>f1>>f2>>f3>>f4;
		if(f1 == 0){
			x_min = max(x_min, a);
		}
		if(f3 == 0){
			x_max = min(x_max, a);
		}
		if(f2 == 0){
			y_max = min(y_max, b);
		}
		if(f4 == 0){
			y_min = max(y_min, b);
		}
	}
	if(y_min > y_max || x_min > x_max){
		cout<<0<<'\n';
		return;
	}
	cout<<1<<" "<<x_min<<" "<<y_min<<'\n';
 
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
}
