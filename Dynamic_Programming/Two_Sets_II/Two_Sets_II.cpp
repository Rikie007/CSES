/*
 * Problem Name: Two_Sets_II
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-12
 */

#include <bits/stdc++.h>
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Rikie cout.tie(NULL);
#define ll long long
int n;
int T;
int MOD = 1e9 + 7;
ll t[125251][501];
ll sol(int total, int n){
    if(total == T/2){
        return 1;
    }
    if(total < T/2){
        return 0;
    }
    if(n == 0) return 0;
    if(t[total][n] != -1){
        return t[total][n];
    }
    ll take = sol(total-n, n-1);
 
    ll notTake = sol(total, n-1);
 
    return t[total][n] = (take + notTake) % MOD;
}
void solve(){
    cin >> n;
 
    int total = (n * (n+1))/2;
    T = total;
    if(total & 1) {
        cout << 0 << endl;return ;
    }
    memset(t, -1, sizeof(t));
    cout << sol(total, n)/2;
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}