/*
 * Problem Name: Increasing_Subsequence
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
 
void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> tails;
 
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
 
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }
 
    cout << tails.size();
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}