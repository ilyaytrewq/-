/*
-Werror
g++ solution.cpp -o solution.exe -D_GLIBCXX_DEBUG -Wall -Wextra -Wshadow
clang++ solution.cpp -o solution.exe -fsanitize=undefined -fsanitize=address -g -g3 -Wall -Wextra -Wshadow -Werror
*/
/*
TIMER
auto start = chrono::high_resolution_clock::now();
auto cur = chrono::high_resolution_clock::now();
if (chrono::duration_cast<chrono::milliseconds>(cur - start).count() > 1950) {
    break;
}
*/

//#pragma GCC optimize("Ofast")//O3
//#pragma GCC target("avx2")﻿

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <chrono>

using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;
//using BigInt = __int128_t;
//#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int cnt = 1;
    do {
        for (int i = 0; i < n; ++i) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(p.begin(), p.end()));

}

/*
2 4
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
*/

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(40);

    int tt = 1;
    //cin >> tt;

    for (int _ = 0; _ < tt; ++_) {
        solve();
    }

}
