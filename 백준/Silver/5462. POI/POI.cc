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

bool ac[2001][2001];
int score[2001] = {0, };
int total[2001] = {0, };
int cnt[2001] = {0, };

struct result {
    int score, answer, id;
    bool operator<(result &r) {
        if(score != r.score) return score < r.score;
        if(answer != r.answer) return answer < r.answer;
        return id > r.id;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, T, P; cin >> N >> T >> P;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= T; j++) {
            cin >> ac[i][j];
            score[j] += !ac[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= T; j++) {
            total[i] += score[j]*ac[i][j];
            cnt[i] += ac[i][j];
        }
    }
    
    vector<result> vec;
    for(int i = 1; i <= N; i++) {
        vec.pb({total[i], cnt[i], i});
    }
    
    sort(rall(vec));
    
    for(int i = 1; i <= N; i++) {
        if(vec[i-1].id == P) {
            cout << total[vec[i-1].id] << ' ' << i;
            break;
        }
    }
    
    return 0;
}
