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
	
	from the first character, jump to the nearest one (in alphabet chars)
	until you hit the last one.


	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
	a b c d e f g h i j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z

	15 - 12 + 15 - 9 +

	logic


	• the minimum cost = |index( s.front - index(s.back) )|
	• to get this minimum, 
	you need to jump over all the characters between the first character and the last character.

	we save positions of each character into a map.
	because the map is sorted by key by default
	we loop through the map starting from the key s[0] to the key s.back() (ascending or descending)
	so this way we get the positions of each character between the start and the back. 
*/



void solve()
{
	string s; cin >> s;
	map<char, vector<int>> M;
	
	for (int i = 0; i < s.size(); i++)
	{
		M[s[i]].push_back(i + 1);
	}

	
	vector<int> ans;

	if (s.front() < s.back())
	{
		for (auto it = M.find(s[0]); (*it).first != s.back(); ++it) {
			for (int i = 0; i < (*it).second.size(); i++)
			{
				ans.push_back((*it).second[i]);
			}
		}
	}
	else if (s.front() > s.back())
	{
		for (auto it = M.find(s[0]); (*it).first != s.back(); --it) {
			for (int i = 0; i < (*it).second.size(); i++)
			{
				ans.push_back((*it).second[i]);
			}
		}
	}

	
	for (int i = 0; i < M[s.back()].size(); i++)
		ans.push_back(M[s.back()][i]);
	


	cout << abs(s.back() - s.front()) << ' ' << ans.size() << endl;
	
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}

	cout << endl;

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