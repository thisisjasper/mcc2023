#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<set>
#include<stack>
#include<string>

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<limits>

#define MODNUM 998244353

using namespace std;

template <typename T>
T ipow(T x, unsigned int n) { T r = 1; for(;;) { if (n & 1) { r *= x; } n >>= 1; if (!n) { break; } x *= x; } return r; }

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<long long> > cards(n);
    for (int i = 0 ; i < n; i++) {
        vector<long long> card(4);
        int a, b, c, d; cin >> a >> b >> c >> d;
        card[0] = a;
        card[1] = b;
        card[2] = c;
        card[3] = d;
        cards[i] = card;
    }

    sort(cards.begin(), cards.end(), [](vector<long long> &a, vector<long long> &b) { 
        return a[0] + a[1] > b[0] + b[1]; 
    });

    long long max_sum = 0;
    for (int i = 0; i < n; i++) {
        long long sum = cards[i][0] + cards[i][1] + cards[i][2] + cards[i][3];
        int cards_added = 1;

        int curr_index = 0;
        while (cards_added < m) {
            if (curr_index != i) {
                cards_added += 1;
                sum += cards[curr_index][0] + cards[curr_index][1];
            }
            curr_index += 1;
        }
        max_sum = max(max_sum, sum);
    }
    cout << max_sum << "\n";
}