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

int I, N, K; 
string color; int color_ord = 0;
char arr[100][101];
vector<pii> wall;
pii player;
int jump = 0;

void progress(string &command) {
    for(auto &com: command) {
        int r = player.fi;
        int c = player.se;
        if(com == 'U') {
            if(r-1 >= 0 && arr[r-1][c] == '.') {
                swap(arr[r-1][c], arr[r][c]);
                player = {r-1, c};
            }
        }
        if(com == 'D') {
            if(r+1 < N && arr[r+1][c] == '.') {
                swap(arr[r+1][c], arr[r][c]);
                player = {r+1, c};
            }
        }
        if(com == 'L') {
            if(c-1 >= 0 && arr[r][c-1] == '.') {
                swap(arr[r][c-1], arr[r][c]);
                player = {r, c-1};
            }
        }
        if(com == 'R') {
            if(c+1 < N && arr[r][c+1] == '.') {
                swap(arr[r][c+1], arr[r][c]);
                player = {r, c+1};
            }
        }
        if(com == 'j') jump++;
        if(com == 'J') {
            for(int rr = 0; rr < N; rr++) {
                for(int cc = 0; cc < N; cc++) {
                    if(abs(r-rr)+abs(c-cc) <= jump && arr[rr][cc] != '.' && arr[rr][cc] != '@') {
                        arr[rr][cc] = color[color_ord];
                    }
                }
            }
            color_ord = (color_ord+1)%color.length();
            jump = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> I >> N >> K;
    cin >> color;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == '#') wall.pb({i, j});
            if(arr[i][j] == '@') player = {i, j};
        }
    }
    
    string command; cin >> command;
    progress(command);
    
    for(int i = 0; i < N; i++) cout << arr[i] << '\n';

    return 0;
}