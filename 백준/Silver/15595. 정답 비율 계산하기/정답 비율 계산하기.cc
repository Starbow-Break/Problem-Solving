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
    
    map<string, int> mp;
    int N; cin >> N;
    while(N--) {
        int num, result, execTime, memory, language, codeLength; string name;
        cin >> num >> name >> result >> execTime >> memory >> language >> codeLength;
        
        if(name == "megalusion") continue;
        auto t = mp.find(name);
        
        if(t == mp.end()) {
            if(result == 4) mp.insert({name, 1});
            else mp.insert({name, -1});
        }
        else {
            if(t->second > 0) continue;
            
            if(result == 4) t->second = 1-t->second;
            else t->second--;
        }
    }
    
    int ac = 0, total = 0;
    for(auto &m: mp) {
        if(m.second > 0) {
            ac++; total += m.second;
        }
    }
    
    if(total == 0) cout << 0;
    else cout << fixed << setprecision(12) << (double)ac/total*100;

    return 0;
}