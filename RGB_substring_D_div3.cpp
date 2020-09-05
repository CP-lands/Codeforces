//--------Anivia_kid---------//
//https://codeforces.com/contest/1196/problem/D2
#include<bits/stdc++.h>
 
using namespace std;
 
void Solve(){
    int n, k;
    string s;
    cin>>n>>k>>s;
    string t1 = "", t2 = "", t3 = "";
    for(int i = 0; i < n; i++){
        if(i % 3 == 0){
            t1 += 'R';
            t2 += 'G';
            t3 += 'B';
        }
        if(i % 3 == 1){
            t1 += 'G';
            t2 += 'B';
            t3 += 'R';
        }
        if(i % 3 == 2){
            t1 += 'B';
            t2 += 'R';
            t3 += 'G';
        }
    }
    vector<int> dp1(n - k + 1), dp2(n - k + 1), dp3(n - k + 1);
    for(int i = 0; i < k; i++){
        if(s[i] == t1[i]) dp1[0]++;
        if(s[i] == t2[i]) dp2[0]++;
        if(s[i] == t3[i]) dp3[0]++;
    }
    int j = 1;
    for(int i = k; i < n; i++){
        dp1[j] = dp1[j - 1];
        dp2[j] = dp2[j - 1];
        dp3[j] = dp3[j - 1];
        if(s[i] == t1[i]) dp1[j]++;
        if(s[i - k] == t1[i - k]) dp1[j]--;
        if(s[i] == t2[i]) dp2[j]++;
        if(s[i - k] == t2[i - k]) dp2[j]--;
        if(s[i] == t3[i]) dp3[j]++;
        if(s[i - k] == t3[i - k]) dp3[j]--;
        j++;
    }
    int maxx = 0;
    for(auto x: dp1){
        //cout<<x<<" ";
        if(x > maxx) maxx = x;
    }
    for(auto x: dp2){
        if(x > maxx) maxx = x;
    }
    for(auto x: dp3){
        if(x > maxx) maxx = x;
    }
    cout<<k - maxx<<'\n';
    //cout<<t1<<" "<<t2<<" "<<t3<<'\n';
 
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
