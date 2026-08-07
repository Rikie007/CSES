/*
 * Problem Name: Removing_Digits
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
 
int t[1000001];
 
int sol(int sum){
    if(sum < 0) return INT_MAX;
    
    if(sum == 0) return 0;
    if(t[sum] != -1) return t[sum];
    vector<bool> flag(10, false);
    int tmp = sum;
    while(tmp){
        flag[tmp%10] = true;
        tmp /= 10;
    }
    int ans = INT_MAX;
    for(int i = 1 ; i < 10; i++){
        if(flag[i]){
            int del = sol(sum - i);
 
            if(del != INT_MAX){
                ans = min(ans, 1 + del);
            }
        }
    }
    return t[sum] = ans;
}
 
void solve(){
    int n;
    cin >> n;
    
    memset(t, -1, sizeof(t));
    cout << sol(n) ;
}
 
int main(){
 
    Code By Rikie
 
    
        solve();
 
    return 0;
}