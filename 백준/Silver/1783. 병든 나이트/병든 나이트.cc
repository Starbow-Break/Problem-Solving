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
    
    int N, M; cin >> N >> M;
    if(N == 1) {
        cout << 1;
    }
    else if(N == 2) {
        cout << min(4, (M-1)/2+1);
    }
    else {
        if(M < 7) cout << min(4, M);
        else cout << M-2;
    }

    return 0;
}