# In a list of 1...10...0 returns the last 1's position.
def binary_range_search(size, index):

    items = [1]*(index+1) + [0]*(size-index-1)

    first = 0
    last = len(items)-1

    while first<last:

        # Rounding upwards.    
        midpoint = first + (last - first)//2 + (last-first)%2
    
        if items[midpoint]:
            first = midpoint
        else:
            last = midpoint-1

    print(first)
    return first

# In a list of 1...10...0 returns the first 0's position.
def binary_range_search_downwards(size, index):

    items = [1]*(index+1) + [0]*(size-index-1)

    first = 0
    last = len(items)

    while first<last:

        # Rounding downwards.    
        midpoint = first + (last - first)//2
    
        if items[midpoint]:
            first = midpoint+1
        else:
            last = midpoint

    print(first)
    return first

# For binary item search it does not matter if we round the middlepoint up or down.
def binary_item_search(size, item):

    print("Binary item search")

    items = list(range(size))
    print(items)

    first = 0
    last = len(items)-1

    while first<last:
    
        midpoint = first + (last - first)//2 + (last-first)%2
    
        print(items)
        print(first, midpoint, last)
        print("")

        if items[midpoint] == item:
            first = midpoint
            last = midpoint
        elif items[midpoint] < item:
            first = midpoint+1
        else:
            last = midpoint-1

    print("Result:")
    print(first, last)
   
def binary_item_search_downwards(size, item):

    print("Binary item search")

    items = list(range(size))
    print(items)

    first = 0
    last = len(items)-1

    while first<last:
    
        midpoint = first + (last - first)//2
    
        print(items)
        print(first, midpoint, last)
        print("")

        if items[midpoint] == item:
            first = midpoint
            last = midpoint
        elif items[midpoint] < item:
            first = midpoint+1
        else:
            last = midpoint-1

    print("Result:")
    print(first, last)

   
range_or_item = bool(input("Range or item? "))
print("Range" if range_or_item else "Item")
size = int(input("Size? "))
index = int(input("Index? "))

binary_range_search_downwards(size, index) if range_or_item else binary_item_search(size, index)

