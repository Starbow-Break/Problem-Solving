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
#define MOD 1'000'000'007

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

int isExist[16];

int mbtiToInt(string mbti) {
    int ret = 0;
    if(mbti[0] == 'I') ret += 8;
    if(mbti[1] == 'N') ret += 4;
    if(mbti[2] == 'F') ret += 2;
    if(mbti[3] == 'P') ret += 1;
    return ret;
}

int dist(int i, int j) {
    int x = i^j;
    int ret = 0;
    while(x > 0) {
        ret += x%2; x /= 2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        fill(isExist, isExist+16, 0);
        int N; cin >> N;
        while(N--) {
            string mbti; cin >> mbti;
            int t = mbtiToInt(mbti);
            isExist[t]++;
        }
        
        int ans = 1000;
        for(int i = 0; i <= 15; i++) {
            for(int j = i; j <= 15; j++) {
                for(int k = j; k <= 15; k++) {
                    if(i == j && j == k) {
                        if(isExist[i] >= 3) ans = 0;
                    }
                    else if(i == j) {
                        if(isExist[i] >= 2 && isExist[k]) {
                            ans = min(ans, dist(i, j)+dist(j, k)+dist(k, i));
                        }
                    }
                    else if(j == k) {
                        if(isExist[j] >= 2 && isExist[i]) {
                            ans = min(ans, dist(i, j)+dist(j, k)+dist(k, i));
                        }
                    }
                    else if(i == k) {
                        if(isExist[i] >= 2 && isExist[j]) {
                            ans = min(ans, dist(i, j)+dist(j, k)+dist(k, i));
                        }
                    }
                    else {
                        if(isExist[i] && isExist[j] && isExist[k])
                            ans = min(ans, dist(i, j)+dist(j, k)+dist(k, i));
                    }
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}