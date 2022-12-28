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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, W, H; cin >> N >> W >> H;
    while(N--) {
        int L; cin >> L;
        cout << ((L*L <= W*W+H*H) ? "DA" : "NE") << '\n';
    }

    return 0;
}