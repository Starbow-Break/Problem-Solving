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
    
    int N; cin >> N;
    int ans[N+1];
    for(int i = 1; i <= N; i++) ans[i] = i;
    
    int M; cin >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        swap(ans[a], ans[b]);
    }
    
    for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
    
    return 0;
}