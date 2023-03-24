#include <bits/stdc++.h>
using namespace std;

// Ez egy ritka példa olyan vprog feladatra, ahol ha szép kódot írsz, azzal
// mérhető mennyiségű időt spórolsz. :D

// n*m méretű pálya.
int n, m;

// Így könnyebb beolvasni az n*m méretű 2D karakter tömböt.
// Indexelés szempontjából ugyanolyan, mint egy vector<vector<char>>.
vector<string> field;

// Aktuális (x,y) koordinátáink.
int x=0, y=0;

// Letárolom az irányok betűkódjait. Trükk 1: Ha rájövök hogy cserélve vannak,
// akkor majd megcserélem a változóikat és transzparensen használom őket tovább.
char u='U', d='D', l='L', r='R';

// Mélységi bejáráshoz segédtömb.
vector<vector<bool>> visited;

// Mélységi bejárás közben elmentem a lépéseimet 2 elemű vektorokba,
// (mx, my) koordinátapárokként egy verembe.
stack<vector<int>> moves;

// 2D lépés vektorokat u,d,l,r karakterekre cseréli a kiíráshoz.
char dir(int mx, int my) {
  if(mx==-1) return u;    // (-1,  0) = UP
  if(mx==1) return d;     // ( 1,  0) = DOWN
  if(my==-1) return l;    // ( 0, -1) = LEFT
  /*if(my==1)*/ return r; // ( 0,  1) = RIGHT
}

// Lépek az (mx, my) 2D vektornak megfelelően.
void step(int mx, int my) {
  // Elmentem a korábbi koordinátáimat.
  int prevx=x, prevy=y;
  // Kiadom a parancsot a lépésre.
  cout << dir(mx, my) << endl;
  // Beolvasom és átrakom 0-based indexbe az eredményt.
  cin >> x >> y; --x; --y;
  // - Trükk 2: Hogy fogom észrevenni, hogy valamelyik irányt felcserélték
  //   a játék elején?
  // - Amikor először lépek abba az irányba, akkor "nem sikerül".
  // - Mivel először lépnék abba az irányba, ezért eddig nem léptem
  //   még arra, tehát nem az ellenkező irányba fogok ellépni, hanem
  //   nem fogok elmozdulni, mert fal van mögöttem.
  //   Ez baromi hasznos, mert nem kell azon aggódnom, hogy belehátrálok
  //   egy aknába, a fal biztosan megvéd.
  if (prevx == x && prevy == y) {
    // Ha x irány mentén nem sikerült lépni, akkor cserélni kell u és d betűit.
    if (mx) swap(u, d);
    // Ha y irány mentén nem sikerült lépni, akkor cserélni kell l és r betűit.
    if (my) swap(l, r);
    // Ezek után újra végrehajtom a lépést, ezúttal már a jó parancsot kiadva.
    step(mx, my);
  }
}

// Mélységi bejárással keresek útvonalat a kezdőpontból F-be.
// Trükk 1 és Trükk 2 miatt transzparensen működik minden, ezen
// a ponton már az extra feltételekkel nem kell foglalkozni.
bool dfs(int cx, int cy) {
  // Ha megtaláltuk az F-et visszatérünk.
  if (field[cx][cy] == 'F') return true;
  
  // Egyébként bejárt-ra állítjuk a mezőt.
  visited[cx][cy] = true;

  // Lambda függvény, mert lusta vagyok mx és my 4 lehetséges
  // kombinációjára ugyanazt leírni. [&] azt jelenti hogy referencia
  // szerint capture-öli a cx és cy változókat a befoglaló scope-ból,
  // bár itt érték szerint is lehetne. A lényeg, hogy cx és cy belül
  // elérhető.
  auto move = [&](int mx, int my) -> bool {
    // Széleknél nem lehet kilépni.
    if (cx+mx < 0 || n <= cx+mx) return false;
    if (cy+my < 0 || m <= cy+my) return false;
    // Már bejártra és aknára nem lépünk rá.
    if (visited[cx+mx][cy+my] || field[cx+mx][cy+my] == '*') return false;
    // Ha lehet erre lépni, akkor rekurzívan folytatom a mélységi bejárást.
    if (dfs(cx+mx, cy+my)) {
      // Ha igaz-al tér vissza akkor megtalálta az F-et és a moves
      // globális verem változóba már beletolta a rákövetkező lépéseket,
      // most a tetejére teszem az aktuális lépést és megyek kifele
      // a rekurzióból...
      moves.push(vector<int>{mx, my});
      return true;
    }
    return false;
  };

  // Kihasználom a lazy evaluation-t. Jobbról balra fogja végrehajtani,
  // ha false akkor megy a következőre, de ha az egyik true, azaz
  // abban az irányban megvan a keresett mező akkor nem megy tovább
  // (és nem találja meg másik függeten úton is, összekavarva a 
  // moves verem tartalmát).
  return move(-1, 0) || move(1, 0) || move(0, -1) || move(0, 1);
}

int main() {
  cin >> n >> m;
  field.resize(n);
  visited.resize(n, vector<bool>(m));
  for(int i=0; i<n; ++i) {
    cin >> field[i];
  }

  // Mélységi bejárás a kezdőpontból F-et keresve.
  dfs(0, 0);

  // A moves tartalmát kiolvasom, ez pont jó sorrendet fog adni.
  // A step függvény segítségével végrehajtom.
  // A step függvény hibatűrő és okos, automatikusan javítja az iránykódokat ha kell.
  while(!moves.empty()) {
    auto m = moves.top(); moves.pop();
    step(m[0], m[1]);
  }

  return 0;
}
