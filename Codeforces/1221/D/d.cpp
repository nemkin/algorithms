#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  // Enélkül time limites lesz.
  // Megöli a szinkronizációt a C-s és C++-os i/o függvények között
  // ami lassítaná a beolvasást és a kiírást.
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int queries;
  cin >> queries;
  while (queries--)
  {
    // Beolvasom az aktuális feladatot.
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i] >> b[i];

    // DP tömb, lehetne n*3-mas méretű is, de úgyis csak
    // az eggyel korábbi oszlopra van szükség, ezért
    // csak 2 oszlopot veszek fel és mindig amikor
    // az i. oszlopra akarok hivatkozni akkor i%2-t írok.
    // Így mindig az "egyik"-et töltöm ki és az eggyel
    // korábbi pedig kizárásos alapon a "másik" lesz.
    // "Pingpongozás az oszlopok között."
    vector<vector<ll>> dp(2, vector<ll>(3));

    // DP[i][j] jelentése: mennyibe kerül, hogy szép legyen
    // az a kerítés prefix, ami pont az i. lécig tart
    // és az i. lécen pont j-szer magasítottunk.

    // Meggondolandó, hogy 0<=j<=2, hiszen ha egy lécen már
    // 3-szor kellene magasítani, akkor egy kisebb=olcsóbb
    // magasság is jó lenne, hiszen csak 2 szomszédja van,
    // amitől különbözőnek kell lennie, a 3. érték mindig szabad.

    // Meggondolandó továbbá, hogy a j paraméterre azért
    // van szükség, mert nélküle nem tudnánk előrelépni a DP során.
    // Ki kell ugyanis zárni az egyforma magasak
    // egymás mellettiségét, vagyis tudnunk kell, hogy egy
    // költséghez milyen magas utolsó léc tartozott.

    // Első oszlop. Az egyléces kerítés mindig szép,
    // mennyibe kerül adott magasságra növelni.
    dp[0][0] = 0;
    dp[0][1] = b[0];
    dp[0][2] = 2 * b[0];

    // Töltjük lécenként a DP táblát balról-jobbra.
    for (int curr_lec = 1; curr_lec < n; ++curr_lec)
      // Ezen belül nézzük, hogy mennyivel akarjuk növelni curr_lec-et.
      for (int curr_plus = 0; curr_plus <= 2; ++curr_plus)
      {
        // Az aktuális léc ilyen magas és azt ennyibe került elérni.
        auto curr_height = a[curr_lec] + curr_plus;
        auto curr_price = b[curr_lec] * curr_plus;
        // Előző léc indexe.
        auto prev_lec = curr_lec - 1;

        // Attól függően, hogy az előző léc milyen magas volt,
        // mennyibe kerülhet széppé tenni idáig a kerítést:
        vector<ll> possible_prices;
        for (int prev_plus = 0; prev_plus <= 2; ++prev_plus)
        {
          auto prev_height = a[prev_lec] + prev_plus;
          // Ha az előző léc ugyanolyan magas mint a mostani, akkor nem szép,
          // ezt az értéket kihagyjuk.
          if (curr_height == prev_height)
            continue;

          // Pont annyiba kerül széppé tenni a curr_lec-ig a kerítést, úgy hogy
          // az curr_height magas legyen pontosan, mint amennyibe az eggyel
          // korábbi lécig széppé tevése került, feltéve hogy annak a magassága
          // nem egyezik a mi magasságunkkal, plusz az aktuális léc magasításának
          // az ára.
          possible_prices.push_back(dp[prev_lec % 2][prev_plus] + curr_price);
        }

        // A lehetséges költségek minimumával megyek toább.
        dp[curr_lec % 2][curr_plus] = *min_element(possible_prices.begin(), possible_prices.end());
      }

    // A megoldás az utolsó oszlopban lévő számok minimuma.
    auto moi = (n - 1) % 2;
    cout << min({dp[moi][0], dp[moi][1], dp[moi][2]}) << endl;
  }
  return 0;
}
