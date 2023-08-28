#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

using pii = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

vector<int> words;
vector<int> values;

int temp = 0;
void getValues(int n, int k, int step = 0, int start = 0) {
	if (step == k) {
		values.push_back(temp);
		return;
	}
	
	if (start >= 26) return;

	for (int i = start; i < 26; i++) {
		temp |= 1 << i;
		getValues(n, k, step + 1, i + 1);
		temp ^= 1 << i;
	}
}

int main() {
	int N, K; cin >> N >> K;
	while (N--) {
		string s; cin >> s;
		int value = 0;
		for (auto &c : s) {
			value |= 1 << (c - 'a');
		}
		words.push_back(value);
	}

	getValues(26, K);

	int ans = 0;
	for (auto &v : values) {
		int cur = 0;
		for (auto &w : words) {
			cur += ((w & v) == w);
		}
		ans = max(ans, cur);
	}

	cout << ans;

	return 0;
}