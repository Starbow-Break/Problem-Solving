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

int N, M;
int arr[9][9];
map<int, int> dp[81];

int getNormalizationStatus(vector<int> &status_vec) {
    int brr[11] = {0, }; int cnt = 0;
    vector<int> vec;
    for(auto &v: status_vec) {
        if(v) {
            if(brr[v]) vec.pb(brr[v]);
            else {
                cnt++;
                brr[v] = cnt;
                vec.pb(cnt);
            }
        }
        else vec.pb(0);
    }
    
    int ret = 0;
    for(int i = vec.size()-1; i >= 0; i--) {
        ret *= 10;
        ret += vec[i];
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> arr[r][c];
    }
    
    dp[0].insert({1, arr[0][0]});
    for(int i = 1; i < N*M; i++) {
        dp[i].insert({1, arr[i/M][i%M]});
        for(auto &[s, value]: dp[i-1]) {
            vector<int> status_vec;
            int status = s;
            for(int j = 0; j < M; j++) {
                status_vec.pb(status%10);
                status /= 10;
            }
            
            // 새로운 칸을 선택 안할 때
            bool check = true;
            if(status_vec[M-1]) { // 위칸이 선택된 상태
                check = false;
                // 다른 M-1개의 칸이랑 연결되어 있는지 확인
                for(int j = 0; j < M-1; j++) {
                    if(status_vec[j] == status_vec[M-1]) {
                        check = true;
                    }
                }
            }
            
            // check가 true이면 선택하지 않는 케이스를 고려
            if(check) {
                vector<int> new_stat_vec;
                new_stat_vec.pb(0);
                for(int j = 0; j < M-1; j++) {
                    new_stat_vec.pb(status_vec[j]);
                }
                
                int newStatus = getNormalizationStatus(new_stat_vec);
                
                auto t = dp[i].find(newStatus);
                if(t == dp[i].end()) {
                    dp[i].insert({newStatus, value});
                }
                else {
                    t->second = min(t->second, value);
                }
            }
            
            // 새로운 칸을 선택할 때
            if(!(i%M && status_vec[0]) && !(i/M && status_vec[M-1])) { // 위, 왼쪽 선택 X
                vector<int> new_stat_vec;
                new_stat_vec.pb(10);
                for(int j = 0; j < M-1; j++) {
                    new_stat_vec.pb(status_vec[j]);
                }
                
                int newStatus = getNormalizationStatus(new_stat_vec);
                
                auto t = dp[i].find(newStatus);
                if(t == dp[i].end()) {
                    dp[i].insert({newStatus, value+arr[i/M][i%M]});
                }
                else {
                    t->second = min(t->second, value+arr[i/M][i%M]);
                }
            }
            else if((i%M && status_vec[0]) && !(i/M && status_vec[M-1])) { // 왼쪽만 선택
                vector<int> new_stat_vec;
                new_stat_vec.pb(status_vec[0]);
                for(int j = 0; j < M-1; j++) {
                    new_stat_vec.pb(status_vec[j]);
                }
                
                int newStatus = getNormalizationStatus(new_stat_vec);
                
                auto t = dp[i].find(newStatus);
                if(t == dp[i].end()) {
                    dp[i].insert({newStatus, value+arr[i/M][i%M]});
                }
                else {
                    t->second = min(t->second, value+arr[i/M][i%M]);
                }
            }
            else if(!(i%M && status_vec[0]) && (i/M && status_vec[M-1])) { // 위쪽만 선택
                vector<int> new_stat_vec;
                new_stat_vec.pb(status_vec[M-1]);
                for(int j = 0; j < M-1; j++) {
                    new_stat_vec.pb(status_vec[j]);
                }
                
                int newStatus = getNormalizationStatus(new_stat_vec);
                
                auto t = dp[i].find(newStatus);
                if(t == dp[i].end()) {
                    dp[i].insert({newStatus, value+arr[i/M][i%M]});
                }
                else {
                    t->second = min(t->second, value+arr[i/M][i%M]);
                }
            }
            else { // 왼쪽, 위 둘다 선택
                vector<int> new_stat_vec;
                int bef = status_vec[0];
                int aft = status_vec[M-1];
                new_stat_vec.pb(aft);
                for(int j = 0; j < M-1; j++) {
                    new_stat_vec.pb(status_vec[j]);
                }
                for(int j = 0; j < M; j++) {
                    if(new_stat_vec[j] == bef) {
                        new_stat_vec[j] = aft;
                    }
                }
                
                int newStatus = getNormalizationStatus(new_stat_vec);
                
                auto t = dp[i].find(newStatus);
                if(t == dp[i].end()) {
                    dp[i].insert({newStatus, value+arr[i/M][i%M]});
                }
                else {
                    t->second = min(t->second, value+arr[i/M][i%M]);
                }
            }
        }
    }
    
    // 최솟값 찾기
    int ans = 0;
    for(int i = 0; i < N*M; i++) {
        for(auto &[s, value]: dp[i]) {
            vector<int> status_vec;
            int status = s;
            for(int j = 0; j < M; j++) {
                status_vec.pb(status%10);
                status /= 10;
            }
            
            int temp = 0;
            bool check = true;
            for(auto &v: status_vec) {
                if(v) {
                    if(temp) {
                        if(temp != v) check = false;
                    }
                    else {
                        temp = v;
                    }
                }
            }
            
            if(check) {
                ans = min(ans, value);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
