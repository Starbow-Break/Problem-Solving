#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    if(s.length() == 26) {
        int j = 25;
        while(j > 0 && s[j-1] > s[j]) j--;
        
        if(j == 0) s = "-1";
        else {
            j--;
            bool check[26] = {false, };
            string t = "";
            for(int i = 0; i <= j; i++) {
                check[s[i]-'a'] = true;
            }
            for(int i = 0; i < j; i++) {
                t += s[i];
            }
            for(int i = s[j]-'a'; i < 26; i++) {
                if(!check[i]) {
                    t += 'a'+i;
                    break;
                }
            }
            s = t;
        }
    }
    else {
        bool check[26] = {false, };
        for(auto &c: s) {
            check[c-'a'] = true;
        }
        
        for(int i = 0; i < 26; i++) {
            if(!check[i]) {
                s += 'a'+i;
                break;
            }
        }
    }
    
    cout << s;

    return 0;
}