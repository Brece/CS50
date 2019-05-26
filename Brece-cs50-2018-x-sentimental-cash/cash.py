import cs50

while True:
    print("Change owed: ", end="")
    n = cs50.get_float()
    if n > 0:
        break
    

coins = 0
quarter = 0
dime = 0
nickel = 0
penny = 0

cash = int(100.0 * n)

if cash >= 25:
    coins += (cash//25)
    quarter += (cash//25)
    cash -= 25*(cash//25)
    
if (cash%25) >= 10:
    coins += (cash//10)
    dime += (cash//10)
    cash -= 10*(cash//10)
    
if (cash%10) >= 5:
    coins += (cash//5)
    nickel += (cash//5)
    cash -= 5*(cash//5)
    
if (cash%5) < 5:
    coins += (cash%5)
    penny += (cash%5)
    cash -= (cash%5)
    
print("Coins: " + str(coins))
print("Quarter: " + str(quarter))
print("Dime: " + str(dime))
print("Nickel: " + str(nickel))
print("Penny: " + str(penny))
print("Cash owed: " + str(cash))