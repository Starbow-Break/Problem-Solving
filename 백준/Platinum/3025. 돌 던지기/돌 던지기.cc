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
#include <set>

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

int R, C;
char arr[30001][31];
stack<pii> route[30];

void progress(pii pos, int col) {
    int r = pos.first; int c = pos.second;
    while(1) {
        if(arr[r+1][c] == '.') {
            r++; route[col].push({r, c});
        } else if(arr[r+1][c] == 'X') {
            arr[r][c] = 'O'; break;
        } else {
            if(c-1 >= 0 && arr[r][c-1] == '.' && arr[r+1][c-1] == '.') {
                r++; c--; route[col].push({r, c});
            } else if(c+1 < C && arr[r][c+1] == '.' && arr[r+1][c+1] == '.') {
                r++; c++; route[col].push({r, c});
            } else {
                arr[r][c] = 'O'; break;
            }
        }
    }
}

//돌 떨구기
void drop(int start) {
    while(!route[start].empty()) {
        if(arr[route[start].top().first][route[start].top().second] == '.') break;
        route[start].pop(); //돌이 있으면 해당 위치는 갈 수 없으므로 제거
    }
    //해당 열에 대한 정보가 없으면 처음부터 시행
    if(route[start].empty()) {
        progress({0, start}, start);
    } else {
        progress(route[start].top(), start); //스택의 맨 위에 있는 위치에서부터 시행 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) cin >> arr[i];
    //바닥도 벽이랑 동일한 역할을 함
    for(int i = 0; i < C; i++) arr[R][i] = 'X';
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        drop(v-1);
    }
    
    for(int i = 0; i < R; i++) cout << arr[i] << '\n';

    return 0;
}