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

int arr[1000][1000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j <= N; j++) {
            if('0' <= s[j] && s[j] <= '9') {
                arr[i][j] = -(s[j]-'0');
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 0) {
                for(int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        if(0 <= i+dx && i+dx < N && 0 <= j+dy && j+dy < N) {
                            if(dx != 0 || dy != 0) {
                                arr[i][j] += (arr[i+dx][j+dy] < 0 ? -arr[i+dx][j+dy] : 0);
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] < 0) cout << '*';
            else if(arr[i][j] >= 10) cout << 'M';
            else cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}