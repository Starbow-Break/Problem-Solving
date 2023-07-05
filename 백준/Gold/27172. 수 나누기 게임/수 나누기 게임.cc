#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

bool used[1'000'001] = {false, };
vector<int> cards;
int score[1'000'001] = {0, };

void solve() {
    for(int i = 1; i <= 1'000'000; i++) {
        if(used[i]) {
            for(int j = i*2; j <= 1'000'000; j += i) {
                if(used[j]) { score[j]--; score[i]++; }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        cards.push_back(v);
        used[v] = true;
    }
    
    solve();
    
    for(auto &v: cards) {
        cout << score[v] << ' ';
    }

    return 0;
}