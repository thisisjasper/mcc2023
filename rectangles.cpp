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

long long find_minimum_area(int N, int K, vector<pair<long long, long long> > &rects, vector<vector<long long> > &memoi) { // n - # red rects covered, k - # blue rects placed
    if (memoi[N][K] != numeric_limits<long long>::max()) {
        return memoi[N][K];
    }
    if (K == 1) { // base case
        long long width_sum = 0;
        long long max_height = 0;

        for (int i = 0; i < N; i++) {
            max_height = max(max_height, rects[i].first);
            width_sum += rects[i].second;
        }
        memoi[N][K] = max_height * width_sum;

        return memoi[N][K];
    }

    // K > 1

    for (int i = 1; i <= N-K; i++) {
        long long left_minimum = find_minimum_area(N-i, K-1, rects, memoi);
        
        long long right_minimum = 0;
        long long width_sum = 0;
        long long max_height = 0;
        for (int j = N-i; j < N; j++) {
            max_height = max(max_height, rects[j].first);
            width_sum += rects[j].second;
        }
        right_minimum = width_sum * max_height;
        memoi[N][K] = min(memoi[N][K], left_minimum + right_minimum);
    }

    return memoi[N][K];
}

int main() { 
    freopen("input.txt", "r", stdin);
    
    int N, K; cin >> N >> K;
    vector<pair<long long, long long> > rects(N);
    vector<vector<long long> > memoi(N+1, vector<long long>(K+1, numeric_limits<long long>::max()));

    for (int i = 0; i < N; i++) {
        long long a, b; cin >> a >> b;
        rects[i] = make_pair(a, b);
    }

    cout << find_minimum_area(N, K, rects, memoi) << "\n";
}