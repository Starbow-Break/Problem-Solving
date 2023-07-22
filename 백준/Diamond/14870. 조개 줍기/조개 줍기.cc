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

//펜윅 트리
struct fenwickTree {
    ll _fenwick[1<<11];
    
    fenwickTree() {
        fill(_fenwick, _fenwick+(1<<11), 0);
    }
    
    ll sum(int s) {
        ll ret = 0;
        while(s > 0) {
            ret += _fenwick[s];
            s -= (s & -s);
        }
        return ret;
    }
    
    void add(int idx, int del) {
        while(idx < (1<<11)) {
            _fenwick[idx] += del;
            idx += (idx & -idx);
        }
    }
    
    //Range update
    void update(int s, int e, int del) {
        add(s, del); add(e+1, -del);
    }
    
    //point query
    ll query(int s) {
        return sum(s);
    }
}fenwick[1501];

int arr[1501][1501] = {0, };
int dp[1501][1501] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])+arr[i][j];
            ans += dp[i][j];
        }
    }
    
    //dp에 맞춰 펜윅 트리 초기화
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            fenwick[i].update(j, j, dp[i][j]);
        }
    }
    
    //처음 답 출력
    cout << ans << '\n';
    
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
                    ll temp1 = fenwick[t].query(a-1);
                    ll temp2 = fenwick[t-1].query(a);
                    if(temp1 >= temp2) a++;
                    else break;
                }
                if(a > b) break; //a가 b를 넘어서면 해당 행 부터 갱신이 이루어지지 않으므로 중단
                while(b < N) { //b 이동
                    ll temp1 = fenwick[t-1].query(b+1);
                    ll temp2 = fenwick[t].query(b);
                    if(temp1 < temp2+1) b++;
                    else break;
                }
                //[a, b]구간 업데이트
                fenwick[t].update(a, b, 1);
                ans += (b-a+1);
                t++; //다음 행으로 이동
            }
        }
        else {
            arr[r][c]--;
            int a = c, b = c, t = r;
            while(t <= N) {
                while(t > r && a <= b) {
                    ll temp1 = fenwick[t].query(a-1);
                    ll temp2 = fenwick[t-1].query(a);
                    if(temp1 > temp2) a++;
                    else break;
                }
                if(a > b) break;
                while(b < N) {
                    ll temp1 = fenwick[t-1].query(b+1);
                    ll temp2 = fenwick[t].query(b);
                    if(temp1 <= temp2-1) b++;
                    else break;
                }
                fenwick[t].update(a, b, -1);
                ans -= (b-a+1);
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
        cout << ans << '\n';
    }

    return 0;
}