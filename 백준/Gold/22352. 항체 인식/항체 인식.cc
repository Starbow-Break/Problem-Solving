#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end();
#define rall(vec) vec.rbegin(), vec.rend();
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

int N, M;
int before[30][30], after[30][30];
bool visited[30][30] = {false, };

void dfs(int r, int c, int b, int a) {
    visited[r][c] = true;
    if(r-1 >= 0 && before[r-1][c] == b && after[r-1][c] == a && !visited[r-1][c]) {
        dfs(r-1, c, b, a);
    }
    if(r+1 < N && before[r+1][c] == b && after[r+1][c] == a && !visited[r+1][c]) {
        dfs(r+1, c, b, a);
    }
    if(c-1 >= 0 && before[r][c-1] == b && after[r][c-1] == a && !visited[r][c-1]) {
        dfs(r, c-1, b, a);
    }
    if(c+1 < M && before[r][c+1] == b && after[r][c+1] == a && !visited[r][c+1]) {
        dfs(r, c+1, b, a);
    }
}

queue<pii> q;
void dfs(int r, int c, int b) {
    visited[r][c] = true;
    q.push({r, c});
    if(r-1 >= 0 && before[r-1][c] == b && !visited[r-1][c]) {
        dfs(r-1, c, b);
    }
    if(r+1 < N && before[r+1][c] == b && !visited[r+1][c]) {
        dfs(r+1, c, b);
    }
    if(c-1 >= 0 && before[r][c-1] == b && !visited[r][c-1]) {
        dfs(r, c-1, b);
    }
    if(c+1 < M && before[r][c+1] == b && !visited[r][c+1]) {
        dfs(r, c+1, b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> before[r][c];
    }
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> after[r][c];
    }
    
    int cnt = 0, flag = true;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(!visited[r][c]) {
                if(before[r][c] != after[r][c]) cnt++;
                
                dfs(r, c, before[r][c]);
                int cur = 0, t = 0;
                while(!q.empty()) {
                    pii cur = q.front(); q.pop();
                    if(t == 0) {
                        t = after[cur.first][cur.second];
                    }
                    else {
                        if(t != after[cur.first][cur.second]) {
                            flag = false;
                        }
                    }
                }
            }
        }
    }
    
    cout << (cnt <= 1 && flag ? "YES" : "NO");

    return 0;
}