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
 
void mobile_game(long long N, long long A, long long B, vector<long long> enemies) {
    vector<bool> has_killed(N, false);
    long long A_now = A; 
    int n_killed = 0;
    sort(enemies.begin(), enemies.end(), greater<long long>());
    
    while(A_now < B) {
        bool can_kill = false;
        for (int i = 0; i < N; i++) {
            if ((enemies[i] < A_now) && (A_now < B) && (!has_killed[i])) {
                has_killed[i] = true;
                can_kill = true;
                A_now += enemies[i];
                n_killed += 1;
                break;
            }
        }

        if (!can_kill) {
            break;
        }
    }

    if (A_now < B) {
        cout << "-1" << "\n";
    } else {
        cout << n_killed << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        long long N, A, B; cin >> N >> A >> B;
        vector<long long> enemies;
        for (int j = 0; j < N; j++) {
            long long elevel; cin >> elevel;
            enemies.push_back(elevel);
        }
        mobile_game(N, A, B, enemies); 
    }
    return 0;
}