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
#include <set>

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

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 1) return 1;
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

bool cmp1(string &s, string &t) {
    int lenS = s.length(), lenT = t.length();
    for(int k = 0; k < lcm(lenS, lenT); k++) {
        if(s[k%lenS] < t[k%lenT]) return false;
        if(s[k%lenS] > t[k%lenT]) return true;
    }
    return lenS > lenT; 
}

bool cmp2(string &s, string &t) {
    if(s.length() != t.length())
        return s.length() > t.length();
    
    return cmp1(s, t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string> numbers, ans;
    
    int K, N; cin >> K >> N;
    for(int k = 0; k < K; k++) {
        string num; cin >> num;
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end(), cmp2);
    
    while(N > K) {
        ans.push_back(numbers[0]);
        N--;
    }
    for(int i = 0; i < K; i++) ans.push_back(numbers[i]);
    
    sort(ans.begin(), ans.end(), cmp1);
    
    for(auto &s: ans) cout << s;

    return 0;
}