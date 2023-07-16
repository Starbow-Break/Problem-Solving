#include <bits/stdc++.h>

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

vector<string> stringToList(string &s) {
    vector<string> ret;
    string t = "";
    for(auto c: s) {
        if(c == ' ') {
            ret.push_back(t);
            t = "";
        }
        else t += c;
    }
    ret.push_back(t);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    cin.ignore();
    while(T--) {
        string s;
        getline(cin, s);
        vector<string> words = stringToList(s);
        
        string t = "";
        set<string> st;
        while(1) {
            getline(cin, t);
            if(t == "what does the fox say?") break;
            vector<string> temp = stringToList(t);
            st.insert(temp[2]);
        }
        
        for(auto &w: words) {
            auto iter = st.find(w);
            if(iter == st.end()) cout << w << ' ';
        }
    }

    return 0;
}