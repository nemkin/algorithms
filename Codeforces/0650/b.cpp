#include <iostream>
using namespace std;

int n,a,b,T;

int result (int p[]):

    int max_to_right = 1
    int t = b[0] + 1;

    if (t>T) return 0;

 
    for(int i=1; i<n; ++i) { 

        t += a + p[i] + 1
  
        if(t>T) {

            t -= (a + p[i] + 1)
            break;
        }
     
        max_to_right += 1
    }

 
    int max_all = max_to_right
    int tleft = 0
    int right_guard = max_to_right - 1

    for(int i=n-1; max_to_right<=i; --i) {

        tleft += a + p[i] + 1
       
        while tleft + tdup > T:

            if right_guard < 1:
                return max_all

            move = a
            if p[right_guard] == 'w':
                rotate = b
            else:
                rotate = 0
            watch = 1

            tdup -=  (2*move + rotate + watch)
            right_guard -= 1

            if tdup < 0:
                return max_all

        current = right_guard + 1 + i + 1        

        if max_all < current:
            max_all = current

    return max_all

n,a,b,T = map(int, input().split())
p = input()

print(max(result(n,a,b,T,p), result(n,a,b,T, p[0] + p[n-1:0:-1])))

