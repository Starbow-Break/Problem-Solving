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

int ans[1000001];
bool check(int N) {
    bool isUsed[N+1] = {false, };
    for(int i = 1; i <= N; i++) {
        if(isUsed[ans[i]]) return false;
        isUsed[ans[i]] = true;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) { ans[i] = i; }
    
    while(M--) {
        int x, y; cin >> x >> y;
        ans[x]++; ans[y]--;
    }
    
    if(check(N)) {
        for(int i = 1; i <= N; i++) { cout << ans[i] << " ";}
    }
    else cout << -1;

    return 0;
}