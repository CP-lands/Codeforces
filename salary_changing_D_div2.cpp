//___1 WA == 5 Push up___
//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1251/D
using namespace std;
 
typedef long long ll; 
 
const int MOD = 1e9 + 7;
 
bool isPossible(vector<vector<int>> &v, int p, ll current, int n){
	int count = 0;
	for(int i = n - 1; i >= 0; i--){
		if(v[i][0] >= p) count++;
		else if(v[i][0] < p){
			if(v[i][1] >= p){
				if(current >= p - v[i][0])
				{
					current -= (p - v[i][0]);
					count++;
				}
				else break;
			}
		}
	}
	if(count > n / 2) return true;
	return false;
}
void Anivia_kid(){
	ll n, s;
	ll min_money = 0;
	cin>>n>>s;
	vector<vector<int>> v(n, vector<int>(2));
	vector<int> v1(n);
	for(int i = 0; i < n; i++)
	{
		cin>>v[i][0]>>v[i][1];
		v1[i] = v[i][1];
		min_money += v[i][0];
	}
	ll current = s - min_money;
	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	int low = v[n / 2][0];
	int high = v1[n / 2]; 

	while(high > low){
		int mid = low + (high - low) / 2;
		if(isPossible(v, mid, current, n)) low = mid;
		else high = mid - 1;
		if(high - low == 1){
			if(isPossible(v, high, current, n)){
				cout<<high<<endl;
				return;
			}
			cout<<low<<endl;
			return;
		}
	}
	cout<<low<<endl;
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}

	return 0;
}
