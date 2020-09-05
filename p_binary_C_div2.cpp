//___1 WA == 5 Push up___
//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1225/C
using namespace std;
 
typedef long long ll; 
 
const int MOD = 1e9 + 7;
bool isPossible(int mid, int n, int p){
	ll k = n - mid * p;
	ll temp = k;
	if(k <= 0) return false;
	int res = 0;
	while(k > 0){
		int tmp = 1;
		while(tmp <= k){
			tmp *= 2;
		}
		res++;
		k = k - tmp / 2;
	}
	if(temp < mid || res > mid) return false;
	return true;
}
void Anivia_kid(){
	int n, p;
	cin>>n>>p;
	int low = 1;
	while(low < 1000000){
		if(isPossible(low, n, p))
		{
			cout<<low<<endl;
			return;
		}
		low++;
	}
 	cout<<-1<<endl;
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
