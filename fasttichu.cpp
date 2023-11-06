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
    //freopen("output.txt", "w", stdout);
    
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
    long long max_length = 1 + k;

    for (int l = 1; l <= proc_nums.size(); l++) {
        int start = 0;
        int end = l-1;
        int gaps = 0;
        for (int i = 0; i < end; i++) {
            gaps += proc_nums[i+1] - proc_nums[i] - 1;
        }

        if (gaps <= k) {
            max_length = max(max_length, proc_nums[end]-proc_nums[start]+1+k-gaps);
        }
        while(end < proc_nums.size()-1) {
            start++;
            end++;
            gaps += proc_nums[end] - proc_nums[end-1]-1 - (proc_nums[start] - proc_nums[start-1]-1);
            if (gaps <= k) {
                max_length = max(max_length, proc_nums[end]-proc_nums[start]+1+k-gaps);
            }   
        }
    }
    cout << max_length << "\n";
}