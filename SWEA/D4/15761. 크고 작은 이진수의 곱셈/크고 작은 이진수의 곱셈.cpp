#include<iostream>

using namespace std;

int arr[800'000];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << '#' << test_case << ' ';
        int A, B, ans = 0; cin >> A >> B;
        int sz = 2*(A+B);
        for(int i = 0; i < sz; i++) arr[i] = 0;
        for(int i = 0; i < A-1; i++) {
           	arr[B+i]++; arr[B+A+i]--;
       	}
        arr[A+2*B-1]++; arr[2*A+2*B-1]--;
        for(int i = 1; i < sz; i++) arr[i] += arr[i-1];
        for(int i = 0; i < sz-1; i++) {
            arr[i+1] += arr[i]/2;
            arr[i] %= 2;
            ans += arr[i];
        }
        ans += arr[sz-1];
        cout << ans << '\n';
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}