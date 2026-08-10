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
int t[501][501];
int sol(int a, int b){
    if(a <= 0 || b <= 0) return 0;
    if(a == b){
        return 0;
    }
    if(t[a][b] != -1) return t[a][b];
    int ans = INT_MAX;
    for(int i = 1 ; i < a; i++){
        ans = min(ans, 1 + sol(a-i, b) + sol(i,b));
    }
    for(int i = 1; i < b ; i++){
        ans = min(ans, 1 + sol(a, b-i) + sol(a,i));
    }
    return t[a][b] = ans;
}
 
 
void solve(){
    int a, b; cin >> a >> b;
    memset(t,-1,sizeof(t));
    cout <<  sol(min(a,b),max(a,b));
 
}
 
int main(){
 
    Code By Rikie
 
    
        solve();
        
    
    return 0;
}