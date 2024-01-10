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
    
    random_device rd;
    mt19937 gen(rd());
    
    int A, B;
    bool check[10001] = {false, };
    for(int i = 10000; i >= 1; i--) {
        vector<int> numbers;
        for(int j = 1; j <= 10000; j++) {
            if(!check[j]) numbers.pb(j);
        }
        
        int v = gen()%i;
        cout << "? A " << numbers[v] << '\n';
        cout.flush();
        
        int result; cin >> result;
        if(result) {
            A = numbers[v]; break;
        }
        else {
            check[numbers[v]] = true;
        }
    }
    
    fill(check, check+10001, false);
    for(int i = 10000; i >= 1; i--) {
        vector<int> numbers;
        for(int j = 1; j <= 10000; j++) {
            if(!check[j]) numbers.pb(j);
        }
        
        int v = gen()%i;
        cout << "? B " << numbers[v] << '\n';
        cout.flush();
        
        int result; cin >> result;
        if(result) {
            B = numbers[v]; break;
        }
        else {
            check[numbers[v]] = true;
        }
    }
    
    cout << "! " << A+B << '\n';
    
    return 0;
}