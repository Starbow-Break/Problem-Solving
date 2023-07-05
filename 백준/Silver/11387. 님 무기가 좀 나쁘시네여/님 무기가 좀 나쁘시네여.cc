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

const int MAX = 1'000'000;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

struct status {
    int atk, str, crip, crid, spd;
    
    ll calPow() {
        return 1LL*atk*(100+str)*(10000-min(crip*100, 10000)+min(crip, 100)*crid)*(100+spd);
    }
    
    status operator+(status &s) {
        return {atk+s.atk, str+s.str, crip+s.crip, crid+s.crid, spd+s.spd};
    }
    
    status operator-(status &s) {
        return {atk-s.atk, str-s.str, crip-s.crip, crid-s.crid, spd-s.spd};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int atk, str, crip, crid, spd;
    
    cin >> atk >> str >> crip >> crid >> spd;
    status cs = {atk, str, crip, crid, spd};
    cin >> atk >> str >> crip >> crid >> spd;
    status ps = {atk, str, crip, crid, spd};
    cin >> atk >> str >> crip >> crid >> spd;
    status cw = {atk, str, crip, crid, spd};
    cin >> atk >> str >> crip >> crid >> spd;
    status pw = {atk, str, crip, crid, spd};
    
    if(cs.calPow() < (cs-cw+pw).calPow()) cout << '+' << '\n';
    else if(cs.calPow() > (cs-cw+pw).calPow())  cout << '-' << '\n';
    else cout << '0' << '\n';
        
    if(ps.calPow() < (ps-pw+cw).calPow()) cout << '+' << '\n';
    else if(ps.calPow() > (ps-pw+cw).calPow())  cout << '-' << '\n';
    else cout << '0' << '\n';

    return 0;
}