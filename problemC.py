# // First, let’s line up our 10 prisoners and label them. Also label the wine bottles 0–999 so we can tell them apart.

# // Let’s have Prisoner A drink from every other bottle starting with the first bottle, bottle #0. In other words, Prisoner
# //  A will drink from bottles 0, 2, 4, … Next, assign Prisoner B the task of drinking from every other set of two bottles. For example,
# //  Prisoner B drinks from bottles 0 and 1, skips 2 and 3. Drinks from 4 and 5, skips 6 and 7, and so forth continuing the pattern.
# // Before we decode the result, we need to flip our prisoners around so that it matches the binary place-value system.

# # // There we go. Now suppose all the prisoners are poisoned? Which bottle of wine was it?
# // Well it must have been the first bottle, bottle #0, since this is the only bottle that they all drank from.
# // This is confirmed in our diagram because if they are all poisoned, we place a zero above every prisoner. And 0000000000 in binary is still 0 in decimal.
# // Translate the number 0101010101 into decimal to determine which bottle it was.and
# // Hence, the poisonous bottle's number will be counted.


import bikash as bk

def poisonousWine(numofBottles, prisonernum):
    if numofBottles > 2 ** prisonernum:
        print("No any way to save the King.")
        return
    
    prisoner = dict()
    for i in range(prisonernum):
        label = chr(ord('A') + i)
        prisoner[label] = [0] * numofBottles
        j = 0
        while j < numofBottles:
            
            l = j + 2 ** i
            l = l if l < numofBottles else numofBottles
            for x in range(j, l):
                prisoner[label][x] = 1
                
            j = 2 * l
    return(prisoner)

data = bk.DataFrame(poisonousWine(1000, 10))
data.to_csv('final1.csv')

