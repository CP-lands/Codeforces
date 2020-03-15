#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1312/problem/C
using namespace std;
 
long long power(long long a, long long k)
{
    if (k == 0) return 1;
    if (k == 1) return a;
    long long tmp = power(a, k >> 1);
    tmp = (tmp * tmp);
    return k % 2 ? (tmp * a) : tmp;
}
 
void Solve(){
	int maxx = 0;
	set<int> s;
	int n, k;
	cin>>n>>k;
	int t = 2;
	while(maxx == 0){
		if(power(k, t) > 1e16) maxx = t;
		t++;
	}
	vector<long long> a(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	sort(a.begin(), a.end());
	int i = 0;
	while(i < n && a[i] == 0){
		i++;
	}
	//cout<<maxx<<endl;
	while(i < n){
		for(int j = maxx; j >= 0; j--){
			if(a[i] >= power(k, j)){
				if(s.find(j) != s.end()){
					cout<<"NO\n";
					return;
				}
				s.insert(j);
				a[i] -= power(k, j);
			}
		}
		if(a[i] > 0){
			cout<<"NO\n";
			return;
		}
		i++;
	}
	cout<<"YES\n";
 
	return;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while(q--){
    	Solve();
    }
}