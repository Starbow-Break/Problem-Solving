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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    bool card1[2*N+1], card2[2*N+1];
    fill(card1, card1+2*N+1, false);
    fill(card2, card2+2*N+1, false);
    
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        card1[v] = true;
    }
    
    for(int i = 1; i <= 2*N; i++) {
        if(!card1[i]) card2[i] = true;
    }
    
    int turn = 1;
    int remain1 = N, remain2 = N;
    int cur = 0;
    while(remain1 && remain2) {
        if(turn == 1) {
            bool check = false;
            for(int i = cur+1; i <= 2*N && !check; i++) {
                if(card1[i]) {
                    card1[i] = false;
                    remain1--;
                    cur = i;
                    check = true;
                }
            }
            
            if(!check) {
                cur = 0;
            }
        }
        else {
            bool check = false;
            for(int i = cur+1; i <= 2*N && !check; i++) {
                if(card2[i]) {
                    card2[i] = false;
                    remain2--;
                    cur = i;
                    check = true;
                }
            }
            
            if(!check) {
                cur = 0;
            }
        }
        
        turn = 3-turn;
    }
    
    cout << remain2 << '\n' << remain1;
    
    return 0;
}