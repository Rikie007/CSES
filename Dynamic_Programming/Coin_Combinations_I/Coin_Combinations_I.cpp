/*
 * Problem Name: Coin_Combinations_I
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-07
 */

#include <bits/stdc++.h>
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Rikie cout.tie(NULL);
#define ll long long
vector<int> arr;
int tar ;
ll t[1000001];
int M = 1e9 + 7;
ll sol(int sum){
    if(sum == tar) return 1;
    if(sum > tar) return 0;
 
    if(t[sum] != -1)
        return t[sum];
 
    ll ans = 0;
 
    for(int coin : arr){
        ans = (ans + sol(sum + coin)) % M;
    }
 
    return t[sum] = ans;
}
void solve(){
    int n, x;
    cin >> n >> x;
    tar = x;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    memset(t, -1, sizeof(t));
    ll ans = sol(0);
    cout << ans << endl;
}
 
int main(){
 
    Code By Rikie
 
    
        solve();
 
 
    return 0;
}