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

int N, M; int bound = 0;
vector<int> marble;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        marble.push_back(v);
        bound = max(bound, v);
    }
    
    int ans; int len[301] = {0, };
    for(int i = 100*N; i >= bound; i--) {
        if(i == bound) {
            ans = bound; break;
        }
        
        int cnt = 1; int cur = 0;
        int curLen[301] = {0, };
        for(int j = 0; j < N; j++) {
            if(cur+marble[j] > i) {
                cnt++; cur = marble[j];
                curLen[cnt] = 1;
            }
            else {
                cur += marble[j];
                curLen[cnt]++;
            }
        }
        
        if(cnt > M) {
            ans = i+1; break;
        }
        
        for(int j = 1; j <= cnt; j++) {
            len[j] = curLen[j];
        }
    }
    
    cout << ans << '\n';
    for(int i = M; i >= 1; i--) {
        if(len[i] > 0) break;
        while(len[i] <= 0) {
            len[i-1]--; len[i]++;
        }
    }
    for(int i = 1; i <= M; i++) { cout << len[i] << " "; }

    return 0;
}