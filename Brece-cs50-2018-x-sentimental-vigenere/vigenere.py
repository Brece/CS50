import sys
import cs50


# check for proper usage and key argument value
if len(sys.argv) != 2:
    print("Usage: python <program> <key>")
    sys.exit(1)

key = str(sys.argv[1])

if key.isalpha() == False:
    print("<key> argument must consist on letters only")
    sys.exit(1)


# get user input
print("plaintext: ", end="")
text = cs50.get_string()

print("ciphertext: ", end="")


# index for key-letter increases by one if the the char in plaintext is alphabetic
m = 0

# loop for each char in plaintext
for c in text:

    # index in string <key>
    j = m % len(key)

    # convert char in <key> to ascii number
    k = ord(key[j].lower()) - 97

    # if char in plaintext is alphabetic
    if c.isalpha():

        if c.islower():
            print(chr((((ord(c) - 97) + k) % 26) + 97), end="")

        else:
            print(chr((((ord(c) - 65) + k) % 26) + 65), end="")

        m += 1

    else:
        print(c, end="")
        
print("")