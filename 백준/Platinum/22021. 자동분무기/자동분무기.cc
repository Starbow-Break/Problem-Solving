#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<vector<int>> vec(8, vector<int>(8));
    
    int M; cin >> M;
    FOR(r, 0, 8) {
        FOR(c, 0, 8) {
            cin >> vec[r][c];
            vec[r][c] -= M;
        }
    }
    
    int ans[8][8];
    int deltaSum = 0;
    int deltaRow[8], deltaCol[8];
    
    FOR(r, 0, 8) { FOR(c, 0, 8) { deltaSum += vec[r][c]; } }
    deltaSum /= 15;
    
    FOR(r, 0, 8) {
        int curDelta = 0;
        FOR(c, 1, 8) {
            curDelta += vec[r][c];
        }
        curDelta -= (deltaSum - vec[r][0]);
        curDelta /= 7;
        
        deltaRow[r] = curDelta;
    }
    
    FOR(c, 0, 8) {
        int curDelta = 0;
        FOR(r, 1, 8) {
            curDelta += vec[r][c];
        }
        curDelta -= (deltaSum - vec[0][c]);
        curDelta /= 7;
        
        deltaCol[c] = curDelta;
    }
    
    FOR(r, 0, 8) {
        FOR(c, 0, 8) {
            ans[r][c] = deltaSum;
            FOR(rr, 0, 8) {
                if(rr == r) continue;
                ans[r][c] -= deltaRow[rr];
            }
            FOR(cc, 0, 8) {
                if(cc == c) continue;
                ans[r][c] -= deltaCol[cc];
            }
            ans[r][c] += (deltaSum - vec[r][c]);
        }
    }
    
    FOR(r, 0, 8) {
        FOR(c, 0, 8) {
            if(ans[r][c]) cout << (ans[r][c] > 0 ? '+' : '-');
            else cout << '.';
            cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}