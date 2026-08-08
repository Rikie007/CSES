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
int t[1001][100001];
int sol(int i, int cost, vector<int> &price, vector<int> &page){
    if(i >= N || cost < 0){
        return 0;
    }
    if(t[i][cost] != -1) return t[i][cost];
    int take = 0;
    if(price[i] <= cost)
        take = page[i] + sol(i+1, cost - price[i], price, page);
 
    int notTake = sol(i+1, cost, price, page);
 
    return t[i][cost] =  max(take, notTake);
}
void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> price;
    vector<int> page;
    N = n;
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
    memset(t, -1, sizeof(t));
 
    cout << sol(0,x, price, page);
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}