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

int main() { 
    freopen("input.txt", "r", stdin);
    
    int N, K; cin >> N >> K;
    vector<long long> nums(N);
    vector<long long> chosen;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    //sort(nums.begin(), nums.end());

    long long sum_elements = 0;
    long long sum_squares = 0;

    for (int i = 0; i < N; i++) {
        sum_elements += nums[i] % MODNUM;
        sum_elements = sum_elements % MODNUM;
        sum_squares += (nums[i] * nums[i]) % MODNUM;
        sum_squares = sum_squares % MODNUM;
    }

    long long sum = 1;

    for (int i = 0; i < 3; i++) {
        sum = ((sum % MODNUM)* (sum_elements % MODNUM)) % MODNUM;
    }

    // for (int i = 0; i < N-1; i++) {
    //     sum *= 2;
    //     sum = sum % MODNUM;
    // }
    
    cout << sum << "\n";
}