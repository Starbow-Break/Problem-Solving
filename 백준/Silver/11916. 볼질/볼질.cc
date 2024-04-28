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

bool base[4] = {false, }; int score = 0;
int ball = 0;
void hitterMove() {
    bool carry = true;
    for(int i = 1; i <= 4 && carry; i++) {
        if(i == 4) {
            score++;
        }
        else {
            carry = base[i];
            base[i] = true;
        }
    }
    ball = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        switch(v) {
            case 1:
            ball++;
            if(ball == 4) {
                hitterMove();
            }
            break;
            case 2:
            hitterMove();
            break;
            case 3:
            for(int i = 3; i >= 1; i--) {
                if(base[i]) {
                    if(i == 3) {
                        base[i] = false;
                        score++;
                    }
                    else {
                        base[i] = false;
                        base[i+1] = true;
                    }
                }
            }
            
            ball++;
            if(ball == 4) {
                hitterMove();
            }
            break;
        }
    }
    
    cout << score;
    
    return 0;
}