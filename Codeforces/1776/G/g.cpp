#include <bits/stdc++.h>
#include <cstdio>
#include <cassert>
#include <vector>

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

// https://gist.github.com/math314/6a08301b8b75b8172798
typedef long long ll;
typedef pair<int, int> Pii;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<int mod, int primitive_root>
class NTT {
public:
	int get_mod() const { return mod; }
	void _ntt(vector<ll>& a, int sign) {
		const int n = sz(a);
		assert((n ^ (n&-n)) == 0); //n = 2^k

		const int g = 3; //g is primitive root of mod
		int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod

		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}

		for (int m = 1; m < n; m *= 2) {
			const int m2 = 2 * m;
			const ll base = mod_pow(h, n / m2, mod);
			ll w = 1;
			FOR(x, m) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s];
					ll d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}

		for (auto& x : a) if (x < 0) x += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv(sz(input), mod);
		for (auto& x : input) x = x * n_inv % mod;
	}

	// 畳み込み演算を行う
	vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
		int ntt_size = 1;
		while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);

		ntt(_a);
		ntt(_b);

		FOR(i, ntt_size){
			(_a[i] *= _b[i]) %= mod;
		}

		intt(_a);
		return _a;
	}
};

ll garner(vector<Pii> mr, int mod){
	mr.emplace_back(mod, 0);

	vector<ll> coffs(sz(mr), 1);
	vector<ll> constants(sz(mr), 0);
	FOR(i, sz(mr) - 1) {
		ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
		if (v < 0) v += mr[i].first;

		for (int j = i + 1; j < sz(mr); j++) {
			(constants[j] += coffs[j] * v) %= mr[j].first;
			(coffs[j] *= mr[i].first) %= mr[j].first;
		}
	}

	return constants[sz(mr) - 1];
}

typedef NTT<167772161, 3> NTT_1;
typedef NTT<469762049, 3> NTT_2;
typedef NTT<1224736769, 3> NTT_3;

vector<ll> int32mod_convolution(vector<ll> a, vector<ll> b,int mod){
	for (auto& x : a) x %= mod;
	for (auto& x : b) x %= mod;
	NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
	auto x = ntt1.convolution(a, b);
	auto y = ntt2.convolution(a, b);
	auto z = ntt3.convolution(a, b);

	vector<ll> ret(sz(x));
	vector<Pii> mr(3);
	FOR(i, sz(x)){
		mr[0].first = ntt1.get_mod(), mr[0].second = (int)x[i];
		mr[1].first = ntt2.get_mod(), mr[1].second = (int)y[i];
		mr[2].first = ntt3.get_mod(), mr[2].second = (int)z[i];
		ret[i] = garner(mr, mod);
	}

	return ret;
}

vector<ll> fast_int32mod_convolution(vector<ll> a, vector<ll> b,int mod){
	for (auto& x : a) x %= mod;
	for (auto& x : b) x %= mod;
	
	NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
	assert(ntt1.get_mod() < ntt2.get_mod() && ntt2.get_mod() < ntt3.get_mod());
	auto x = ntt1.convolution(a, b);
	auto y = ntt2.convolution(a, b);
	auto z = ntt3.convolution(a, b);

	const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
	const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
	const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
	const ll m12_mod = m1 * m2 % mod;
	vector<ll> ret(sz(x));
	FOR(i, sz(x)){
		ll v1 = (y[i] - x[i]) *  m1_inv_m2 % m2;
		if (v1 < 0) v1 += m2;
		ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
		if (v2 < 0) v2 += m3;
		ll constants3 = (x[i] + m1 * v1 + m12_mod * v2) % mod;
		if (constants3 < 0) constants3 += mod;
		ret[i] = constants3;
	}

	return ret;
}

int main() {
  NTT_1 ntt1;
  int n; cin>>n;
  string s; cin>>s;

  int x = (s[n-1] == 'W');

  string s0 = s.substr(0, n-1);
  string s1 = s.substr(n, n-1);

  reverse(s1.begin(), s1.end());

  int count = 1;
  vector<ll> countss0(n+1, 0);
  int j = 0;
  for(int i=0; i<n-1; ++i) {
    if (s0[i] == 'R') {
      count += 1;
    } else {
      countss0[j] = count;
      ++j;
      count = 1;
    }
  }
  countss0[j] = count;

  count = 1;
  vector<ll> countss1(n+1, 0);
  j = 0;
  for(int i=0; i<n-1; ++i) {
    if (s1[i] == 'R') {
      count += 1;
    } else {
      countss1[j] = count;
      ++j;
      count = 1;
    }
  }
  countss1[j] = count;

  debug(s);
  debug(x);
  debug(s0);
  debug(s1);
  debug(countss0);
  debug(countss1);

  vector<ll> v = { 1, 2, 3 };
	vector<ll> u = { 4, 5, 6 };

	vector<ll> res = ntt1.convolution(countss0, countss1);

  int maxi = max_element(res.begin(), res.end()) - res.begin();
  debug(res);
  debug(maxi);

  cout << maxi+x;
  return 0;

}
