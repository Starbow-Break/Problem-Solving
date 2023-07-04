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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> music, dream;
    int N, M; cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        music.push_back(v);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int v; cin >> v;
        dream.push_back(v);
    }
    
    int minV = 10000, maxV = -1;
    for(int i = 0; (N-1)*(i+1)+1 <= M; i++) {
        bool check = false;
        for(int j = 0; j < M; j++) {
            if(dream[j] == music[0]) {
                int idx = 0;
                while(idx < N) {
                    if(j+(i+1)*idx >= M) break;
                    if(dream[j+(i+1)*idx] != music[idx]) break;
                    idx++;
                }
                if(idx == N) {
                    minV = min(minV, i);
                    maxV = max(maxV, i);
                }
            }
        }
    }
    
    if(maxV == -1) cout << -1;
    else cout << minV << ' ' << maxV;

    return 0;
}