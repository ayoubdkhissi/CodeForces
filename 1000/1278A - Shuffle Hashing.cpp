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
	Given the password p, and a hash h. check if h can be a hash for p using the specified algorithm.


	• we need to scan h with a sliding window of length p.size().
	if we find that we can construct p from the current window, then the answer is YES

	
	see the sliding window technique : https://www.geeksforgeeks.org/window-sliding-technique/



*/


void solve()
{

	string p, h; cin >> p >> h;

	if (h.size() < p.size())
	{
		cout << "NO" << endl;
		return;
	}

	sort(p.begin(), p.end());

	int k = p.size();
	for (int i = 0; i < h.size() - k + 1; i++)
	{
		string current_window = h.substr(i, k);
		sort(current_window.begin(), current_window.end());
		if (current_window == p)
		{
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
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