#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1451/problem/D
using namespace std; 
 
void Solve(){
    long long d, k;
    cin>>d>>k;
    int steps = 0;
    long long x = 0, y = 0;
    while(x * x + y * y <= d * d){
        if(x <= y){
            if((x + k) * (x + k) + y * y <= d * d){
                steps++;
                x += k;
            }
            else break;
        }
        else{
            if((y + k) * (y + k) + x * x <= d * d){
                steps++;
                y += k;
            }
            else break;
        }
    }
    if(steps % 2) cout<<"Ashish\n";
    else cout<<"Utkarsh\n";
 
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