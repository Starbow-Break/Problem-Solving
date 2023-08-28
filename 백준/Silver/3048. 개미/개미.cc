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
	int N1, N2; cin >> N1 >> N2;
	string s1, s2; cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	string t = s1 + s2;
	vector<int> d;
	for (int i = 0; i < N1; i++) d.push_back(0);
	for (int i = 0; i < N2; i++) d.push_back(1);
	
	int T; cin >> T;
	while (T--) {
		int i = 0;
		while (i < N1 + N2) {
			if (i+1 < N1+N2 && !d[i] && d[i + 1]) {
				swap(d[i], d[i+1]);
				swap(t[i], t[i+1]);
				i += 2;
			}
			else {
				i++;
			}
		}
	}

	cout << t;

	return 0;
}