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
    
    int K, C; cin >> K >> C;
    while(C--) {
        int M, N; cin >> M >> N;
        if(M > N) {
            int t = K-M; t++;
            cout << (N+t >= M-1);
        }
        else if(M < N) {
            int t = K-N;
            cout << (M+t >= N-1);
        }
        else cout << 1;
        
        cout << '\n';
    }

    return 0;
}