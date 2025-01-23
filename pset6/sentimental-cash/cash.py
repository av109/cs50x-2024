from cs50 import get_float
coins = 0
n = 0
while (n <= 0):
    n = get_float("change: ")

n = round(n * 100, 0)


while (n > 0):
    if (n >= 25):
        n -= 25
        coins += 1
    elif (n >= 10):
        n -= 10
        coins += 1
    elif (n >= 5):
        n -= 5
        coins += 1
    else:
        n -= 1
        coins += 1

print(coins)
