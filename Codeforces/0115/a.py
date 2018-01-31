n = int(input())
employees = set(range(n))
managers = {i: int(input())-1 for i in range(n)}

counter = 0

while bool(employees):
   
    employees = set(key for key in managers.keys() if managers[key] in employees)
    counter += 1

print(counter)

