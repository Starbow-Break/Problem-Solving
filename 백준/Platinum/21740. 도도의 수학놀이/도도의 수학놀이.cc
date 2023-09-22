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
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

string rotate(string num) {
    string ret = "";
    reverse(all(num));
    for(auto &c: num) {
        if(c == '6') ret += '9';
        else if(c == '9') ret += '6';
        else ret += c;
    }
    return ret;
}

bool cmp(string &a, string &b) {
    return a+b < b+a;
}

bool cmp1(string &a, string &b) {
    if(a.length() != b.length()) return a.length() < b.length();
    return a+b < b+a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 숫자 받기
    vector<string> numbers;
    int N; cin >> N;
    repeat(N) {
        string v; cin >> v;
        numbers.pb(v);
    }
    
    // 숫자 회전
    for(int i = 0; i < N; i++) {
        numbers[i] = rotate(numbers[i]);
    }
    
    //정렬
    sort(rall(numbers), cmp1);
    numbers.pb(numbers[0]);
    
    sort(rall(numbers), cmp);
    string ans = "";
    for(auto &n: numbers) {
        ans += n;
    }
    
    cout << rotate(ans);
    
    return 0;
}