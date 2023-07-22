#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

//세그먼트 트리
struct segmentTree {
    ll sgTree[1<<12];
    ll lazy[1<<12];
    
    segmentTree() {
        fill(sgTree, sgTree+(1<<12), 0);
        fill(lazy, lazy+(1<<12), 0);
    }
    
    //노드 갱신
    void propagate(int s, int e, int idx) {
        if(s != e) {
            lazy[idx<<1] += lazy[idx];
            lazy[idx<<1|1] += lazy[idx];
        }
        sgTree[idx] += lazy[idx]*(e-s+1);
        lazy[idx] = 0;
    }
    
    //업데이트
    void update(int s, int e, int idx, int i, int j, int del) {
        propagate(s, e, idx);
        
        if(e < i || j < s) return;
        if(i <= s && e <= j) {
            lazy[idx] += del;
            propagate(s, e, idx);
            return;
        }
        
        int mid = s+e>>1;
        update(s, mid, idx<<1, i, j, del); update(mid+1, e, idx<<1|1, i, j, del);
        sgTree[idx] = sgTree[idx<<1]+sgTree[idx<<1|1];
    }
    
    //합 쿼리
    ll query(int s, int e, int idx, int i, int j) {
        propagate(s, e, idx);
        
        if(e < i || j < s) return 0;
        if(i <= s && e <= j) return sgTree[idx];
        
        int mid = s+e>>1;
        return query(s, mid, idx<<1, i, j)+query(mid+1, e, idx<<1|1, i, j);
    }
    
    //세그트리가 관리하는 요소들의 합계
    ll total() {
        return sgTree[1];
    }
}segTree[1501];

int arr[1501][1501] = {0, };
int dp[1501][1501] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])+arr[i][j];
        }
    }
    
    //dp에 맞춰 세그먼트 트리 최기화
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            segTree[i].update(0, N, 1, j, j, dp[i][j]);
        }
    }
    
    //처음 답 구하기
    ll firstAns = 0;
    for(int i = 1; i <= N; i++) {
        firstAns += segTree[i].total();
    }
    cout << firstAns << '\n';
    
    for(int i = 1; i <= N; i++) {
        char q; int r, c; cin >> q >> r >> c;
        if(q == 'U') {
            arr[r][c]++; //arr[r][c] 증가
            //갱신이 오른쪽, 아래로만 이루어지는것을 이용해 두포인터 사용
            //a : 왼쪽, b : 오른쪽, t : 현재행
            int a = c, b = c, t = r;
            while(t <= N) {
                while(t > r && a <= b) { //a 이동
                    //cout << t << ' ' << a << ' ' << b << '\n';
                    ll temp1 = segTree[t].query(0, N, 1, a-1, a-1);
                    ll temp2 = segTree[t-1].query(0, N, 1, a, a);
                    if(temp1 >= temp2) a++;
                    else break;
                }
                if(a > b) break; //a가 b를 넘어서면 해당 행 부터 갱신이 이루어지지 않으므로 중단
                while(b < N) { //b 이동
                    ll temp1 = segTree[t-1].query(0, N, 1, b+1, b+1);
                    ll temp2 = segTree[t].query(0, N, 1, b, b);
                    if(temp1 < temp2+1) b++;
                    else break;
                }
                //[a, b]구간 업데이트
                segTree[t].update(0, N, 1, a, b, 1);
                t++; //다음 행으로 이동
            }
        }
        else {
            arr[r][c]--;
            int a = c, b = c, t = r;
            while(t <= N) {
                while(t > r && a <= b) {
                    ll temp1 = segTree[t].query(0, N, 1, a-1, a-1);
                    ll temp2 = segTree[t-1].query(0, N, 1, a, a);
                    if(temp1 > temp2) a++;
                    else break;
                }
                if(a > b) break;
                while(b < N) {
                    ll temp1 = segTree[t-1].query(0, N, 1, b+1, b+1);
                    ll temp2 = segTree[t].query(0, N, 1, b, b);
                    if(temp1 <= temp2-1) b++;
                    else break;
                }
                segTree[t].update(0, N, 1, a, b, -1);
                t++;
            }
        }
        
        // for(int i = 1; i <= N; i++) {
        //     for(int j = 1; j <= N; j++) {
        //         cout << segTree[i].query(0, N, 1, j, j) << ' ';
        //     }
        //     cout << '\n';
        // }
        
        //구하고자 하는 값 출력
        ll ans = 0;
        for(int i = 1; i <= N; i++) {
            ans += segTree[i].total();
        }
        cout << ans << '\n';
    }

    return 0;
}