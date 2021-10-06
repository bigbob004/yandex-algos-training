def deposit(accounts, name, sum):
    if name not in accounts:
        accounts[name] = 0
    accounts[name] += sum


def withdraw(accounts, name, sum):
    if name not in accounts:
        accounts[name] = 0
    accounts[name] -= sum


def balance(accounts, name):
    if name not in accounts:
        print('ERROR')
    else:
        print(accounts[name])


def transfer(accounts, name1, name2, sum):
    if name1 not in accounts:
        accounts[name1] = 0
    if name2 not in accounts:
        accounts[name2] = 0
    accounts[name1] -= sum
    accounts[name2] += sum


def income(accounts, p):
    for key in accounts:
        if accounts[key] > 0:
            accounts[key] *= (100 + p)
            accounts[key] //= 100


bank_accounts = {}
f = open('input.txt', 'r')
for line in f:
    data_of_request = line.split()
    if data_of_request[0] == 'DEPOSIT':
        deposit(bank_accounts, data_of_request[1], int(data_of_request[2]))
    elif data_of_request[0] == 'WITHDRAW':
        withdraw(bank_accounts, data_of_request[1], int(data_of_request[2]))
    elif data_of_request[0] == 'BALANCE':
        balance(bank_accounts, data_of_request[1])
    elif data_of_request[0] == 'TRANSFER':
        transfer(bank_accounts, data_of_request[1], data_of_request[2], int(data_of_request[3]))
    else:
        income(bank_accounts, int(data_of_request[1]))
