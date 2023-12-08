#include <bits/stdc++.h>

using namespace std;

using ll = long long; // это нужно чтобы не писать long long

int main() {
    size_t n;
    cin >> n;
    if (n == 1) {
        cout << 2 << '\n';
        return 0;
    }
    vector<vector<ll> > dp(4, vector<ll>(n)); 
    // мы создали dp состоящее из 4 элементов.
    // каждый элемент равен vector<ll>(n)
    // где каждый vector<ll>(n) массив длинны n

    // dp[0] это если последовательность заканчивается на 00
    // dp[1] это если последовательность заканчивается на 10
    // dp[2] это если последовательность заканчивается на 01
    // dp[3] это если последовательность заканчивается на 11
    

    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;
    
    for (size_t i = 2; i < n; ++ i) {
        // переход динамики
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[2][i - 1] + dp[3][i - 1];
        dp[2][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[3][i] = dp[2][i - 1];
    }
    ll out = 0;
    for (size_t i = 0; i < 4; ++ i) {
        out += dp[i].back();
    }
    cout << out << '\n';
}
