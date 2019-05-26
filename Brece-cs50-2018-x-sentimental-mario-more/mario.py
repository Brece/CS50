import cs50

# promt user input for "height"
while True:
    print("Height: ", end="")
    n = cs50.get_int()
    if n in range(24):
        break

# i limits the amount of spaces and hashtags in each row
i = 1

for row in range(n):

    print(" " * (n - i) + "#" * i + "  " + "#" * i)
    i += 1