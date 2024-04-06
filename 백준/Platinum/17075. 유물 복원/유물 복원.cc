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

int N, M, K;
int arr[50][50]; // 석판
int w[50][50]; // 가중치
int cnt[2500] = {0, }; // -1인 칸에 대해 가중치 카운트
int visited[2500][2500] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) fill(visited[i], visited[i]+K, -1);
    
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            w[i][j] = (i+1)*(N-i)%K*(j+1)%K*(M-j)%K;
            
            if(arr[i][j] == -1) {
                cnt[w[i][j]]++;
            }
            else {
                sum += w[i][j] * arr[i][j];
                sum %= K;
            }
        }
    }
    
    if(sum == 0) {
        cout << 1 << '\n';
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cout << (arr[i][j] > 0 ? 1 : 0) << ' ';
            }
            cout << '\n';
        }
        
        return 0;
    }
    
    int startIdx = -1;
    visited[0][sum] = 0;
    for(int i = 1; i < K; i++) {
        for(int j = 0; j < K; j++) {
            if(visited[i-1][j] == -1) continue;
            for(int k = 0; k <= cnt[i]; k++) {
                int t = (j+i*k)%K;
                if(visited[i][t] == -1) {
                    visited[i][t] = k;
                }
            }
        }
        
        if(visited[i][0] != -1) {
            startIdx = i;
            break;
        }
    }
    
    //
    // for(int i = 0; i < K; i++) cout << cnt[i] << ' ';
    // cout << '\n' << '\n';
    
    //
    // for(int i = 0; i < K; i++) {
    //     for(int j = 0; j < K; j++) {
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    if(startIdx == -1) {
        cout << -1;
        return 0;
    }
    
    int _cnt[2500] = {0, };
    int cur = 0;
    for(int i = startIdx; i >= 1; i--) {
        if(visited[i][cur]) {
            _cnt[i] = visited[i][cur];
            cur = (cur+(K-i)*visited[i][cur])%K;
        }
    }
    
    cout << 1 << '\n';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == -1) {
                if(_cnt[w[i][j]] > 0) {
                    cout << 1 << ' ';
                    _cnt[w[i][j]]--;
                }
                else {
                    cout << 0 << ' ';
                }
            }
            else {
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
