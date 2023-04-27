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
#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

template<size_t _Nw> void _M_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for(int i=0, c=0; i<_Nw; i++)
		c=_subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
}
template<size_t _Nb> bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B) {
	bitset<_Nb> C(A);
	_M_sub(C, B);
	return C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string S, T; cin >> S >> T;
    int n = S.length(), m = T.length();
    bitset<50000> B(0), match[26], x, y;
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < m; j++) {
            match[i][j] = (T[j] == (char)('A'+i));
        }
    }
    
    for(int i = 0; i < n; i++) {
        x = match[S[i]-'A'] | B;
        y = (B << 1); y[0] = 1;
        B = x^(x&(x-y));
    }
    
    cout << B.count() << '\n';

    return 0;
}