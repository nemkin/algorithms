#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define IN "A.IN"
#define N 160000

using namespace std;

typedef struct ember {
    string azon;
    string nev;
    int pontok;
    bool filled;
} ember;
ember emberek[N];

bool cmp (ember a, ember b) {
    if(!a.filled) return false;
    if(!b.filled) return true;
    if(a.pontok>b.pontok)  return true;
    if(a.pontok==b.pontok) return a.nev.compare(b.nev) == -1;

    return false;
}
int main() {

    int n, i;
    int azonint;
    char be, kihagas[20];
    string azon;
    string nev;

    ifstream file(IN);
    file >> n;

    for (int i = 0; i<n;i++) {
        file >> azon;
        file.get();
        azonint = atoi(azon.c_str());
        getline(file,nev);

        emberek[azonint-1].azon = azon;
        emberek[azonint-1].nev = nev;

        emberek[azonint-1].filled = true;
    }
    cout<<"TADA"<<endl;
    while(!file.eof()) {
        kihagas[0] = file.get();
        if(!iswspace(kihagas[0])) {
            break;
        }
        file.peek();
    }
    cout<<"TADA"<<endl;
    i=1;
    while(!file.eof()) {
        be = file.get();
        if(iswspace(be)) {
            kihagas[i] = '\0';
                if(kihagas[0] == '+') {
                    kihagas[0] = '0';
                    azonint = atoi(kihagas);
                    emberek[azonint-1].pontok+=5;
                } else {
                    azonint = atoi(kihagas);
                    emberek[azonint-1].pontok+=1;
                }
            i=0;
        } else {
            kihagas[i++] = be;
        }
        file.peek();
    }
    cout<<"TADA"<<endl;
    kihagas[i] = '\0';
    if(!iswspace(be)) {
        if(kihagas[0] == '+') {
                    kihagas[0] = '0';
                    azonint = atoi(kihagas);
                    emberek[azonint-1].pontok+=5;
                } else {
                    azonint = atoi(kihagas);
                    emberek[azonint-1].pontok+=1;
                }

    }

    int corrupt = 0;
    for(i=0; i<N; i++) {
        if(emberek[i].filled && 0<emberek[i].pontok) corrupt++;
    }

    sort(emberek, emberek+n*sizeof(ember), cmp);



    cout<<"Honest: "<<n-corrupt<<" persons, ";
    printf("%.2f%%\n", (n-corrupt)/(double)n*100);
    cout<<"Corrupt: "<<corrupt<<" persons, ";
    printf("%.2f%%\n", (corrupt)/(double)n*100);
    cout<<"Champions of corruption:"<<endl;
    int pontfajta = 0;
    int pont = emberek[0].pontok;
    for(int i=0; i<N; i++) {

       if(emberek[i].filled) {
            if(emberek[i].pontok != pont) pontfajta++;
            if(pontfajta<=2) {
            cout<<emberek[i].azon<<" "<<emberek[i].nev<<", "<<emberek[i].pontok<<" points"<<endl;
            }
       }
    }
    return 0;
}
