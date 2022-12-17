#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, L;
vector<int> holes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L;
    while(N--) {
        int v; cin >> v;
        holes.push_back(v);
    }
    
    sort(holes.begin(), holes.end());
    
    int idx = 0; int ans = 0;
    while(idx < holes.size()) {
        ans++;
        int e = holes[idx]+L-1;
        while(idx < holes.size() && holes[idx] <= e) { idx++; }
    }
    
    cout << ans;

    return 0;
}