#include<bits/stdc++.h>
 
//https://codeforces.com/gym/101652/attachments
using namespace std;
 
void Solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> v(n);
    int MAX = 0;
    int left = 0, right = 0;
    //case1 B = -1, R = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B') v[i] = -1;
        else v[i] = 1;
    }
    int sum = 0;
    int tmp_left = 1, tmp_right = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        tmp_right++;
        if(sum > MAX){
            MAX = sum;
            left = tmp_left;
            right = tmp_right;
        }
        if(sum < 0){
            sum = 0;
            tmp_left = i + 2;
            tmp_right = i + 1;
        }
    }
    //case2 R = -1, B = 1
    int MAX2 = 0;
    int left2 = 0, right2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') v[i] = -1;
        else v[i] = 1;
    }
    sum = 0;
    tmp_left = 1, tmp_right = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        tmp_right++;
        if(sum > MAX2){
            MAX2 = sum;
            left2 = tmp_left;
            right2 = tmp_right;
        }
        if(sum < 0){
            sum = 0;
            tmp_left = i + 2;
            tmp_right = i + 1;
        }
    }
    if(MAX2 > MAX){
        cout<<left2<<" "<<right2<<'\n';
        return;
    }
    if(MAX > MAX2){
        cout<<left<<" "<<right<<'\n';
        return;
    }
    if(left < left2){
        cout<<left<<" "<<right<<'\n';
        return;
    }
    if(left2 < left){
        cout<<left2<<" "<<right2<<'\n';
        return;
    }
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}