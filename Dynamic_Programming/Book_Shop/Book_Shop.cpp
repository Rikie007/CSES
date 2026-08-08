/*
 * Problem Name: Book_Shop
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
int N ;
void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> price;
    vector<int> page;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        price.push_back(x);
    }
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        page.push_back(x);
    }
    vector<int> prev(x+1,0);
    for(int i = 1; i <= n; i++){
        vector<int> curr(x+1);
        for(int j = 0 ; j <= x ; j++){
            int take = 0;
            if(j - price[i-1] >= 0) take = page[i-1] + prev[j-price[i-1]];
            curr[j] = max(prev[j],take);
        }
        prev = curr;
    }
    cout << prev[x];
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}