#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1369/problem/C
using namespace std;
 
void Solve(){
	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	vector<int> w(k);
	for(int i = 0; i < k; i++)
		cin>>w[i];
	sort(v.rbegin(), v.rend());
	sort(w.begin(), w.end());
	long long res = 0;
	vector<int> maxx(k);
	for(int i = 0; i < k; i++){
		res += v[i];
		maxx[i] = v[i];
		w[i]--;
	}
	int i = k;
	int j = 0;
	while(j < k && w[j] == 0){
		res += maxx[j];
		j++;
	}
	//cout<<res<<" "<<i<<" "<<j<<endl;
	while(i < n && j < k){
		w[j]--;
		while(w[j]--){
			i++;
		}
		res += v[i];
		i++;
		j++;
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}