#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1451/problem/C
using namespace std; 
 
void Solve(){
    int n, k;
    cin>>n>>k;
    string a, b;
    cin>>a>>b;
    map<char, int> aa, bb;
    for(auto x: a) ++ aa[x];
    for(auto x: b) ++ bb[x];
    for(auto x: aa){
        int k = min(x.second, bb[x.first]);
        aa[x.first] -= k;
        bb[x.first] -= k;
    }
    string a1 = "", b1 = "";
    for(auto x: aa){
        while(x.second--){
            a1 += x.first;
        }
    }
    for(auto x: bb){
        while(x.second--){
            b1 += x.first;
        }
    }
    n = a1.size();
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
 
    int i = 0;
    //cout<<a1<<" "<<b1<<endl;
    while(i < n){
        if(a1[i] == b1[i]){
            i++;
            continue;
        }
        else if(a1[i] > b1[i]){
            cout<<"No\n";
            return;
        }
        else{
            int count = 1;
            if(count == k){
                i++;
                continue;
            }
            while(i < n - 1 && a1[i] == a1[i + 1] && b1[i] == b1[i + 1]){
                count++;
                i++;
                if(count == k) break;
            }
            i++;
            if(count < k){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
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
