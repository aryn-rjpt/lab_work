
# Doesn't work

coins = {1,2,5,10,20,50,100}

def combs(coin):
    
    if coin == 1:
        ansSet.append([1])
        return

    combs(coin-1)

    for i in range(len(ansSet)):
        ansSet[i].append(1)

    if coin in coins:
        ansSet.append([coin])


    return ansSet


ansSet = []
combs(4)
print(ansSet)
