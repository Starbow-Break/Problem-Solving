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

int R, C;
char arr[20][21];
vector<string> words;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for(int r = 0; r < R; r++) cin >> arr[r];
    
    for(int r = 0; r < R; r++) {
        string t = "";
        for(int c = 0; c <= C; c++) {
            if(arr[r][c] == '#' || arr[r][c] == '\0') {
                if(t.length() >= 2) words.push_back(t);
                t = "";
            }
            else t += arr[r][c];
        }
    }
    
    for(int c = 0; c < C; c++) {
        string t = "";
        for(int r = 0; r <= R; r++) {
            if(r == R || arr[r][c] == '#') {
                if(t.length() >= 2) words.push_back(t);
                t = "";
            }
            else t += arr[r][c];
        }
    }

    sort(words.begin(), words.end());
    
    cout << words[0];
    
    return 0;
}