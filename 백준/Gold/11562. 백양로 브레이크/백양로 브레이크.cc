#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;
int d[251][251];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 1; i <= 250; i++) { fill(d[i], d[i]+251, INF); d[i][i] = 0; }
    
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = 0; d[b][a] = 1-c;
    }
    
    for(int k = 1; k <= N; k++) {
        for(int a = 1; a <= N; a++) {
            for(int b = 1; b <= N; b++) {
                d[a][b] = min(d[a][b], d[a][k]+d[k][b]);
            }
        }
    }
    
    int Q; cin >> Q;
    while(Q--) {
        int a, b; cin >> a >> b;
        cout << d[a][b] << '\n';
    }
    
    return 0;
}