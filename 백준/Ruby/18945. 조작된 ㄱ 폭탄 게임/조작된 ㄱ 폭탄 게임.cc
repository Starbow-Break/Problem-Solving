#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const ll BASE = 1LL << 40;

ll segTree[1 << 16] = {0, };

void update(int l, int r, int idx, int t, ll v) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] = v;
        return;
    }
    
    int mid = l+r>>1;
    update(l, mid, idx<<1, t, v);
    update(mid+1, r, idx<<1|1, t, v);
    segTree[idx] = segTree[idx<<1]+segTree[idx<<1|1];
}

void update(int l, int r, int idx, int t) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] *= -1;
        return;
    }
    
    int mid = l+r>>1;
    update(l, mid, idx<<1, t);
    update(mid+1, r, idx<<1|1, t);
    segTree[idx] = segTree[idx<<1]+segTree[idx<<1|1];
}

ll query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = l+r>>1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, idx<<1|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    char game[40][41];
    for(int i = 1; i <= N; i++) {
        int R, C; cin >> R >> C;
        for(int r = 0; r < R; r++) cin >> game[r];
        
        ll cur = 0;
        int sumA[40][40] = {0, };
        int sumB[40][40] = {0, };
        
        // 폭탄 누적합 구하기
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if(game[r][c] == 'A') sumA[r][c]++;
                if(game[r][c] == 'B') sumB[r][c]++;
            }
        }
        
        for(int r = 0; r < R; r++) {
            for(int c = 1; c < C; c++) {
                sumA[r][c] += sumA[r][c-1];
                sumB[r][c] += sumB[r][c-1];
            }
        }
            
        for(int c = 0; c < C; c++) {
            for(int r = R-2; r >= 0; r--) {
                sumA[r][c] += sumA[r+1][c];
                sumB[r][c] += sumB[r+1][c];
            }
        }
        
        // 게임판에 해당하는 값 구하기
        if(!sumA[0][C-1]) cur = -BASE*sumB[0][C-1];
        else if(!sumB[0][C-1]) cur = BASE*sumA[0][C-1];
        else {
            //A가 1개있는 경우
            if(sumA[0][C-1] == 1) {
                for(int r = 0; r < R; r++) {
                    for(int c = 0; c < C; c++) {
                        if(game[r][c] == 'A') {
                            cur += -BASE/(1LL << sumB[r][c]);
                            
                            bool check = false;
                            for(int rr = r; rr >= 0; rr--) {
                                for(int cc = c; cc < C; cc++) {
                                    if(game[rr][cc] == 'B' && sumB[rr][cc] == 1+sumB[r][c]) {
                                        check = true;
                                    }
                                }
                            }
                            
                            if(check) cur /= 2;
                            
                            cur += BASE*(sumB[0][C-1]-sumB[r][c]);
                        }
                    }
                }
                cur *= -1;
            }
            //B가 1개있는 경우
            else {
                for(int r = 0; r < R; r++) {
                    for(int c = 0; c < C; c++) {
                        if(game[r][c] == 'B') {
                            cur += -BASE/(1LL << sumA[r][c]);
                            
                            bool check = false;
                            for(int rr = r; rr >= 0; rr--) {
                                for(int cc = c; cc < C; cc++) {
                                    if(game[rr][cc] == 'A' && sumA[rr][cc] == 1+sumA[r][c]) {
                                        check = true;
                                    }
                                }
                            }
                            
                            if(check) cur /= 2;
                            
                            cur += BASE*(sumA[0][C-1]-sumA[r][c]);
                        }
                    }
                }
            }
        }
        
        //cout << (double)cur/BASE << '\n';
        update(1, N, 1, i, cur);
    }
    
    int Q; cin >> Q;
    while(Q--) {
        int K, U, V; cin >> K >> U >> V;
        update(1, N, 1, K);
        ll result = query(1, N, 1, U, V);
        
        // for(int i = 1; i <= N; i++) {
        //     cout << query(1, N, 1, i, i) << ' ';
        // }
        // cout << '\n';
        
        cout << (result > 0 ? "Ahgus" : "Bagus") << '\n';
    }
    
    return 0;
}