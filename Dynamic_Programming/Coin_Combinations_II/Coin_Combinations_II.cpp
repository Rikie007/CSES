/*
 * Problem Name: Coin_Combinations_II
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-07
 */

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int MOD = 1e9 + 7;
 
int n, x;
vector<int> coins;
vector<vector<ll>> dp;
 
ll ways(int idx, int sum) {
    if (sum == x) return 1;
    if (sum > x) return 0;
    if (idx == n) return 0;
 
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
 
    ll ans = 0;
 
    // Take current coin
    ans += ways(idx, sum + coins[idx]);
 
    // Skip current coin
    ans += ways(idx + 1, sum);
 
    ans %= MOD;
 
    return dp[idx][sum] = ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> x;
 
    coins.resize(n);
    for (int &c : coins)
        cin >> c;
 
    dp.assign(n + 1, vector<ll>(x + 1, -1));
 
    cout << ways(0, 0) << '\n';
}