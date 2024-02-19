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

// 차원 압축 된 배열에서 원래 배열을 얻을 시 사용할 값
// 순서대로 m, n, o, p, q, r, s, t, u, v, w축과 관련
int delta[11];

// 각 축의 길이
// 순서대로 m, n, o, p, q, r, s, t, u, v, w축과 관련
int len[11];

// 11차원 하이퍼ㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓ 배열
// 차원 압축되어 있음
ll A[111'111];

// Type 1 : 10차원 초공간에 대해 대칭
void opType1(
    int op, int m1, int n1, int o1, int p1, int q1, 
    int r1, int s1, int t1, int u1, int v1, int w1,
    int m2, int n2, int o2, int p2, int q2, int r2,
    int s2, int t2, int u2, int v2, int w2
) {
    // 요소가 움직이는 방향의 축 구하기
    int ax = op-1;
    vector<pii>_ranges, ranges; vector<int> deltas;
    _ranges.pb({m1, m2}); _ranges.pb({n1, n2}); _ranges.pb({o1, o2});
    _ranges.pb({p1, p2}); _ranges.pb({q1, q2}); _ranges.pb({r1, r2});
    _ranges.pb({s1, s2}); _ranges.pb({t1, t2}); _ranges.pb({u1, u2});
    _ranges.pb({v1, v2}); _ranges.pb({w1, w2});
    
    for(int i = 0; i < 11; i++) {
        if(i == ax) continue;
        ranges.pb(_ranges[i]);
        deltas.pb(delta[i]);
    }
    
    // 대애ㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐ칭
    for(int a = ranges[0].fi; a <= ranges[0].se; a++) {
        for(int b = ranges[1].fi; b <= ranges[1].se; b++) {
            for(int c = ranges[2].fi; c <= ranges[2].se; c++) {
                for(int d = ranges[3].fi; d <= ranges[3].se; d++) {
                    for(int e = ranges[4].fi; e <= ranges[4].se; e++) {
                        for(int f = ranges[5].fi; f <= ranges[5].se; f++) {
                            for(int g = ranges[6].fi; g <= ranges[6].se; g++) {
                                for(int h = ranges[7].fi; h <= ranges[7].se; h++) {
                                    for(int i = ranges[8].fi; i <= ranges[8].se; i++) {
                                        for(int j = ranges[9].fi; j <= ranges[9].se; j++) {
                                            for(int x = _ranges[ax].fi; x <= (_ranges[ax].fi+_ranges[ax].se)/2; x++) {
                                                int idx1 = a*deltas[0]+b*deltas[1]+c*deltas[2]+d*deltas[3]+e*deltas[4]+f*deltas[5]
                                                    +g*deltas[6]+h*deltas[7]+i*deltas[8]+j*deltas[9]+x*delta[ax];
                                                int idx2 = a*deltas[0]+b*deltas[1]+c*deltas[2]+d*deltas[3]+e*deltas[4]+f*deltas[5]
                                                    +g*deltas[6]+h*deltas[7]+i*deltas[8]+j*deltas[9]+(_ranges[ax].fi+_ranges[ax].se-x)*delta[ax];
                                                swap(A[idx1], A[idx2]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// Type 2 : 특정 평면을 기준으로 반시계 방향으로 이동
void opType2(
    int op, int m1, int n1, int o1, int p1, int q1, 
    int r1, int s1, int t1, int u1, int v1, int w1,
    int m2, int n2, int o2, int p2, int q2, int r2,
    int s2, int t2, int u2, int v2, int w2
) {
    // 회전의 기준이 되는 평면이 포함하는 두 축 구하기
    int ax1 = 0, ax2;
    
    // swap 되는 두 축 구하기
    int temp = op-12;
    for(int i = 10; i >= 1; i--) {
        if(temp < i) {
            ax2 = ax1+temp+1;
            break;
        }
        temp -= i;
        ax1++;
    }
    
    vector<pii>_ranges, ranges; vector<int> deltas;
    _ranges.pb({m1, m2}); _ranges.pb({n1, n2}); _ranges.pb({o1, o2});
    _ranges.pb({p1, p2}); _ranges.pb({q1, q2}); _ranges.pb({r1, r2});
    _ranges.pb({s1, s2}); _ranges.pb({t1, t2}); _ranges.pb({u1, u2});
    _ranges.pb({v1, v2}); _ranges.pb({w1, w2});
    
    for(int i = 0; i < 11; i++) {
        if(i == ax1 || i == ax2) continue;
        ranges.pb(_ranges[i]);
        deltas.pb(delta[i]);
    }
    
    // 회애ㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐㅐ전
    for(int a = ranges[0].fi; a <= ranges[0].se; a++) {
        for(int b = ranges[1].fi; b <= ranges[1].se; b++) {
            for(int c = ranges[2].fi; c <= ranges[2].se; c++) {
                for(int d = ranges[3].fi; d <= ranges[3].se; d++) {
                    for(int e = ranges[4].fi; e <= ranges[4].se; e++) {
                        for(int f = ranges[5].fi; f <= ranges[5].se; f++) {
                            for(int g = ranges[6].fi; g <= ranges[6].se; g++) {
                                for(int h = ranges[7].fi; h <= ranges[7].se; h++) {
                                    for(int i = ranges[8].fi; i <= ranges[8].se; i++) {
                                        int x = len[ax1], y = len[ax2];
                                        ll **temp = new ll*[y];
                                        for(int k = 0; k < y; k++) {
                                            temp[k] = new ll[x];
                                        }
                                        
                                        for(int k = 0;; k++) {
                                            int r1 = _ranges[ax2].fi+k, r2 = _ranges[ax2].se-k;
                                            int c1 = _ranges[ax1].fi+k, c2 = _ranges[ax1].se-k;                                            
                                            if(r1 > r2 || c1 > c2) break;
                                            for(int l = r1; l < r2; l++) {
                                                int idx = a*deltas[0]+b*deltas[1]+c*deltas[2]+d*deltas[3]+e*deltas[4]+f*deltas[5]
                                                    +g*deltas[6]+h*deltas[7]+i*deltas[8]+l*delta[ax2]+c1*delta[ax1];
                                                temp[l+1][c1] = A[idx];
                                            }
                                            for(int l = r1+1; l <= r2; l++) {
                                                int idx = a*deltas[0]+b*deltas[1]+c*deltas[2]+d*deltas[3]+e*deltas[4]+f*deltas[5]
                                                    +g*deltas[6]+h*deltas[7]+i*deltas[8]+l*delta[ax2]+c2*delta[ax1];
                                                temp[l-1][c2] = A[idx];
                                            }
                                            for(int l = c1; l < c2; l++) {
                                                int idx = a*deltas[0]+b*deltas[1]+c*deltas[2]+d*deltas[3]+e*deltas[4]+f*deltas[5]
                                                    +g*deltas[6]+h*deltas[7]+i*deltas[8]+r2*delta[ax2]+l*delta[ax1];
                                                temp[r2][l+1] = A[idx];
                                            }
                                            for(int l = c1+1; l <= c2; l++) {
                                                int idx = a*deltas[0]+b*deltas[1]+c*deltas[2]+d*deltas[3]+e*deltas[4]+f*deltas[5]
                                                    +g*deltas[6]+h*deltas[7]+i*deltas[8]+r1*delta[ax2]+l*delta[ax1];
                                                temp[r1][l-1] = A[idx];
                                            }
                                        }
                                        
                                        // for(int k = _ranges[ax2].fi; k <= _ranges[ax2].se; k++) {
                                        //     for(int l = _ranges[ax1].fi; l <= _ranges[ax1].se; l++) {
                                        //         cout << temp[k][l] << ' ';
                                        //     }
                                        //     cout << '\n';
                                        // }
                                        
                                        for(int k = _ranges[ax2].fi; k <= _ranges[ax2].se; k++) {
                                            for(int l = _ranges[ax1].fi; l <= _ranges[ax1].se; l++) {
                                                int idx = a*deltas[0]+b*deltas[1]+c*deltas[2]+d*deltas[3]+e*deltas[4]+f*deltas[5]
                                                    +g*deltas[6]+h*deltas[7]+i*deltas[8]+l*delta[ax1]+k*delta[ax2];
                                                A[idx] = temp[k][l];
                                            }
                                        }
                                        
                                        for(int k = 0; k < y; k++) {
                                            delete temp[k];
                                        }
                                        delete temp;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// Type 3: 특정 직선에 대해 대칭
void opType3(int op) {
    int ax1 = 0, ax2; // swap 될 축 두개
    
    // swap 되는 두 축 구하기
    int temp = op-67;
    for(int i = 10; i >= 1; i--) {
        if(temp < i) {
            ax2 = ax1+temp+1;
            break;
        }
        temp -= i;
        ax1++;
    }
    
    // 두 축을 swap
    swap(len[ax1], len[ax2]);
    swap(delta[ax1], delta[ax2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 하이퍼 배열 입력
    // 각 축의 길이 입력 및 배열 전체 크기 구하기
    int temp = 1;
    for(int i = 0; i < 11; i++) {
        cin >> len[i]; temp *= len[i];
    }
    
    // 하이퍼 배열 받기
    for(int i = 0; i < temp; i++) cin >> A[i];
    
    // delta 초기화
    for(int i = 0; i < 11; i++) {
        temp /= len[i]; delta[i] = temp;
    }
    
    // 연산 실시
    int rho; cin >> rho;
    while(rho--) {
        int op; cin >> op;
        // 1 ~ 66번 연산
        if(1 <= op && op <= 66) {
            int m1, n1, o1, p1, q1, r1, s1, t1, u1, v1, w1;
            int m2, n2, o2, p2, q2, r2, s2, t2, u2, v2, w2;
            cin >> m1 >> n1 >> o1 >> p1 >> q1 >> r1 >> s1 >> t1 >> u1 >> v1 >> w1;
            cin >> m2 >> n2 >> o2 >> p2 >> q2 >> r2 >> s2 >> t2 >> u2 >> v2 >> w2;
            
            // Type 1 : 10차원 초공간에 대해 대칭
            if(1 <= op && op <= 11) {
                opType1(
                    op, m1-1, n1-1, o1-1, p1-1, q1-1, r1-1, s1-1,
                    t1-1, u1-1, v1-1, w1-1,
                    m2-1, n2-1, o2-1, p2-1, q2-1, r2-1, s2-1, 
                    t2-1, u2-1, v2-1, w2-1
                );
            }
            // Type 2 : 특정 평면을 기준으로 반시계 방향으로 이동
            else {
                opType2(
                    op, m1-1, n1-1, o1-1, p1-1, q1-1, r1-1, s1-1,
                    t1-1, u1-1, v1-1, w1-1,
                    m2-1, n2-1, o2-1, p2-1, q2-1, r2-1, s2-1, 
                    t2-1, u2-1, v2-1, w2-1
                );
            }
        }
        // 67 ~ 121번 연산
        // Type 3: 특정 직선에 대해 대칭
        else {
            opType3(op);
        }
    }
    
    // 하이퍼 배열 출력
    for(int i = 0; i < 11; i++) {
        cout << len[i] << ' ';
    }
    cout << '\n';
    
    for(int m = 0; m < len[0]; m++) {
        for(int n = 0; n < len[1]; n++) {
            for(int o = 0; o < len[2]; o++) {
                for(int p = 0; p < len[3]; p++) {
                    for(int q = 0; q < len[4]; q++) {
                        for(int r = 0; r < len[5]; r++) {
                            for(int s = 0; s < len[6]; s++) {
                                for(int t = 0; t < len[7]; t++) {
                                    for(int u = 0; u < len[8]; u++) {
                                        for(int v = 0; v < len[9]; v++) {
                                            for(int w = 0; w < len[10]; w++) {
                                                int idx = m*delta[0]+n*delta[1]+o*delta[2]+p*delta[3]+q*delta[4]+r*delta[5]
                                                    +s*delta[6]+t*delta[7]+u*delta[8]+v*delta[9]+w*delta[10];
                                                cout << A[idx] << ' ';
                                            }
                                            cout << '\n';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}