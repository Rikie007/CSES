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
int MOD = 1e9 + 7;
const ll INV2 = 500000004;
void solve(){
    cin >> n;
 
    int total = (n * (n+1))/2;
    if(total & 1) {
        cout << 0 << endl;return ;
    }
 
    vector<vector<ll>> dp(n+1, vector<ll>(total/2+1, 0LL));
 
    dp[0][0] = 1;
    for(int i = 1; i <= min(n, total/2); i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= total/2; j++){
            dp[i][j] = dp[i-1][j];
 
            if(j >= i) {
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= MOD;
            }
        }
    }
 
    ll ans = dp[n][total/2];
 
 
    cout << ans * INV2 % MOD << endl;
 
 
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}