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
    
    int nA, nB; cin >> nA >> nB;
    
    int ans = nA/2+nB/2;
    if(nA%2 && nB%2) {
        int M; cin >> M;
        while(M--) {
            int u, v; cin >> u >> v;
            if(u%2 && v%2) {
                ans++; break;
            }
        }
    }
    
    cout << ans;

    return 0;
}