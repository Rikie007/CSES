/*
 * Problem Name: Mountain_Range
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
vector<vector<int>> arr;
 
void solve() {
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back({x, i});
    }
 
    vector<int> ng(n);
    stack<int> st;
 
    ng[n - 1] = -1;
    st.push(n - 1);
 
    for (int i = n - 2; i >= 0; i--) {
 
        if (arr[st.top()][0] > arr[i][0]) {
            ng[i] = st.top();
            st.push(i);
        }
        else {
            while (!st.empty() && arr[st.top()][0] < arr[i][0]) {
                st.pop();
            }
 
            if (st.empty()) {
                ng[i] = -1;
                st.push(i);
            }
            else {
                ng[i] = st.top();
                st.push(i);
            }
        }
    }
 
    vector<int> pg(n);
 
    // Clear stack
    while (!st.empty()) {
        st.pop();
    }
 
    pg[0] = -1;
    st.push(0);
 
    for (int i = 1; i < n; i++) {
 
        if (arr[st.top()][0] > arr[i][0]) {
            pg[i] = st.top();
            st.push(i);
        }
        else {
            while (!st.empty() && arr[st.top()][0] < arr[i][0]) {
                st.pop();
            }
 
            if (st.empty()) {
                pg[i] = -1;
                st.push(i);
            }
            else {
                pg[i] = st.top();
                st.push(i);
            }
        }
    }
 
    sort(arr.begin(), arr.end());
 
    vector<int> ans(n, 0);
 
    ans[arr[n - 1][1]] = 1;
 
    for (int i = n - 1; i >= 0; i--) {
 
        int originalIndex = arr[i][1];
 
        int ngei = ng[originalIndex];
        int pgei = pg[originalIndex];
 
        int tmp = 0;
 
        if (ngei != -1) {
            tmp = ans[ngei];
        }
 
        if (pgei != -1) {
            tmp = max(tmp, ans[pgei]);
        }
 
        tmp++;
 
        ans[originalIndex] = tmp;
    }
 
    cout << *max_element(ans.begin(), ans.end()) << '\n';
}
 
int main(){
 
    Code By Rikie
 
        solve();
 
    return 0;
}