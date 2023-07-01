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

int N, M;
char candies[400][401];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++) {
        cin >> N >> M;
        for(int i = 0; i < N; i++) cin >> candies[i];
        
        int candy = 0;
        for(int r = 0; r < N; r++) {
            for(int c = 0; c <= M-3; c++) {
                if(candies[r][c] == '>' && candies[r][c+1] == 'o' && candies[r][c+2] == '<') candy++;
            }
        }
        
        for(int c = 0; c < M; c++) {
            for(int r = 0; r <= N-3; r++) {
                if(candies[r][c] == 'v' && candies[r+1][c] == 'o' && candies[r+2][c] == '^') candy++;
            }
        }
        
        cout << candy << '\n';
    }

    return 0;
}