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

struct battle {
    int a, b;
    double w, d, l;
};

//p[a][b][c][d] = 승점이 a, b, c, d점으로 끝날 확률
double p[10][10][10][10] = {0, };
map<string, int> mp; //각 팀을 특정 값으로 변환
vector<battle> battles;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 4; i++) {
        string name; cin >> name;
        mp.insert({name, i});
    } 
    
    for(int i = 0; i < 6; i++) {
        string a, b;
        double w, d, l;
        cin >> a >> b >> w >> d >> l;
        battles.pb({mp.find(a)->se, mp.find(b)->se, w, d, l});
    }
    
    for(int _status = 0; _status < 729; _status++) {
        int score[4] = {0, }; //승점
        
        int status = _status;
        double pb = 1;
        for(int i = 0; i < 6; i++) {
            int result = status%3;
            status /= 3;
            
            int a = battles[i].a, b = battles[i].b;
            double w = battles[i].w, d = battles[i].d, l = battles[i].l;
            
            if(result == 0) {
                score[b] += 3;
                pb *= l;
            }
            else if(result == 1) {
                score[b]++; score[a]++;
                pb *= d;
            }
            else {
                score[a] += 3;
                pb *= w;
            }
        }
        
        p[score[0]][score[1]][score[2]][score[3]] += pb;
    }
    
    double ans[4] = {0, };
    
    for(int a = 0; a <= 9; a++) {
        for(int b = 0; b <= 9; b++) {
            for(int c = 0; c <= 9; c++) {
                for(int d = 0; d <= 9; d++) {
                    int arr[4] = {a, b, c, d};
                    sort(arr, arr+4);
                    int rank[4] = {0, };
                    int rankCnt[4] = {0, };
                    for(int i = 3; i >= 0; i--) {
                        if(arr[i] == a) rank[0] = max(rank[0], i);
                        if(arr[i] == b) rank[1] = max(rank[1], i);
                        if(arr[i] == c) rank[2] = max(rank[2], i);
                        if(arr[i] == d) rank[3] = max(rank[3], i);
                    }
                    for(int i = 0; i < 4; i++) {
                        rankCnt[rank[i]]++;
                    }
                    
                    if(rankCnt[3] == 4) {
                        double pp[4] = {0, 0, 0, 0.5};
                        for(int i = 0; i < 4; i++) {
                            ans[i] += p[a][b][c][d]*pp[rank[i]];
                        }
                    }
                    else if(rankCnt[3] == 3) {
                        double pp[4] = {0, 0, 0, 0.6666666666666666};
                        for(int i = 0; i < 4; i++) {
                            ans[i] += p[a][b][c][d]*pp[rank[i]];
                        }
                    }
                    else if(rankCnt[2] == 3) {
                        double pp[4] = {0, 0, 0.3333333333333333, 1};
                        for(int i = 0; i < 4; i++) {
                            ans[i] += p[a][b][c][d]*pp[rank[i]];
                        }
                    }
                    else if(rankCnt[2] == 2) {
                        double pp[4] = {0, 0, 0.5, 1};
                        for(int i = 0; i < 4; i++) {
                            ans[i] += p[a][b][c][d]*pp[rank[i]];
                        }
                    }
                    else {
                        double pp[4] = {0, 0, 1, 1};
                        for(int i = 0; i < 4; i++) {
                            ans[i] += p[a][b][c][d]*pp[rank[i]];
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < 4; i++) {
        cout << fixed << setprecision(12) << ans[i] << '\n';
    }
    
    return 0;
}
