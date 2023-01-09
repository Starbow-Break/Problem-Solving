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

const int INF = 1e9;

int N, K;
bool used[101] = {false, }; int cnt  = 0;
queue<int> q[101];
vector<int> seq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    for(int i = 1; i <= K; i++) {
        int v; cin >> v;
        seq.push_back(v);
        q[v].push(i);
    }
    for(int i = 1; i <= K; i++) {
        q[i].push(INF);
    }
    
    int ans = 0;
    for(int i = 0; i < K; i++) {
        int cur = seq[i];
        q[cur].pop();
        
        if(used[cur]) continue;
        
        if(cnt < N) {
            used[cur] = true; cnt++;
        }
        else {
            int off = -1;
            for(int j = 1; j <= K; j++) {
                if(j == cur) continue;
                
                if(used[j]) {
                    if(off == -1) off = j;
                    else {
                        if(q[off].front() < q[j].front()) off = j;
                    }
                }
            }
            
            used[off] = false; ans++;
            used[cur] = true;
        }
    }
    
    cout << ans;

    return 0;
}