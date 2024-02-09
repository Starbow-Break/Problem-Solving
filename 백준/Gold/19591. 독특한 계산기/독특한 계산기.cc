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

deque<char> op;
deque<ll> value;

ll calc(ll a, ll b, char o) {
    switch(o) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    ll cur = 0; bool flag = (s[0] == '-');
    for(int i = (s[0] == '-'); i < s.length(); i++) {
        char c = s[i];
        if('0' <= c && c <= '9') {
            cur = 10*cur+(c-'0');
        }
        else {
            if(flag) {
                cur *= -1;
                flag = false;
            }
            
            value.push_back(cur);
            cur = 0; 
            op.push_back(c);
        }
    }
    if(flag) cur *= -1;
    value.push_back(cur);
    
    if(value.size() == 1) {
        cout << value.front();
        return 0;
    }
    
    while(value.size() > 2) {
        bool flag = false;
        ll f1, f2, b1, b2;
        f1 = value.front(); value.pop_front();
        f2 = value.front(); value.pop_front();
        b1 = value.back(); value.pop_back();
        
        if(value.empty()) { b2 = f2; flag = true; }
        else { b2 = value.back(); value.pop_back(); }
        
        char of, ob;
        of = op.front(); op.pop_front();
        ob = op.back(); op.pop_back();
        
        if((of == '*' || of == '/') && (ob == '+' || ob == '-')) {
            value.push_front(calc(f1, f2, of));
            if(!flag) value.push_back(b2);
            value.push_back(b1);
            op.push_back(ob);
        }
        else if((ob == '*' || ob == '/') && (of == '+' || of == '-')) {
            value.push_back(calc(b2, b1, ob));
            if(!flag) value.push_front(f2);
            value.push_front(f1);
            op.push_front(of);
        }
        else {
            ll rf = calc(f1, f2, of);
            ll rb = calc(b2, b1, ob);
            if(rf >= rb) {
                value.push_front(rf);
                if(!flag) value.push_back(b2);
                value.push_back(b1);
                op.push_back(ob);
            }
            else {
                value.push_back(rb);
                if(!flag) value.push_front(f2);
                value.push_front(f1);
                op.push_front(of);
            }
        }
        
        // for(auto &v: value) cout << v << ' ';
        // cout << '\n';
    }
    
    ll a = value.front(); value.pop_front();
    ll b = value.front(); value.pop_front();
    char o = op.front(); op.pop_front();
    // cout << a << ' ' << b << ' ' << o << '\n';
    cout << calc(a, b, o);
    
    return 0;
}
