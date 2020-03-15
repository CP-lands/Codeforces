#include<bits/stdc++.h>

//https://codeforces.com/contest/158/problem/D 
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    vector<int> p;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(i * i != n){
                if(i > 2) p.push_back(i);
                if(n / i > 2) p.push_back(n / i);
            }
            else if(i > 2) p.push_back(i);
        }
    }
    long long res = INT_MIN;
    for(auto x: p){
        for(int i = 0; i < n / x; i++){
            long long tmp = 0;
            for(int j = i; j < n; j = j + (n / x)){
                tmp += v[j];
            }
            if(res < tmp) res = tmp;
        }
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
