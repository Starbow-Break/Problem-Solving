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

int N, M;
char arr[20][21];

vector<pii> village, space;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(arr[r][c] == '0')
                space.push_back({r, c});
            else
                village.push_back({r, c});
        }
    }
    
    int ans = 1'000'000;
    for(int i = 0; i < space.size(); i++) {
        for(int j = i+1; j < space.size(); j++) {
            int cur = 0;
            for(auto &v: village) {
                cur = max(cur, min(abs(v.first-space[i].first)+abs(v.second-space[i].second),
                abs(v.first-space[j].first)+abs(v.second-space[j].second)));
            }
            ans = min(ans, cur);
        }
    }
    
    cout << ans;

    return 0;
}