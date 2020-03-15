#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1324/problem/D
using namespace std;
 
void Solve(){
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < n; i++)
		cin>>b[i];
	vector<int> dif(n);
	for(int i = 0; i < n; i++)
		dif[i] = a[i] - b[i];
	sort(dif.begin(), dif.end());
	long long res = 0;
	for(int i = 0; i < n; i++){
		int x = -dif[i];
		int p = upper_bound(dif.begin(), dif.end(), x) - dif.begin();
		//cout<<p<<" ";
		p = min(n - p, n - i - 1);
		//cout<<p<<endl;
		res += p;
	}
	cout<<res<<'\n';
 
	return;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}