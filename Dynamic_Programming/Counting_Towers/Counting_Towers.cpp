/*
 * Problem Name: Counting_Towers
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-08
 */

#include <bits/stdc++.h>
using namespace std;
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Rikie cout.tie(NULL);
#define ll long long
int M = 1e9  + 7;
int N ;
 
void solve(){
    
    vector<vector<ll>> dp(1000001, vector<ll>(2,0));
 
    dp[1][1] = 1;
    dp[1][0] = 1;
 
    for(int i = 2 ; i<= 1000000; i++){
        dp[i][0] = (4 * dp[i-1][0] + dp[i-1][1]) % M;
        dp[i][1] = (2 * dp[i-1][1]  + dp[i-1][0]) % M;
    }
 
    int t; 
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
 
        cout << (dp[n][0] + dp[n][1]) % M << endl;
    }
    
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}