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
int M = 1e9 + 7;  
void solve(){
    int n, x;
    cin >> n >> x;
    tar = x;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
 
    vector<ll> dp(x+1, 0LL);
    dp[x] = 1;
    int sz = arr.size();
    for(int i = x-1 ; i >= 0; i--){
        for(int j = 0; j < sz; j++){
            if(i + arr[j] <= x){
                dp[i] = (dp[i] + dp[i+arr[j]]) ;
                if(dp[i] >= M){
                    dp[i] -= M;
                }
            }
        }
    }
    cout << dp[0] << endl;
}
 
int main(){
 
    Code By Rikie
 
    
        solve();
 
 
    return 0;
}