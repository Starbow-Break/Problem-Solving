#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

char mine[10][11]; //지뢰 장소
char open[10][11]; //열린 칸
char ans[10][10]; //답
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> mine[i];
    for(int i = 0; i < N; i++) cin >> open[i];
    
    bool mineOpen = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(open[i][j] == 'x') {
                if(mine[i][j] == '*') mineOpen = true;
                else {
                    int cnt = 0;
                    for(int k = 0; k < 8; k++) {
                        if(0 <= i+dr[k] && i+dr[k] < N && 0 <= j+dc[k] && j+dc[k] < N) {
                            cnt += (mine[i+dr[k]][j+dc[k]] == '*');
                        }
                    }
                    ans[i][j] = '0'+cnt;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(open[i][j] == 'x' && mine[i][j] != '*') cout << ans[i][j];
            else {
                if(mineOpen && mine[i][j] == '*') cout << '*';
                else cout << '.';
            }
        }
        cout << '\n';
    }

    return 0;
}