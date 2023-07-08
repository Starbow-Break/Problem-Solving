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

char game[30][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> game[i];
    
    string ans = "ongoing";
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c <= N-3; c++) {
            bool check = true;
            for(int k = 0; k < 3; k++) {
                if(game[r][c] != game[r][c+k] || game[r][c+k] == '.') check = false;
            }
            if(check) ans = game[r][c];
        }
    }
    
    for(int c = 0; c < N; c++) {
        for(int r = 0; r <= N-3; r++) {
            bool check = true;
            for(int k = 0; k < 3; k++) {
                if(game[r][c] != game[r+k][c] || game[r+k][c] == '.') check = false;
            }
            if(check) ans = game[r][c];
        }
    }
    
    for(int r = 0; r <= N-3; r++) {
        for(int c = 0; c <= N-3; c++) {
            bool check = true;
            for(int k = 0; k < 3; k++) {
                if(game[r][c] != game[r+k][c+k] || game[r+k][c+k] == '.') check = false;
            }
            if(check) ans = game[r][c];
        }
    }
    
    for(int r = 0; r <= N-3; r++) {
        for(int c = 2; c < N; c++) {
            bool check = true;
            for(int k = 0; k < 3; k++) {
                if(game[r][c] != game[r+k][c-k] || game[r+k][c-k] == '.') check = false;
            }
            if(check) ans = game[r][c];
        }
    }
    
    cout << ans;

    return 0;
}