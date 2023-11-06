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

int ipow_mod(int b, int e, int m)
{
	int result = e & 1 ? b : 1;
	while (e) {
		e >>= 1;
		b = (b * b) % m;
		if (e & 1)
			result = (result * b) % m;
	}
	return result;
}

long long total_sum = 0;

void subsets(int N, int K, int I, vector<long long> &nums, vector<long long> &chosen) {
    if (I == N) {
        cout << total_sum << "\n";
        long long this_sum = 0;
        for (auto i : chosen) {
            this_sum += i % MODNUM;
        }
        total_sum += ipow_mod(this_sum, K, MODNUM);
        total_sum = total_sum % MODNUM;
        return;
    }

    subsets(N, K, I+1, nums, chosen);
    chosen.push_back(nums[I]);
    subsets(N, K, I+1, nums, chosen);
    chosen.pop_back();
}

int main() { 
    freopen("input.txt", "r", stdin);
    
    int N, K; cin >> N >> K;
    vector<long long> nums(N);
    vector<long long> chosen;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    subsets(N, K, 0, nums, chosen);
    cout << total_sum << "\n";
}