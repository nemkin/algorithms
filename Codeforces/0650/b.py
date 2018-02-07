def result (n,a,b,T,p):

    t = 0
    tdup = 0

    move = 0
    if p[0] == 'w':
        rotate = b
    else:
        rotate = 0
    watch = 1

    if t + move > T or t + move + rotate > T or t + move + rotate + watch > T:
        return 0

    t += move + rotate + watch
    tdup += 2*move + rotate + watch

    max_to_right = 1
 
    for i,o in enumerate(p):
        
        if i==0:
            continue

        move = a
        if o == 'w':
            rotate = b
        else:
            rotate = 0
        watch = 1

        if t + move > T or t + move + rotate > T or t + move + rotate + watch > T:
            break
        
        max_to_right += 1
        t += move + rotate + watch
        tdup+= 2*move + rotate + watch
    
    max_all = max_to_right
    tleft = 0
    right_guard = max_to_right - 1

    for i,o in enumerate(reversed(p[max_to_right:])):

        move = a
        if o == 'w':
            rotate = b
        else:
            rotate = 0
        watch = 1
        
        tleft += move + rotate + watch
       
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

