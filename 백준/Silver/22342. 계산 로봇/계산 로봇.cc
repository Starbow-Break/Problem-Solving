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

char arr[2000][2001];
int D[2000][2001];
int save[2000][2000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, N; cin >> M >> N;
    for(int i = 0; i < M; i++) cin >> arr[i];
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            D[i][j] = arr[i][j]-'0';
        }
    }
    
    for(int c = 1; c < N; c++) {
        for(int r = 0; r < M; r++) {
            if(r > 0) save[r][c] = max(save[r][c], save[r-1][c-1]+D[r-1][c-1]);
            save[r][c] = max(save[r][c], save[r][c-1]+D[r][c-1]);
            if(r < M-1) save[r][c] = max(save[r][c], save[r+1][c-1]+D[r+1][c-1]);
        }
    }
    
    int ans = 0;
    for(int c = 0; c < N; c++) {
        for(int r = 0; r < M; r++) {
            ans = max(ans, save[r][c]);
        }
    }
    
    cout << ans;

    return 0;
}