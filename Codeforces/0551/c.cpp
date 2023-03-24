#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef long long ll;

int n, m;
vector<ll> a;

// Ez a függvény megmondja, hogy <time> idő alatt fel lehet-e
// szedni az a-ban lévő dobozokat legfeljebb m db ember használatával.
bool possible(ll time) {
  
  // Alapötlet: mohó működik.
  // Miért:
  // - Állítás: A legutolsó dobozt valakinek fel kell szedni.
  // - Ez a valaki el fog menni a legutolsó dobozig, amire elhasznál x időt.
  // - A maradék time-x idővel menet közben ennyi db dobozt levehet bárhonnan.
  // - Akkor járunk a legjobban, ha a végéről veszi le az összes dobozt,
  //   mivel a rákövetkező játékosok így lehet, hogy kevesebb időt pazarolnak
  //   majd lépésre.
  // - Lépjük ezt meg az utolsó emberrel. Maradni fog a-ban valamennyi doboz.
  // - Ismételjük ugyanezt új emberekkel amíg el nem fogynak a dobozok.
  // - Ha ekkor m-nél kevesebb vagy egyenlő embert használtunk akkor meg
  //   lehet csinálni.
  // - Ha m-nél többet használtunk, akkor nincs alternatív konfiguráció
  //   ami =<m-et használ.
  //    - Ezt bizonyítani valahogy úgy kéne, hogy indirekt feltesszük, hogy
  //      mégis van ilyen, abban felsoroljuk a végső pozíciókat minden
  //      emberre, észrevesszük hogy ezek csak nagyobbak lehetnek a 
  //      mohó által adottnál és akkor meg ezek az emberek meg tudják
  //      egymás között cserélni a dobozaikat, hogy egymást követőek
  //      legyenek, ezért a mohónak is találnia kellett volna megoldást.
  // - Következmény: Ha van megoldás, akkor olyan is van amiben az emberek
  //   egymást követő dobozokat vesznek le.
  // Ezt implementáljuk.
  // Innentől kezdve nem is kell hátulról menni, előlről is végig lehet
  // ezt játszani. 

  // Kezdő játékos.
  int people = 1;
  // Time ideje van.
  ll leftover_time = time;
  
  // A lassú verzió az embereket egyesével küldi, de az a[i]<=10^9 miatt ez time limites lesz.
  // Lásd https://codeforces.com/contest/551/submission/198876335
  // Helyette: iterálunk a dobozokon i-vel.
  for(int i=0; i<n; ++i) {
    // Ha az aktuális játékosnak még van ideje akkor rálép az i. aktuális cellára
    // az előző pozícióból.
    if (0 < leftover_time) {
      --leftover_time;
    } else {
      // Ha elfogyott az idő akkor először megnézzük, hogy van-e épp doboz a[i]-ben.
      if (!a[i]) {
        // Ha nincs, akkor még halogatjuk az új ember küldést, hátha 
        // nincs is már több doboz vissza a-ban.
        continue;
      }
      // Ha elfogyott az idő de doboz még van, akkor küldünk egy új játékost az elejéről.
      people += 1;
      // Ő i+1 lépés alatt ér ide, ezért time - ennyi ideje van vissza.
      leftover_time = time - (i+1);
      // Ha nem tudunk eljutni ebbe a cellába, vagy nem marad időnk
      // dobozt is leszedni, pedig a[i]-ben van doboz, akkor nem megoldható
      // time idő alatt a feladat.
      if (leftover_time <= 0) {
        return false;
      }
    }
    // Ha az aktuális embernek van ideje összeszedni a dobozokat,
    // akkor ő szedi össze egyedül.
    if ( a[i] <= leftover_time ) {
      leftover_time -= a[i];
    // Ha neki nincs elég ideje, akkor több emberre is szükség van,
    // hogy pontosan hány darabra, azt kezeljük maradékos osztással
    // csoportosítottan.
    } else {
      // A mostani játékos elveszi amit tud és őt ezzel kivégeztük.
      // A maradék dobozokat új játékosok viszik el.
      ll boxes_for_new_people = a[i] - leftover_time;
      // Ilyenkor a mostani játékos idejét kinullázzuk, majd a következő
      // játékos kap új időt.
      leftover_time = 0;
      // Az összes új játékos frissen jön ide, nekik ennyi idejük lesz még miután ideértek.
      ll new_people_leftover_time = time - (i+1);
      // Ha a frissen küldött embereknek nincs idejük összeszedni a dobozokat,
      // akkor lehetetlen a feladat time időben.
      if (new_people_leftover_time == 0) {
        return false;
        // Így elkerüljük a 0-val osztást a következő sorokban.
      }
      // Ennyi darab ember fog idejönni és kivégződni ezen a pozíción teljesen.
      people += boxes_for_new_people / new_people_leftover_time;
      // És akkor még van a boxes_for_new_people % new_people_leftover_time maradék,
      // ami ha nem 0, akkor azt egy ember fogja elvinni és ő tovább is tud majd innen lépni:
      if (boxes_for_new_people % new_people_leftover_time) {
        people += 1;
        leftover_time = new_people_leftover_time - boxes_for_new_people % new_people_leftover_time;
      }
    }
  }

  // Amikor ide eljutottunk, akkor a dobozokat felszedtük, az a kérdés
  // hány emberre volt szükség ehhez.
  return people <= m;
}

// [from, to] intervallumon keres binárisan legkisebb olyan értéket,
// amire még meg lehet csinálni.
// Invariáns tulajdonság: to-ra biztosan meg lehet majd csinálni.
// Ezt használjuk a +-1-ek beállításához.
// (Ciklusinvariánsként szokott szerepelni ciklusokkal kapcsolatban,
// olyat még nem hallottam, hogy "rekurzióinvariáns".)
ll binsearch(ll from, ll to) {
  // 1 hosszúra szűkült az intervallum, az invariáns miatt a to
  // a legkisebb megcsinálható time.
  if (from == to) return to;

  // Itt néha van még egy +(from + to)%2, de most azért nem kell,
  // mert azt akarom, hogy ha from + 1 = to, akkor mid a from-ra
  // álljon rá és tesztelje, mert a to-t biztosan meg lehet csinálni.
  // (Különben meg lehet gondolni, hogy végtelen rekurzió lenne.)
  ll mid = (from + to) / 2; 

  if (possible(mid)) {
    // Ezután ha a mid-et meg lehet csinálni, akkor ez lehet az új
    // to, hiszen teljesül rá az invariáns tulajdonság.
    return binsearch(from, mid);
  } else {
    // Ha a mid-et nem lehet megcsinálni, akkor az intervallumból
    // kidobhatjuk. To-t továbbra is meg lehet, invariáns teljesül.
    return binsearch(mid+1, to);
  }
}

int main() {
  cin >> n >> m;

  a.resize(n);
  for(int i=0; i<n; ++i) cin >> a[i];

  // - A kérdés, hogy mennyi idő alatt lehet a feladatot megcsinálni.
  // - Már megírtuk a függvényt, ami gyosan megmondja, hogy adott idő alatt meg lehet-e.
  // - Ha igen a válasz, akkor minden ennél nagyobb időre is igen a válasz.
  // - Keressük a legkisebbet amire igen a válasz -> bináris keresés a megoldásra.

  ll from = 0; // Min lehetséges idő, ha nincsenek dobozok.
  ll to = accumulate(a.begin(), a.end(), 0ll) + n + 1; // Max idő, pl. ha 1 ember csinál mindent.
  // 0ll = long long típusú 0 numberic literal.
  ll result = binsearch(from, to);
  cout << result << endl;
  return 0;
}
