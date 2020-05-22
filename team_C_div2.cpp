#include<bits/stdc++.h>
 
//https://codeforces.com/contest/401/problem/C
using namespace std;
 
void Solve(){
    int n, m;
    cin>>n>>m;
    if(n - m > 1){
        cout<<-1<<'\n';
        return;
    }
    string res = "";
    int k = n + m;
    int i = 0;
    while(i < k){
        if(n >= m){
            if((i == 0) || (i > 0 && res[i - 1] != '0')){
                res += '0';
                n--;
            }
            else{
                if(m > 0){
                    if(i < 2 || (i >= 2 && (res[i - 1] == '0' || res[i + 1] == '0'))){
                        res += '1';
                        m--;
                    }
                    else{
                        cout<<-1<<'\n';
                        return;
                    }
                }
                else{
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
        else{
            if((i < 2 || (i >= 2 && (res[i - 2] == '0' || res[i - 1] == '0'))) && m > 0){
                res += '1';
                m--;
            }
            else{
                if(n > 0){
                    if((i == 0) || (i > 0 && res[i - 1] != '0')){
                        res += '0';
                        n--;
                    }
                    else{
                        cout<<-1<<'\n';
                        return;
                    }
                }
                else{
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
        i++;
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}