#include<bits/stdc++.h>
 
//https://codeforces.com/contest/446/problem/A
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<1<<'\n';
        return;
    }
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    vector<int> left(n), right(n);
    left[1] = 1;
    for(int i = 2; i < n; i++){
        if(v[i - 1] > v[i - 2]) left[i] = left[i - 1] + 1;
        else left[i] = 1;
    }
    right[n - 2] = 1;
    for(int i = n - 3; i >= 0; i--){
        if(v[i + 1] < v[i + 2]) right[i] = right[i + 1] + 1;
        else right[i] = 1;
    }
    int res = 0;
    //cout<<left[1]<<" "<<right[1]<<'\n';
    for(int i = 0; i < n; i++){
        if(v[i + 1] - v[i - 1] > 1){
            int tmp = left[i] + right[i] + 1;
            if(res < tmp){
                res = tmp;
                //cout<<v[i]<<" "<<left[i]<<" "<<right[i]<<'\n';
            }
        }
        else{
            if(res < left[i] + 1) res = left[i] + 1;
            if(res < right[i] + 1) res = right[i] + 1;
        }
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