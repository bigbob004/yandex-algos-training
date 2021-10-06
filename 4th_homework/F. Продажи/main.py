f = open('input.txt', 'r')
data = {}
for line in f:
    name, product, count = line.split()
    count = int(count)
    if name not in data:
        data[name] = {product: count}
    elif product not in data[name]:
        data[name][product] = count
    else:
        data[name][product] += count
for customer in sorted(data.keys()):
    print(customer, ':', sep='')
    for product in sorted(data[customer].keys()):
        print(product, data[customer][product])
f.close()
