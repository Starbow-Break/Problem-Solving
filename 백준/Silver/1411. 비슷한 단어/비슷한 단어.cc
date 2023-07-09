#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

bool similar(string &a, string &b) {
    int f[27] = {0, }, g[27] = {0, };
    
    for(int i = 0; i < a.length(); i++) {
        if(f[a[i]-'a'+1] == 0 && g[b[i]-'a'+1] == 0) {
            f[a[i]-'a'+1] = b[i]-'a'+1;
            g[b[i]-'a'+1] = a[i]-'a'+1;
        }
        else {
            if(f[a[i]-'a'+1] != b[i]-'a'+1) return false;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string> words;
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        string w; cin >> w;
        words.push_back(w);
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            ans += similar(words[i], words[j]);
        }
    }
    
    cout << ans;

    return 0;
}