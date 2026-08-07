/*
 * Problem Name: Coin_Combinations_II
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-08-07
 */

input/code.cpp: In function 'long long int sol(int, int)':
input/code.cpp:12:12: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   12 |     if(idx >=  arr.size()) return 0;
      |        ~~~~^~~~~~~~~~~~~~
input/code.cpp:21:24: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   21 |     for(int i = idx; i < arr.size(); i++){
      |                      ~~^~~~~~~~~~~~