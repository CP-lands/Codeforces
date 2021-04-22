//----------------just-trying-to-keep-this-happiness-----------------------
#include<bits/stdc++.h>

//https://codeforces.com/contest/1506/problem/E
 
using namespace std;
#define nl '\n'
 
void Alice(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	vector<int> mn(n), mx(n);
	set<int> s1, s2;
	for(int i = 1; i <= n; i++){
		s1.insert(i);
	}
	s1.erase(v[0]);
	for(int i = 1; i < v[0]; i++)
		s2.insert(i);
	int last = v[0] + 1;
	mn[0] = mx[0] = v[0];
	for(int i = 1; i < n; i++){
		if(v[i] == v[i - 1]){
			mn[i] = *s1.begin();
			s1.erase(s1.begin());
			mx[i] = *s2.rbegin();
			s2.erase(mx[i]);
		}
		else{
			mn[i] = v[i];
			s1.erase(v[i]);
			mx[i] = v[i];
			for(int j = last; j < v[i]; j++){
				s2.insert(j);
			}
			last = v[i] + 1;
		}
	}
	for(auto x: mn)
		cout<<x<<" ";
	cout<<nl;
	for(auto x: mx)
		cout<<x<<" ";
	cout<<nl;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int T = 1;
	cin>>T;
	while(T--){
		Alice();
	}
}