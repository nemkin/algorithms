import sys

n, x, y = map(int, input().split())

# Ennyi bitet kell végigkérdezni.
bits = len(bin(n))-2

# Összes lehetséges index.
indexes = list(range(1, n+1))

# Rákérdez azokra az indexekre amiknek a mask bitjeinek a
# helyén a pattern bitmintája van.
# True -> Páratlan sok (1 db) speciális jégcsap van köztük.
# False -> Páros sok (0 vagy 2 db) speciális jégcsap van köztük.
def mask_ask_odd(pattern, mask):
  ask = [i for i in indexes if (i & mask) == (pattern & mask)]
  if not ask:
    return False

  print("?", len(ask), " ".join(map(str, ask)))
  sys.stdout.flush()
  ans = int(input())

  if (ans == y) or (ans == x ^ y):
    return True
  else: # (ans == 0) or (ans == x)
    return False

# Addig kérdezzük a biteket, amíg meg nem találunk egyet
# amire páratlan sok a válasz. Tehát ebben a bitben
# különbözik a két jégcsap indexe.
for curr_bit in range(bits):
  mask = 1 << curr_bit
  if mask_ask_odd(mask, mask):
    diff_bit = curr_bit
    break

# Ettől a ponttól kezdve a diff_bit-et mindig felvesszük a maskokba
# tehát a mask_ask_odd válasza mostmár:
# True -> 1 db speciális jégcsap van köztük.
# False -> 0 db speciális jégcsap van köztük.

# Ezután visszamegyünk és végigkérdezzük újra az azonos biteket,
# vagyis a közös postfixet helyreállítjuk:
postfix = 0
for curr_bit in range(diff_bit):
  # Mask: diff_bit + a curr_bit-ig az összes bit.
  mask = (1 << diff_bit) | ((1 << curr_bit + 1)-1)
  # Pattern: diff_bit = 1 + az aktuálisan kérdezett bit
  # + az eddig helyreállított postfix.
  pattern = (1 << diff_bit) | (1 << curr_bit) | postfix
  if mask_ask_odd(pattern, mask):
    postfix |= (1 << curr_bit)

# A közös postfix megvan, diff_bit-ben különböznek.
# Innentől kezdve egymástól függetlenül állítjuk helyre
# a bitjeiket a speciális jégcsapoknak.
pos1 = postfix
pos2 = (1 << diff_bit) | postfix
for curr_bit in range(diff_bit+1, bits):
  # Mask: curr_bit-ig az összes bit.
  mask = (1 << curr_bit+1)-1
  # Ha a curr_bit nem 0, akkor 1.
  if not mask_ask_odd(pos1, mask):
    pos1 |= (1 << curr_bit)
  # Ha a curr_bit nem 0, akkor 1.
  if not mask_ask_odd(pos2, mask):
    pos2 |= (1 << curr_bit)

print("!", " ".join(map(str, sorted([pos1, pos2]))))
