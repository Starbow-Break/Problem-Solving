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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int A, B;
int field[100][100] = {0, };
int dir[101] = {0, };
int pos[101][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    int N, M; cin >> N >> M;
    FOR(i, 1, N+1) {
        int x, y; char d;
        cin >> x >> y >> d;
        field[x-1][y-1] = i;
        pos[i][0] = x-1;
        pos[i][1] = y-1;
        switch(d) {
            case 'N':
                dir[i] = 0;
                break;
            case 'E':
                dir[i] = 1;
                break;
            case 'S':
                dir[i] = 2;
                break;
            case 'W':
                dir[i] = 3;
        }
    }
    
    while(M--) {
        int num, cnt; char c;
        cin >> num >> c >> cnt;
        switch(c) {
            case 'F':
                repeat(cnt) {
                    int x = pos[num][0], y = pos[num][1];
                    pos[num][0] += dx[dir[num]];
                    pos[num][1] += dy[dir[num]];
                    if(0 > pos[num][0] || pos[num][0] >= A || 0 > pos[num][1] || pos[num][1] >= B) {
                        cout << "Robot " << num << " crashes into the wall";
                        return 0;
                    }
                    if(field[pos[num][0]][pos[num][1]] != 0) {
                        cout << "Robot " << num << " crashes into robot " << field[pos[num][0]][pos[num][1]];
                        return 0;
                    }
                    swap(field[x][y], field[pos[num][0]][pos[num][1]]);
                }
                break;
            case 'L':
                dir[num] = (dir[num]+3*cnt)%4;
                break;
            case 'R':
                dir[num] = (dir[num]+cnt)%4;
        }
    }
    
    cout << "OK";
    
    return 0;
}