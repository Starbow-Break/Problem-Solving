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
#define x first
#define y second

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

pii pos[11]; //말의 위치
int dir[11]; //말의 이동 방향
int arr[12][12]; //게임 판
vector<int> brr[12][12]; //말의 위치 표시

int N, K; 
bool move(int num) {
    int r = pos[num].x; int c = pos[num].y;
    if(brr[r][c][0] != num) return false; //가장 아래에 있는 말이 아니면 이동 불가
    
    switch(dir[num]) {
        case 1: //오른쪽
            if(c+1 >= N || arr[r][c+1] == 2) {
                dir[num] = 2; //판을 넘어가거나 파란색 타일이면 방향 전환
                if(c-1 >= 0 && arr[r][c-1] != 2) {
                    if(arr[r][c-1] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                    for(auto &v: brr[r][c]) {
                        brr[r][c-1].push_back(v);
                        pos[v] = {r, c-1};
                    }
                    brr[r][c].clear();
                    return brr[r][c-1].size() >= 4;
                }
                return brr[r][c].size() >= 4;
            }
            else {
                if(arr[r][c+1] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                for(auto &v: brr[r][c]) {
                    brr[r][c+1].push_back(v);
                    pos[v] = {r, c+1};
                }
                brr[r][c].clear();
                return brr[r][c+1].size() >= 4;
            }
            break;
        case 2: //왼쪽
            if(c-1 < 0 || arr[r][c-1] == 2) {
                dir[num] = 1; //판을 넘어가거나 파란색 타일이면 방향 전환
                if(c+1 < N && arr[r][c+1] != 2) {
                    if(arr[r][c+1] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                    for(auto &v: brr[r][c]) {
                        brr[r][c+1].push_back(v);
                        pos[v] = {r, c+1};
                    }
                    brr[r][c].clear();
                    return brr[r][c+1].size() >= 4;
                }
                return brr[r][c].size() >= 4;
            }
            else {
                if(arr[r][c-1] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                for(auto &v: brr[r][c]) {
                    brr[r][c-1].push_back(v);
                    pos[v] = {r, c-1};
                }
                brr[r][c].clear();
                return brr[r][c-1].size() >= 4;
            }
            break;
        case 3: //위쪽
            if(r-1 < 0 || arr[r-1][c] == 2) {
                dir[num] = 4; //판을 넘어가거나 파란색 타일이면 방향 전환
                if(r+1 < N && arr[r+1][c] != 2) {
                    if(arr[r+1][c] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                    for(auto &v: brr[r][c]) {
                        brr[r+1][c].push_back(v);
                        pos[v] = {r+1, c};
                    }
                    brr[r][c].clear();
                    return brr[r+1][c].size() >= 4;
                }
                return brr[r][c].size() >= 4;
            }
            else {
                if(arr[r-1][c] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                for(auto &v: brr[r][c]) {
                    brr[r-1][c].push_back(v);
                    pos[v] = {r-1, c};
                }
                brr[r][c].clear();
                return brr[r-1][c].size() >= 4;
            }
            break;
        case 4: //아래쪽
            if(r+1 >= N || arr[r+1][c] == 2) {
                dir[num] = 3; //판을 넘어가거나 파란색 타일이면 방향 전환
                if(r-1 >= 0 && arr[r-1][c] != 2) {
                    if(arr[r-1][c] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                    for(auto &v: brr[r][c]) {
                        brr[r-1][c].push_back(v);
                        pos[v] = {r-1, c};
                    }
                    brr[r][c].clear();
                    return brr[r-1][c].size() >= 4;
                }
                return brr[r][c].size() >= 4;
            }
            else {
                if(arr[r+1][c] == 1) reverse(brr[r][c].begin(), brr[r][c].end());
                for(auto &v: brr[r][c]) {
                    brr[r+1][c].push_back(v);
                    pos[v] = {r+1, c};
                }
                brr[r][c].clear();
                return brr[r+1][c].size() >= 4;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> arr[i][j];
    }
    
    for(int i = 1; i <= K; i++) {
        int a, b, d; cin >> a >> b >> d;
        pos[i] = {a-1, b-1};
        brr[a-1][b-1].push_back(i);
        dir[i] = d;
    }
    
    int ans = 0; bool flag = false;
    while(ans <= 1000 && !flag) {
        ans++;
        for(int i = 1; i <= K; i++) {
            flag = flag || move(i); //이동
        }
    }
    
    cout << (ans > 1000 ? -1 : ans);

    return 0;
}