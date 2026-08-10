/*
 * Problem Name: Rectangle_Cutting
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-10
 */

#include <bits/stdc++.h>
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Rikie cout.tie(NULL);
#define ll long long
 
int sol(int a, int b){
    if(a <= 0 || b <= 0) return 0;
    if(a == b){
        return 0;
    }
    
    return 1 + sol(a,a) + sol(min(a,b-a),max(a,b-a));
}
 
 
void solve(){
    int a, b; cin >> a >> b;
 
    cout <<  sol(min(a,b),max(a,b));
 
}
 
int main(){
 
    Code By Rikie
 
    
        solve();
        
    
    return 0;
}