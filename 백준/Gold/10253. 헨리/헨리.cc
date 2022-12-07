#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

ll gcd(ll a, ll b) {
    if(a < b) return gcd(b, a);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

class Fraction {
    private:
        int a, b;
    public:
        Fraction(int a, int b) {
            this->a = a;
            this->b = b;
        }
        
        bool operator<(Fraction &frac) {
            return 1LL*a*frac.b-1LL*frac.a*b < 0;
        }
        
        Fraction operator-(Fraction &frac) {
            ll x = 1LL*a*frac.b-1LL*frac.a*b;
            ll y = 1LL*frac.b*b;
            ll g = gcd(x, y);
            
            return Fraction(x/g, y/g);
        }
        
        bool isUnit() { return a == 1; }
        int getDenom() { return b; }
};

int solve(Fraction frac) {
    int i = 2;
    while(1) {
        if(frac.isUnit()) return frac.getDenom();
        
        Fraction f = Fraction(1, i);
        if(f < frac) { frac = frac-f; }
        i++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int a, b; cin >> a >> b;
        cout << solve(Fraction(a, b)) << '\n';
    }

    return 0;
}