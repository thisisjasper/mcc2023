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

long long tichu(int k, long long l, long long r, vector<long long> proc_nums) {
    int gaps = 0;
    for (int i = l; i < r ; i++) {
        gaps += proc_nums[i+1] - proc_nums[i] - 1;
    }
    if (gaps > k) {
        return -1;
    } else {
        return proc_nums[r]-proc_nums[l]+1+k-gaps;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k; cin >> n >> k;
    vector<long long> nums(n-k);
    vector<long long> proc_nums(1, 0);
    for (int i = 0; i < n-k; i++) {
        int a; cin >> a;
        nums[i] = a;
    }
    sort(nums.begin(), nums.end());
    proc_nums[0] = nums[0];

    for (int i = 1; i < n-k; i++) {
        if (!(nums[i] == proc_nums[proc_nums.size()-1])) {
            proc_nums.push_back(nums[i]);
        }
    }
    
    // begin

    long long max_length = 0;

    for (int i = 0; i < proc_nums.size(); i++) {
        for (int j = i; j < proc_nums.size(); j++) {
            max_length = max(tichu(k, i, j, proc_nums), max_length);
        }
    }

    for (auto i : proc_nums) {
        cout << i << " ";
    }
    cout << "\n";
    cout << max_length << "\n";
}