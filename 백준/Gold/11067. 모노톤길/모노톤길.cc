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

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<pii> cafe;
		cafe.push_back({ -1, 0 });
		for (int i = 0; i < N; i++) {
			int x, y; cin >> x >> y;
			cafe.push_back({ x, y });
		}
		sort(cafe.begin(), cafe.end());

		int i = 1, j = 1;
		while (j <= N) {
			while (j <= N && cafe[j].first == cafe[i].first) {
				j++;
			}
			if (cafe[i - 1].second != cafe[i].second) {
				reverse(cafe.begin() + i, cafe.begin() + j);
			}
			i = j;
		}

		int M; cin >> M;
		while (M--) {
			int v; cin >> v;
			cout << cafe[v].first << ' ' << cafe[v].second << '\n';
		}
	}

	return 0;
}