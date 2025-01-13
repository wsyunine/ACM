#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

const long long Mod = 998244353;

const int N = 1e5 + 10;

int n;
string str;
long long u[100][2], l[100][2], d[100][2], s[100][2];

int main()
{

	scanf("%d", &n);
	cin >> str;

	if (str[0] >= 'A' && str[0] <= 'Z') {
		l[str[0] - 'A' + 1][0] = 1;
		d[str[0]-'A'+1][0]=1;
		s[str[0] - 'A' + 1][0] = 1;
	}
	else if (str[0] >= '0' && str[0] <= '9') {
		u[str[0] - '0' +1+ 26+26][0] = 1;
		u[str[0]-'0'+1+26+26][0]=1;
		s[str[0] - '0' + 1+26+26][0] = 1;
	}
	else if (str[0] >= 'a' && str[0] <= 'z') {
		u[str[0] - 'a' + 1 + 26][0] = 1;
		l[str[0] - 'a' + 1][0] = 1;
		s[str[0] - 'a' + 1][0] = 1;
		s[str[0] - 'a' + 1 + 26][0] = 1;
		d[str[0]-'a'+1][0]=1;
		d[str[0]-'a'+1+26][0]=1;
	}
	else if (str[0] == '?') {
		for (int i = 1; i <= 26; i++) {
			l[i][0] = 1;
			d[i][0]=1;
			s[i][0] = 1;
		}
		for (int i = 27; i <= 26 + 26; i++) {
			u[i][0] = 1;
			d[i][0]=1;
			s[i][0] = 1;
		}
		for (int i = 26 + 26 + 1; i <= 26 + 26 + 10; i++) {
			u[i][0] = 1;
			l[i][0]=1;
			s[i][0] = 1;
		}
	}
	for (int k = 1; k < n; k++) {
		int op = k & 1;
		long long U = 0, L = 0, D = 0, S = 0;
		if (str[k] >= 'A' && str[k] <= 'Z') {
			for (int i = 1; i <= 26; i++) {
				if (i == str[k] - 'A' + 1) continue;
				(L += l[i][op ^ 1])%=Mod;
				(D+=d[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 27; i <= 26 + 26; i++) {
				(D+=d[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 26 + 26 + 1; i <= 26 + 26 + 10; i++) {
				(L+=l[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			s[str[k] - 'A' + 1][op] = S;
			l[str[k] - 'A' + 1][op] = L;
			d[str[k] - 'A' + 1][op] = D;
			u[str[k] - 'A' + 1][op] = U;
		}
		else if(str[k] >= '0' && str[k] <= '9') {
			for (int i = 1; i <= 26; i++) {
				(L+=l[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 27; i <= 26 + 26; i++) {
				(U+=u[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 26 + 26 + 1; i <= 26 + 26 + 10; i++) {
				if (i == str[k] - '0' + 1 + 26 + 26) continue;
				(U += u[i][op ^ 1]) %= Mod;
				(L+=l[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			s[str[k] - '0' + 1+26+26][op] = S;
			l[str[k] - '0' + 1+26+26][op] = L;
			d[str[k] - '0' + 1+26+26][op] = D;
			u[str[k] - '0' + 1+26+26][op] = U;
		}
		else if (str[k] >= 'a' && str[k] <= 'z') {
			for (int i = 1; i <= 26; i++) {
				if (i == str[k] - 'a' + 1) continue;
				(L += l[i][op ^ 1])%=Mod;
				(D+=d[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 27; i <= 26 + 26; i++) {
				(D+=d[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 26 + 26 + 1; i <= 26 + 26 + 10; i++) {
				(L+=l[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			s[str[k] - 'a' + 1][op] = S;
			l[str[k] - 'a' + 1][op] = L;
			d[str[k] - 'a' + 1][op] = D;
			u[str[k] - 'a' + 1][op] = U;
			U = 0, L = 0, D = 0, S = 0;
			for (int i = 1; i <= 26; i++) {
				(D+=d[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 27; i <= 26 + 26; i++) {
				if (i == str[k] - 'a' + 1 + 26) continue;
				(D += d[i][op ^ 1]) %= Mod;
				(U+=u[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			for (int i = 26 + 26 + 1; i <= 26 + 26 + 10; i++) {
				(U+=u[i][op^1])%=Mod;
				(S += s[i][op ^ 1]) %= Mod;
			}
			s[str[k] - 'a' + 1+26][op] = S;
			l[str[k] - 'a' + 1+26][op] = L;
			d[str[k] - 'a' + 1+26][op] = D;
			u[str[k] - 'a' + 1+26][op] = U;
		}
		else if (str[k] == '?') {
			for(int i=1;i<=26+26+10;i++){
				(s[i][op^1]+=s[i-1][op^1])%=Mod;
				(u[i][op^1]+=u[i-1][op^1])%=Mod;
				(l[i][op^1]+=l[i-1][op^1])%=Mod;
				(d[i][op^1]+=d[i-1][op^1])%=Mod;
			}
			for (int i = 1; i <= 26; i++) {
				U = 0, L = 0, D = 0, S = 0;	
				(L += l[26][op ^ 1]-l[i][op^1]+l[i-1][op^1]+Mod) %= Mod;
				(D += d[26][op ^ 1]-d[i][op^1]+d[i-1][op^1]+Mod) %= Mod;
				(S += s[26][op ^ 1]-s[i][op^1]+s[i-1][op^1]+Mod) %= Mod;
				(D += d[26+26][op ^ 1]-d[26][op^1]+Mod) %= Mod;
				(S += s[26+26][op ^ 1]-s[26][op^1]+Mod) %= Mod;
				(L += l[26+26+10][op ^ 1]-l[26+26][op^1]+Mod) %= Mod;
				(S += s[26+26+10][op ^ 1]-s[26+26][op^1]+Mod) %= Mod;
				s[i][op] = S;
				l[i][op] = L;
				d[i][op] = D;
				u[i][op] = U;
			}
			for (int i = 1+26; i <= 26+26; i++) {
				U = 0, L = 0, D = 0, S = 0;
				(D += d[26][op ^ 1]) %= Mod;
				(S += s[26][op ^ 1]) %= Mod;
				(D += d[26+26][op ^ 1]-d[26][op^1]-d[i][op^1]+d[i-1][op^1]+Mod+Mod) %= Mod;
				(U += u[26+26][op ^ 1]-u[26][op^1]-u[i][op^1]+u[i-1][op^1]+Mod+Mod) %= Mod;
				(S += s[26+26][op ^ 1]-s[26][op^1]-s[i][op^1]+s[i-1][op^1]+Mod+Mod) %= Mod;
				(U += u[26+26+10][op ^ 1]-u[26+26][op^1]+Mod) %= Mod;
				(S += s[26+26+10][op ^ 1]-s[26+26][op^1]+Mod) %= Mod;
				s[i][op] = S;
				l[i][op] = L;
				d[i][op] = D;
				u[i][op] = U;
			}
			for (int i = 1 + 26+26; i <= 26 + 26+10; i++) {
				U = 0, L = 0, D = 0, S = 0;
				(L += l[26][op ^ 1]) %= Mod;
				(S += s[26][op ^ 1]) %= Mod;
				(U += u[26+26][op ^ 1]-u[26][op^1]+Mod) %= Mod;
				(S += s[26+26][op ^ 1]-s[26][op^1]+Mod) %= Mod;
				(U += u[26+26+10][op ^ 1]-u[26+26][op^1]-u[i][op^1]+u[i-1][op^1]+Mod+Mod) %= Mod;
				(L += l[26+26+10][op ^ 1]-l[26+26][op^1]-l[i][op^1]+l[i-1][op^1]+Mod+Mod) %= Mod;
				(S += s[26+26+10][op ^ 1]-s[26+26][op^1]-s[i][op^1]+s[i-1][op^1]+Mod+Mod) %= Mod;
				s[i][op] = S;
				l[i][op] = L;
				d[i][op] = D;
				u[i][op] = U;
			}
		}
		for (int i = 1; i <= 26 + 26 + 10; i++) {
			s[i][op ^ 1] = 0;
			u[i][op^1]=0;
			l[i][op^1]=0;
			d[i][op^1]=0;
		}
		long long ans = 0;
		for (int i = 1; i <= 26 + 26 + 10; i++) {
			(ans += s[i][op]) %= Mod;
			cout<<l[i][op]<<" ";
		}
		cout<<endl;
		cout << ans << endl;
	}
	
	n--;
	long long ans = 0;
	for (int i = 1; i <= 26 + 26 + 10; i++) {
		(ans += s[i][n & 1])%=Mod;
	}
	for (int i = 1; i <= 26 + 26 + 10; i++) {
		ans = ((ans - u[i][n & 1] - l[i][n & 1] - d[i][n & 1]+Mod) % Mod + Mod+Mod) % Mod;
	}
	cout << ans << endl;

	return 0;
}
