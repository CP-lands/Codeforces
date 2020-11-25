#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1454/problem/C
using namespace std; 
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n + 1);
       map<int, vector<int>> mm;
    for(int i = 1; i <= n; i++){
    	cin>>v[i];
    	mm[v[i]].push_back(i);
    }
    int res = INT_MAX;
    for(auto x: mm){
    	int tmp = 0;
    	if(x.second[0] != 1) tmp++;
    	if(x.second.back() != n) tmp++;
    	for(int i = 0; i < x.second.size() - 1; i++){
    		if(x.second[i + 1] - x.second[i] > 1) tmp++;
    	}
    	res = min(res, tmp);
    }
    cout<<res<<endl;
    //cout<<"---\n";
}
int main()  
{  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}