#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end();
#define rall(vec) vec.rbegin(), vec.rend();
#define fi first
#define se second
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int H, W;
int arr[1000][1000];
int dh[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dw[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int visited[1000][1000] = {0, };

bool check(int r, int c) {
    if(arr[r][c] == 0) return false;
    
    int cnt = 0;
    for(int k = 0; k < 8; k++) {
        cnt += (arr[r+dh[k]][c+dw[k]] == 0);
    }
    
    return cnt >= arr[r][c];
}

int solve() {
    queue<pii> q;
    // 첫번째 파도에 의해 사라지는 모래들을 큐에 담는다.
    for(int h = 1; h < H-1; h++) {
        for(int w = 1; w < W-1; w++) {
            if(check(h, w)) {
                q.push({h, w});
                visited[h][w] = 1;
            }
        }
    }
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        arr[cur.fi][cur.se] = 0;
        for(int k = 0; k < 8; k++) {
            if(check(cur.fi+dh[k], cur.se+dw[k]) && !visited[cur.fi+dh[k]][cur.se+dw[k]]) {
                q.push({cur.fi+dh[k], cur.se+dw[k]});
                visited[cur.fi+dh[k]][cur.se+dw[k]] = visited[cur.fi][cur.se]+1;
            }
        }
    }
    
    int ret = 0;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            ret = max(ret, visited[h][w]);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        string s; cin >> s;
        for(int w = 0; w < W; w++) {
            if(s[w] == '.') arr[h][w] = 0;
            else arr[h][w] = s[w]-'0';
        }
    }
    
    cout << solve() << '\n';

    return 0;
}