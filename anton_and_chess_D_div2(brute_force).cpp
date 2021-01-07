//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://codeforces.com/contest/734/problem/D
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, x0, y0;
    cin>>n>>x0>>y0;
    int north = -1e9 - 1;
    int south = 1e9 + 1;
    int west = -1e9 - 1;
    int east = 1e9 + 1;
    int nw = -1e9 - 1;
    int ne = 1e9 + 1;
    int se = 1e9 + 1;
    int sw = -1e9 - 1;
    char N = '.', S = '.', W = '.', E = '.', NW = '.', NE = '.', SE = '.', SW = '.';
    while(n--){
        char c;
        int x, y;
        cin>>c>>x>>y;
        if(x == x0){
            if(y < y0 && y > west){
                W = c;
                west = y;
            }
            else if(y > y0 && y < east){
                E = c;
                east = y;
            }
        }
        if(y == y0){
            if(x < x0 && x > north){
                N = c;
                north = x;
            }
            else if(x > x0 && x < south){
                S = c;
                south = x;
            }
        }
        if(abs(x - x0) != abs(y - y0)) continue;
        if(x - x0 < 0 && y - y0 < 0 && y > nw){
            NW = c;
            nw = y;
        }
        if(x - x0 < 0 && y - y0 > 0 && y < ne){
            NE = c;
            ne = y;
        }
        if(x - x0 > 0 && y - y0 < 0 && y > sw){
            SW = c;
            sw = y;
        }
        if(x - x0 > 0 && y - y0 > 0 && y < se){
            SE = c;
            se = y;
        }
    }
    bool check = false;
    if(north >= -1e9 && (N == 'R' || N == 'Q')) check = true;
    if(south <= 1e9 && (S == 'R' || S == 'Q')) check = true;
    if(west >= -1e9 && (W == 'R' || W == 'Q')) check = true;
    if(east <= 1e9 && (E == 'R' || E == 'Q')) check = true;
    if(nw >= -1e9 && (NW == 'B' || NW == 'Q')) check = true;
    if(ne <= 1e9 && (NE == 'B' || NE == 'Q')) check = true; 
    if(se <= 1e9 && (SE == 'B' || SE == 'Q')) check = true;
    if(sw >= -1e9 && (SW == 'B' || SW == 'Q')) check = true;
 
    if(check) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}