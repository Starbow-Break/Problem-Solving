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
    
    int N, M; cin >> N >> M;
    
    int ans = 0;
    while(M > 0) {
        N %= M;
        if(N == 0) break;
        
        if(M%N) { ans += (M/N)*N; }
        else { ans += (M/N-1)*N; }
        
        M %= N;
    }
    
    cout << ans;

    return 0;
}