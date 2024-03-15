#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

char pattern[4000][51];

int colorToInt(char color) {
    switch(color) {
        case 'w' : return 0;
        case 'r' : return 1;
        case 'g' : return 2;
        case 'b' : return 3;
    }
    
    return -1;
}

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return (b ? gcd(b, a%b) : a);
}

bool check[2500][50][16] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w; cin >> h >> w;
    for(int r = 0; r < h; r++) cin >> pattern[r];
    
    int g = gcd(h, w);
    
    for(int i = 0; i < w; i++) {
        for(int j = i+1; j < w; j++) {
            for(int s = 0; s < g; s++) {
                for(int k = s; k < h; k += g) {
                    int colorStatus = 
                        (1<<colorToInt(pattern[k][i])) | (1<<colorToInt(pattern[k][j]));
                    check[i*w+j][s][colorStatus] = true;
                }
            }
        }
    }
    
    bool isPos = false;
    for(int i = 0; i < w; i++) {
        for(int j = i+1; j < w; j++) {
            for(int s = 0; s < h; s++) {
                int k = (s + (j-i))%g;
                int colorStatus = 
                    (1<<colorToInt(pattern[s][i])) | (1<<colorToInt(pattern[s][j]));
                int targetStatus = 15 ^ colorStatus;
                
                if(check[i*w+j][k][targetStatus]) isPos = true;
                
                k = (s + (w-j+i))%g;
                if(check[i*w+j][k][targetStatus]) isPos = true;
            }
        }
    }
    
    cout << (isPos ? "possible" : "impossible");
    
    return 0;
}