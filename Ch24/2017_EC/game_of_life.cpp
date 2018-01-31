#include <iostream>

#include <set>
#include <utility>

#define RUNS 1000000
#define VISUAL 15

using namespace std;

set<pair<long long,long long> > board;

int main() {

board.insert(make_pair( 0 , 23 ));
board.insert(make_pair( 1 , 21 ));
board.insert(make_pair( 1 , 23 ));
board.insert(make_pair( 2 , 12 ));
board.insert(make_pair( 2 , 20 ));
board.insert(make_pair( 2 , 22 ));
board.insert(make_pair( 2 , 34 ));
board.insert(make_pair( 2 , 35 ));
board.insert(make_pair( 3 , 11 ));
board.insert(make_pair( 3 , 12 ));
board.insert(make_pair( 3 , 19 ));
board.insert(make_pair( 3 , 22 ));
board.insert(make_pair( 3 , 34 ));
board.insert(make_pair( 3 , 35 ));
board.insert(make_pair( 4 , 0 ));
board.insert(make_pair( 4 , 1 ));
board.insert(make_pair( 4 , 10 ));
board.insert(make_pair( 4 , 11 ));
board.insert(make_pair( 4 , 16 ));
board.insert(make_pair( 4 , 17 ));
board.insert(make_pair( 4 , 20 ));
board.insert(make_pair( 4 , 22 ));
board.insert(make_pair( 5 , 0 ));
board.insert(make_pair( 5 , 1 ));
board.insert(make_pair( 5 , 9 ));
board.insert(make_pair( 5 , 10 ));
board.insert(make_pair( 5 , 11 ));
board.insert(make_pair( 5 , 16 ));
board.insert(make_pair( 5 , 17 ));
board.insert(make_pair( 5 , 21 ));
board.insert(make_pair( 5 , 23 ));
board.insert(make_pair( 6 , 10 ));
board.insert(make_pair( 6 , 11 ));
board.insert(make_pair( 6 , 16 ));
board.insert(make_pair( 6 , 17 ));
board.insert(make_pair( 6 , 23 ));
board.insert(make_pair( 7 , 11 ));
board.insert(make_pair( 7 , 12 ));
board.insert(make_pair( 8 , 12 ));

   for(int i=0; i<RUNS; ++i) {

        set<pair<long long,long long>> extension;

        /*
        cout<<"New round"<<endl;

        for(long long a = -VISUAL; a<VISUAL; ++a) {

                for(long long b=-VISUAL; b<VISUAL; ++b) {
                    
                        if(board.find(make_pair(a,b)) != board.end()) {

                            cout<<'x';
                            
                        } else {

                            cout<<'.';

                        }

                }

            cout<<endl;

        }
        */
        for(auto pair : board) {

            long long x=pair.first;
            long long y=pair.second;

            long long a,b,count;

            a = x-1;
            b = y;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            
            //if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            ++count;

            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;

            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));
            
            a = x+1;
            b = y;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;


            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));
            
            a = x;
            b = y-1;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;


            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));
            
            a = x;
            b = y+1;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;


            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));
           
            a = x-1;
            b = y-1;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;

            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));

            a = x-1;
            b = y+1;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;

            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));

            a = x+1;
            b = y-1;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;

            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));

            a = x+1;
            b = y+1;

            count = 0;

            if(board.find(make_pair(a-1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b)) != board.end()) ++count;
            if(board.find(make_pair(a,b+1)) != board.end()) ++count;

            if(board.find(make_pair(a+1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b-1)) != board.end()) ++count;
            if(board.find(make_pair(a-1,b+1)) != board.end()) ++count;
            if(board.find(make_pair(a+1,b-1)) != board.end()) ++count;

            if(count==3) extension.insert(make_pair(a,b));
            if(count==2 && board.find(make_pair(a,b)) != board.end()) extension.insert(make_pair(a,b));

        }

        board = extension;

        cout<<fixed<<i/(float)RUNS*100<<"%\r";
    }
    cout<<endl<<endl;
    unsigned long long counter = 0;
    for(auto pair : board) {
       ++counter;
    //   cout<<counter<<".: "<<pair.first<<" "<<pair.second<<endl;
    }
    cout<<"Total: "<<counter<<endl;
    return 0;

}
