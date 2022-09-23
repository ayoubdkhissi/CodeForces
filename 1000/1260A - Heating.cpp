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
	
	the optimal answer is to install c radiators, and the number of sections of each
	radiator is sum/c, and the reminders will be distributed on all the radiators one by one
	so
	• (c - sum%c) radiator will have (sum/c) sections 
	• (sum%c) raditaros will had (sum/c + 1) sections


	so the answer is: ans = (c - sum%c)*((sum/c)^2) + (sum%c)*(sum/c + 1)^2

	
	example 
	c = 4 sum 6 =>
	sum%c = 6%4 = 2, so 2 radiator will have (sum/c + 1) = 2 sections
	c - sum%c = 4 - 2 = 2, and 2 radiatro will have (sum/c) = (6/4) = 1 sections
	
	ans = (4-2)*(6/4)² + 2*(6/4 + 1)² = 2 + 2*4 = 10


*/



void solve()
{
	ll c, sum; cin >> c >> sum;

	ll ans = (c - sum % c) * (sum / c) * (sum / c) + (sum % c) * (sum / c + 1) * (sum / c + 1);

	cout << ans << endl;
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