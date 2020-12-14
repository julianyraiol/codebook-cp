accounts = [[2,8,7],[7,1,3],[1,9,5]]

value_max = 0
for bank in accounts:
    value_max = max(sum(bank), value_max)


print(value_max)