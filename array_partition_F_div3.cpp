#include<bits/stdc++.h>  

//https://codeforces.com/contest/1454/problem/F
using namespace std; 
map<int, int> mm;

void reduce(int val){
    --mm[val];
    if(mm[val] == 0) mm.erase(val);
}
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n), suf(n), pre(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        ++mm[v[i]];
        if(i > 0) pre[i] = max(pre[i - 1], v[i]);
        else pre[i] = v[i];
    }
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1) suf[i] = v[i];
        else suf[i] = max(suf[i + 1], v[i]);
    }
    int low = 0, high = n - 1;
    reduce(v[low]);
    reduce(v[high]);
    while(low < high - 1){
        if(pre[low] == suf[high]){
            int minn;
            for(auto x: mm){
                minn = x.first;
                break;
            }
            //cout<<minn<<endl;
            if(minn == pre[low]){
                cout<<"YES\n";
                cout<<low + 1<<" "<<high - low - 1<<" "<<n - high<<'\n';
                return;
            }
            if(v[low + 1] < v[high - 1]){
                low++;
                reduce(v[low]);
                continue;
            }
            if(v[low + 1] > v[high - 1]){
                high--;
                reduce(v[high]);
                continue;
            }
            if(v[low + 1] != pre[low]){
                low++;
                reduce(v[low]);
                continue;
            }
            if(pre[high] == pre[low]){
                cout<<"YES\n";
                cout<<low + 1<<" "<<1<<" "<<n - low - 2<<'\n';
                return;
            }
            else{
                if(v[low + 2] > v[low + 1]){
                    high--;
                    reduce(v[high]);
                }
                else{
                    low++;
                    reduce(v[low]);
                }
            }
        }
        else if(pre[low] < suf[high]){
            low++;
            reduce(v[low]);
        }
        else{
            high--;
            reduce(v[high]);
        }
    }
    cout<<"NO\n";
}
int main()  
{  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        mm.clear();
        Solve();
    }
}
