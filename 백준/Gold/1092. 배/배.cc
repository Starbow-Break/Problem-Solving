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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
int crane[51], box[10001];
int idx[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N; crane[0] = 0;
    for(int i = 1; i <= N; i++) { cin >> crane[i]; }
    cin >> M; box[0] = 0;
    for(int i = 1; i <= M; i++) { cin >> box[i]; }
    sort(crane+1, crane+N+1); sort(box+1, box+M+1);
    
    int t = 0;
    for(int i = 1; i <= N; i++) {
        while(t <= M) {
            if(box[t+1] > crane[i]) break;
            
            t++;
        }
        
        idx[i] = t;
    }
    
    if(idx[N] < M) cout << -1;
    else {
        int ans = 0; int remain = M;
        while(remain > 0) {
            ans++;
            for(int i = N; i >= 1; i--) {
                while(idx[i] > 0 && box[idx[i]] == 0) { idx[i]--; }
                if(idx[i] > 0) {
                    box[idx[i]] = 0; remain--;
                }
            }
        }
        
        cout << ans;
    }

    return 0;
}
