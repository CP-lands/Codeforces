#include<bits/stdc++.h>
 
//https://codeforces.com/contest/235/problem/A
using namespace std;
 
void Solve(){
    long long n;
    cin>>n;
    long long res = 0;
    if(n == 1) res = 1;
    else if(n == 2) res = 2;
    else if(n == 3) res = 6;
    else{
        if(n % 2 != 0){
            res = n * (n - 1) * (n - 2);
        }
        else if(n % 3 != 0) res = n * (n - 1) * (n - 3);
        else res = (n - 2) * (n - 1) * (n - 3);
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