/******** AYOUB DKHISSI *********/

#include <bits/stdc++.h>
using namespace std;

#define TESTS 1


/*typedefs:*/
using ll = long long;
using ld = long double;

/*CONSTANTS:*/
constexpr auto MOD = 1000000007;


/*input*/
#define CIN_TIE() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

/* Defined Functions*/
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b //Least common multiple
#define onBits(x)  __builtin_popcountll(x) // Number of 1-bits in a number
#define _max(a) *max_element(a.begin(), a.end())
#define _min(a) *min_element(a.begin(), a.end())
#define to_lower(a) transform(s.begin(), s.end(), s.begin(), ::tolower)
// String multiply by a number
string operator*(const string& s, ll n) {
	stringstream str;
	while (n--)
		str << s;
	return str.str();
}




/*
****************************************************************************************
*********************************** SOLVE HERE *****************************************
****************************************************************************************
*/


/*
	Notes:
	
	• there is no answer if and only if the string is already not beautiful


	• we take a greedy approach.
	we traverse the string, if we find a '?', then we give it a character different than
	the character before and the character after. 
	and we need to handle the case where first character is '?' or the last character is '?'.

	• a???a -> ababa
	• a????a -> ababca
	• a???b -> abacb
	• a????b -> ababab


*/

// this function takes one character and return a different character
char diff(char c)
{
	if (c == 'a')
		return 'b';
	if (c == 'b')
		return 'a';
	return 'a';
}

// this function takes two characters and returns a character different than them both.
char diff(char c1, char c2)
{
	if (c1 == c2)
		return diff(c1);
	if ((c1 == 'a' && c2 == 'b') ||(c1 == 'b' && c2 == 'a'))
		return 'c';
	if ((c1 == 'a' && c2 == 'c') || (c1 == 'c' && c2 == 'a'))
		return 'b';
	if ((c1 == 'b' && c2 == 'c') ||(c1 == 'c' && c2 == 'b'))
		return 'a';

}

void solve()
{
	string s; cin >> s;

	int n = s.size();
	if (n == 1)
	{
		cout << (s[0] == '?' ? 'a' : s[0]) << endl;
		return;
	}

	for (int i = 0; i < n-1; i++)
	{
		if (s[i] != '?' && s[i] == s[i + 1])
		{
			cout << -1 << endl;
			return;
		}
	}

	if (s[0] == '?')
		s[0] = diff(s[1]);
	for (int i = 1; i < n - 1; i++)
	{
		if (s[i] == '?' && s[i + 1] == '?')
			s[i] = diff(s[i-1]);
		if (s[i] == '?' && s[i + 1] != '?')
			s[i] = diff(s[i - 1], s[i + 1]);

	}

	if (s[n - 1] == '?')
		s[n - 1] = diff(s[n - 2]);


	cout << s << endl;
	
}
/*
****************************************************************************************
****************************************************************************************
****************************************************************************************
*/

int main()
{
	CIN_TIE();
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);


	ll t = 1;
#if TESTS
	cin >> t;
#endif

	for (int k = 0; k < t; k++)
	{
		//cout << "Case #" << k+1 << ": ";
		solve();
	}

	return 0;
}