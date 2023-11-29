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
 
bool star[3125][3125] = {false, };
int pow5[6] = {1, 5, 25, 125, 625, 3125};
 
void drawStar(int r, int c, int l) {
    if(!l) {
        star[r][c] = true;
        return;
    }
    drawStar(r, c+2*pow5[l-1], l-1);
    drawStar(r+pow5[l-1], c+2*pow5[l-1], l-1);
    for(int i = 0; i < 5; i++) {drawStar(r+2*pow5[l-1], c+i*pow5[l-1], l-1);}
    for(int i = 1; i <= 3; i++) {drawStar(r+3*pow5[l-1], c+i*pow5[l-1], l-1);}
    drawStar(r+4*pow5[l-1], c+1*pow5[l-1], l-1); drawStar(r+4*pow5[l-1], c+3*pow5[l-1], l-1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    drawStar(0, 0, N);
    
    FOR(r, 0, pow5[N]) {
        FOR(c, 0, pow5[N]) {
            cout << (star[r][c] ? '*' : ' ');
        }
        cout << '\n';
    }
    
    return 0;
}