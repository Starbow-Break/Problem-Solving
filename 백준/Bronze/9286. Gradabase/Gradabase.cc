#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cout << "Case " << tc << ':' << '\n';
        int N; cin >> N;
        while(N--) {
            int v; cin >> v;
            if(v < 6) cout << v+1 << '\n';
        }
    }

    return 0;
}