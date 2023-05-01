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
#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

//bitset 뺄셈
template<size_t _Nw> void _M_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for(int i=0, c=0; i<_Nw; i++)
		c=_subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
}
template<size_t _Nb> bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B) {
	bitset<_Nb> C(A);
	_M_sub(C, B);
	return C;
}

//Hirschberg's algorithm
string lcs = "";
template<int sz> int hirschberg(string &s, string &t, int ls, int lt, int rs, int rt) {
    bitset<sz> B1, B2, x, y, match1[26], match2[26];
    
    for(int i = 0; i < rs-ls; i++) {
        match1[s[ls+i]-'A'][i] = 1;
        match2[s[ls+i]-'A'][rs-ls-i-1] = 1;
    }
    
    int mid = (lt+rt)>>1;
    for(int i = lt; i < mid; i++) {
        x = match1[t[i]-'A'] | B1;
        y = B1 << 1; y[0] = 1;
        B1 = x^(x&(x-y));
    }
    
    for(int i = rt; i > mid; i--) {
        x = match2[t[i-1]-'A'] | B2;
        y = B2 << 1; y[0] = 1;
        B2 = x^(x&(x-y));
    }
    
    int idx = ls, maxV, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < rs-ls; i++) cnt2 += B2[i];
    maxV = cnt1+cnt2;
    for(int i = 1, j = rs-ls-1; i <= rs-ls; i++) {
        cnt1 += B1[i-1]; cnt2 -= B2[j];
        if(maxV < cnt1+cnt2) {
            idx = ls+i; maxV = cnt1+cnt2;
        }
        j--;
    }
    
    return idx;
}

int _hirschberg(string &s, string &t, int ls, int lt, int rs, int rt) {
    int sz = rs-ls;
    
    if(sz <= 97) return hirschberg<97>(s, t, ls, lt, rs, rt);
    if(sz <= 195) return hirschberg<195>(s, t, ls, lt, rs, rt);
    if(sz <= 390) return hirschberg<390>(s, t, ls, lt, rs, rt);
    if(sz <= 781) return hirschberg<781>(s, t, ls, lt, rs, rt);
    if(sz <= 1562) return hirschberg<1562>(s, t, ls, lt, rs, rt);
    if(sz <= 3125) return hirschberg<3125>(s, t, ls, lt, rs, rt);
    if(sz <= 6250) return hirschberg<6250>(s, t, ls, lt, rs, rt);
    if(sz <= 12500) return hirschberg<12500>(s, t, ls, lt, rs, rt);
    if(sz <= 25000) return hirschberg<25000>(s, t, ls, lt, rs, rt);
    return hirschberg<50000>(s, t, ls, lt, rs, rt);
}

void solve(string &s, string &t, int ls, int lt, int rs, int rt) {
    if(rs <= ls || rt <= lt) return;
    
    if(rt-lt == 1) {
        for(int i = ls; i < rs; i++) {
            if(s[i] == t[lt]) { lcs += t[lt]; break; }
        }
        
        return;
    }
    
    int idx = _hirschberg(s, t, ls, lt, rs, rt);
    
    if(idx == -1) return;
    
    int mid = (lt+rt)>>1;
    solve(s, t, ls, lt, idx, mid);
    solve(s, t, idx, mid, rs, rt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t; cin >> s >> t;
    
    solve(s, t, 0, 0, s.length(), t.length());
    cout << lcs.length() << '\n' << lcs;

    return 0;
}