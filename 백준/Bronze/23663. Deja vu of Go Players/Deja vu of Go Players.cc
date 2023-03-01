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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        cout << (N <= M ? "Yes" : "No") << '\n';
        
        int v;
        for(int i = 1; i <= N; i++) cin >> v;
        for(int i = 1; i <= M; i++) cin >> v;
    }

    return 0;
}