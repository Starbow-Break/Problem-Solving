#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int R, S;
char arr[3000][3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> S;
    for(int i = 0; i < R; i++) cin >> arr[i];
    
    int h = R;
    for(int c = 0; c < S; c++) {
        int cur = 0; bool flag = false;
        for(int r = 0; r < R; r++) {
            if(arr[r][c] == 'X') { flag = true; cur = 0; }
            if(arr[r][c] == '.') cur++;
            if(arr[r][c] == '#') break;
        }
        if(flag) h = min(h, cur);
    }
    
    for(int r = R-1; r >= 0; r--) {
        for(int c = 0; c < S; c++) {
            if(arr[r][c] == 'X') swap(arr[r][c], arr[r+h][c]);
        }
    }
    
    for(int i = 0; i < R; i++) cout << arr[i] << '\n';

    return 0;
}