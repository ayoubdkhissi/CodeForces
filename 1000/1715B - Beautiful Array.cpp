/******** AYOUB DKHISSI *********/
 
#include <bits/stdc++.h>
using namespace std;
 
#define TESTS 1
 
 
/*typedefs:*/
typedef long long ll;
typedef long double ld;
 
/*CONSTANTS:*/
#define MOD 1000000007
 
 
/*Debuging & Printing*/
#define print_vector(v) for(int g=0; g<(int)v.size(); g++){cout<<v[g]<<" ";}cout<<endl
#define print_array(a,n) for(int i=0; i<n; i++){cout<<a[i]<<" ";}cout<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define print_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cout<<a[i][j]<<" ";}cout<<endl;}
 
/*Taking input*/
#define CIN_TIE() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define cin_array(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define cin_matrix(a,n,m) for(int i=0; i<n; i++){for(int j=0; j<m; j++){cin>>a[i][j];}}
#define cin_string_spaces(s) getline(std::cin, s)
 
/* Defined Functions*/
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b //Least Commun Multiple
#define onBits(x)  __builtin_popcountll(x) // Number of 1-bits in a number
#define count_element(a,x) count(a.begin(), a.end(),x)
#define _max(a) *max_element(a.begin(), a.end())
#define _min(a) *min_element(a.begin(), a.end())
 
/*******************************Templates and Functions************************************/
 
// String multiply by a number
string operator*(const string& s, ll n) {
	stringstream str;
	while (n--)
		str << s;
	return str.str();
}
 
// Check if all elements are the same in a container
template<class T>
bool all_is_same(const T& a) {
	if (adjacent_find(a.begin(), a.end(), not_equal_to<>()) == a.end())
		return true;
	return false;
}
 
 
/*
****************************************************************************************
*********************************** SOLVE HERE *****************************************
****************************************************************************************
*/
 
 
/*
	Notes:
 
	we are given:
	• k 
	• b the beauty resukt
	• s the sum of the array
	• n the size of the array
 
	we need to find the array.
 
	1 - calculate x = (kb + (k-1))>s?s : this element alone will give us b. if(x > s then the answer is yes)
	2 - now we need to find out if the rest is going to fit in the array, but all elements must be less than k.
		so we calculate y = roundUp((s-x)/k-1)  which is the number of elements needed to be included in the array
		this number must be be less than the number of remaining places which is (n-1)
	3 - if y>n => answer is -1
		else => answer = k-1, k-1.... left of (s-x), x>s?s:x, 0, 0, 0,...0
 
*/
 
 
 
 
void solve()
{
 
	ll n,k,b,s;
 
	cin >> n >> k >> b >> s;
 
	if(k*b > s)
	{
		cout << -1 << endl;
		return;
	}
 
	ll x = k*(b+1) - 1 > s ? s : k*(b+1) - 1;
 
	ll y = ceil((double)(s-x)/(k-1==0?k:k-1));
	if(y > n-1){
		cout << -1 << endl;
		return;
	}
 
	cout << x << " ";
	s -= x;
	for(int i=0; i<n-1; i++)
	{
		if(s <= 0)
			cout << 0 << " ";
		else
			cout << ((s-(k-1) >= 0) ? k-1 : s) << " " ; 
 
		s -= (k-1);
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
	for(int k = 0; k < t; k++)
	{
		//cout << "Case #" << k+1 << ": ";
		solve();
	}
  
  	return 0;
}