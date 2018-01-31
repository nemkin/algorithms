#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>


#define IN "I.IN"


using namespace std;

int main() {

    int n, kezdo;
    int ma[3];
    int szn[3];

    string line;
    ifstream file(IN);
    file >>n;
    getline(file, line);



    for (int i = 0; i<n; i++) {
        getline(file, line);
        getline(file, line);
        ma[0] = atoi(line.substr(0, 2).c_str());
        ma[1] = atoi(line.substr(3, 2).c_str());
        ma[2] = atoi(line.substr(6, 4).c_str());
        getline(file, line);
        szn[0] = atoi(line.substr(0, 2).c_str());
        szn[1] = atoi(line.substr(3, 2).c_str());
        szn[2] = atoi(line.substr(6, 4).c_str());


        if (ma[2] < szn[2]){
            cout<<"Case #" << i+1<<": Invalid birth date"<<endl;
        } else if (ma[2] == szn[2]){
            if (ma[1] < szn[1]){
                cout<<"Case #" << i+1<<": Invalid birth date"<<endl;
            } else if (ma[1] == szn[1]){
                if (ma[0] < szn[0]){
                    cout<<"Case #" << i+1<<": Invalid birth date"<<endl;
                } else if (ma[0] == szn[0]){
                    cout<<"Case #" << i+1<<": 0"<<endl;
                } else if (ma[0] > szn[0]){
                    cout<<"Case #" << i+1<<": 0"<<endl;
                }
            } else if (ma[1] > szn[1]){
                cout<<"Case #" << i+1<<": 0"<<endl;
            }
        } else if (ma[2] > szn[2]){
            int ev = ma[2] - szn[2];
            if (ma[1] < szn[1]){
                ev = ev-1;
            } else if (ma[1] == szn[1]){
                if (ma[0] < szn[0]){
                    ev = ev-1;
                }
            }
            if (ev <= 130) cout<<"Case #" << i+1<<": "<<ev<<endl;
            else cout<<"Case #" << i+1<<": Check birth date"<<endl;
        }
    }



    return 0;
}
