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
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int arr[N+1]; bool visited[N+1] = {false, };
        for(int i = 1; i <= N; i++) { cin >> arr[i]; }
        
        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                cnt++; int cur = i;
                while(1) {
                    if(visited[cur]) break;
                    
                    visited[cur] = true;
                    cur = arr[cur];
                }
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}