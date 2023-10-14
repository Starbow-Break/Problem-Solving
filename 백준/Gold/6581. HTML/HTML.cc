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
    
    string s, line = "";
    while(getline(cin, s)) {
        s += ' ';
        string cur = "";
        for(auto &c: s) {
            // 공백이 나오면
            if(c == ' ' || c == '\t') {
                // br 태그가 나올 시, 줄 내림
                if(cur == "<br>") {
                    cout << line << '\n';
                    line = "";
                }
                // hr 태그가 나올 시, 새 줄 시작 -> 밑 줄 긋기 -> 새 줄 시작
                else if(cur == "<hr>") {
                    if(line != "") cout << line << '\n';
                    repeat(80) { cout << '-'; }
                    cout << '\n';
                    line = "";
                }
                //그냥 단어일 때
                else if(cur != "") {
                    // 새 단어를 추가할 때 80글자를 넘으면
                    if(line.length()+(line != "")+cur.length() > 80) {
                        cout << line << '\n';
                        line = cur;
                    }
                    else {
                        if(line != "") line += ' ';
                        line += cur;
                    }
                }
                
                cur = "";
            }
            else cur += c;
        }
    }
    
    
    if(line != "") cout << line;
    cout << '\n';
    
    return 0;
}