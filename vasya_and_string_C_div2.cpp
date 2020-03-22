#include<bits/stdc++.h>

//https://codeforces.com/contest/676/problem/C 
using namespace std;
 
void Solve(){
    int n, k;
    string s;
    cin>>n>>k>>s;
    int res = 0;
    vector<int> a, b;
    a.push_back(0); b.push_back(0);
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') a.push_back(i + 1);
        else b.push_back(i + 1);
    }
    if(a.size() <= k + 1 || b.size() <= k + 1){
        cout<<n<<'\n';
        return;
    }
    a.push_back(n + 1);
    b.push_back(n + 1);
    for(int i = k + 1; i < a.size(); i++){
        int tmp = a[i] - 1 - a[i - k - 1];
        if(res < tmp) res = tmp;
    }
    for(int i = k + 1; i < b.size(); i++){
        int tmp = b[i] - 1 - b[i - k - 1];
        if(res < tmp) res = tmp;
    }
    cout<<res<<'\n';
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