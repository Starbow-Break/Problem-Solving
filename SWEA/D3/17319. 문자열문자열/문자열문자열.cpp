#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
        int N; cin >> N;
		string s; cin >> s;
        if(N%2) cout << "No";
        else {
            bool flag = true;
            for(int i = 0; i < N/2 && flag; i++) {
                if(s[i] != s[i+N/2]) flag = false;
            }
            cout << (flag ? "Yes" : "No");
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}