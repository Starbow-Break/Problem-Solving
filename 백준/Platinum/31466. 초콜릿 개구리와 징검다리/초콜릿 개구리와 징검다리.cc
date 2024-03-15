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
    
    vector<pii> move;
    
    if(N == 1) {
        move.pb({0, 2});    
    }
    else if(N == 2) {
        move.pb({0, 2}); 
        move.pb({0, 1});
        move.pb({1, 3});
        move.pb({2, 3}); 
    }
    else if(N == 3) {
        move.pb({0, 1});
        move.pb({0, 2}); 
        move.pb({1, 2});
        move.pb({0, 1});
        move.pb({1, 3});
        move.pb({3, 4});
        move.pb({2, 3});
        move.pb({2, 4});
        move.pb({3, 4});
    }
    else {
        if(N%2) {
            for(int i = 2; i <= N-3; i += 2) {
                move.pb({0, 1});
                for(int j = 2; j <= i; j += 2) {
                    move.pb({j-2, j});
                }
                move.pb({i, i+1});
                
                for(int j = 2; j <= i; j += 2) {
                    move.pb({max(1, j-2), j});
                }
                move.pb({i, i+1});
            }
            
            move.pb({0, 1});
            for(int i = 2; i <= N-1; i += 2) {
                move.pb({i-2, i});
            }
            move.pb({N-1, N});
            
            for(int i = 2; i <= N+1; i += 2) {
                move.pb({i-2, i});
            }
            
            move.pb({N, N+1});
            move.pb({1, 2});
            for(int i = 4; i <= N+1; i += 2) {
                move.pb({i-2, i});
            }
            
            for(int i = N-3; i >= 2; i -= 2) {
                move.pb({i+1, i+2});
                for(int j = i+1; j <= N; j += 2) {
                    move.pb({j, min(N+1, j+2)});
                }
                for(int j = i+2; j <= N; j += 2) {
                    move.pb({j, min(N+1, j+2)});
                }
            }
        }
        else {
            for(int i = 2; i <= N-2; i += 2) {
                move.pb({0, 1});
                for(int j = 2; j <= i; j += 2) {
                    move.pb({j-2, j});
                }
                move.pb({i, i+1});
                
                for(int j = 2; j <= i; j += 2) {
                    move.pb({max(1, j-2), j});
                }
                move.pb({i, i+1});
            }
            
            move.pb({0, 1});
            
            for(int i = 2; i <= N; i += 2) {
                move.pb({i-2, i});
            }
            move.pb({N, N+1});
            
            move.pb({1, 2});
            for(int i = 4; i <= N; i += 2) {
                move.pb({i-2, i});
            }
            move.pb({N, N+1});
            
            for(int i = N-2; i >= 2; i -= 2) {
                move.pb({i+1, i+2});
                for(int j = i+1; j <= N; j += 2) {
                    move.pb({j, min(N+1, j+2)});
                }
                for(int j = i+2; j <= N; j += 2) {
                    move.pb({j, min(N+1, j+2)});
                }
            }
        }
    }
    
    cout << move.size() << '\n';
    for(auto &p: move) {
        cout << p.fi << ' ' << p.se << '\n';
    }
    
    return 0;
}