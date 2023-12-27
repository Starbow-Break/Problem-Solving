#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
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

// 나무
struct tree {
    int x, y, length;
};

vector<tree> trees; // 나무 목록

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y, length; cin >> x >> y >> length;
        trees.pb({x, y, length});
    }
    
    // 데이터 가공
    vector<int> data_x, data_y;
    
    for(int i = 0; i < N; i++) {
        data_x.pb(trees[i].x);
        data_y.pb(trees[i].y);
    }
    
    sort(all(data_x)); sort(all(data_y));
    
    int ans = N;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            for(int a = 0; a < N; a++) {
                for(int b = a; b < N; b++) {
                    vector<bool> isSurvived(N);
                    int cur = N;
                    
                    for(int idx = 0; idx < N; idx++) {
                        if(
                            data_x[i] <= trees[idx].x && trees[idx].x <= data_x[j]
                            && data_y[a] <= trees[idx].y && trees[idx].y <= data_y[b]
                        ) {
                            isSurvived[idx] = true;
                            cur--;
                        }
                    }
                    
                    int minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
                    int fence = 0;
                    for(int idx = 0; idx < N; idx++) {
                        if(isSurvived[idx]) {
                            minX = min(minX, trees[idx].x);
                            maxX = max(maxX, trees[idx].x);
                            minY = min(minY, trees[idx].y);
                            maxY = max(maxY, trees[idx].y);
                        }
                        else {
                            fence += trees[idx].length;
                        }
                    }
                    
                    if(minX == data_x[i] && maxX == data_x[j] && minY == data_y[a] && maxY == data_y[b]) {
                        if(fence >= 2*(maxX-minX+maxY-minY)) {
                            //cout << minX << ' ' << maxX << ' ' << minY << ' ' << maxY << ' ' << cur << '\n';
                            ans = min(ans, cur);
                        }
                        else {
                            vector<int> can_cut;
                            for(int idx = 0; idx < N; idx++) {
                                if(minX < trees[idx].x && trees[idx].x < maxX && minY < trees[idx].y && trees[idx].y < maxY) {
                                    can_cut.pb(trees[idx].length);
                                }
                            }
                            
                            sort(rall(can_cut));
                            int q = 0;
                            while(q <= can_cut.size()) {
                                if(fence >= 2*(maxX-minX+maxY-minY)) {
                                    ans = min(ans, cur);
                                    break;
                                }
                                
                                if(q == can_cut.size()) break;
                                
                                cur++;
                                fence += can_cut[q];
                                q++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
