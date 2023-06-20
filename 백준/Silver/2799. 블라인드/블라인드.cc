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

char arr[1000][1000];

int cnt[5] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, N; cin >> M >> N;
    for(int r = 0; r <= 5*M; r++) cin >> arr[r];
    
    for(int r = 0; r < M; r++) {
        for(int c = 0; c < N; c++) {
            for(int k = 0; k <= 4; k++) {
                if(arr[5*r+1+k][5*c+1] != '*') {
                    cnt[k]++; break;
                }
            }
        }
    }
    
    for(int i = 0; i < 5; i++) cout << cnt[i] << ' ';
    
    return 0;
}