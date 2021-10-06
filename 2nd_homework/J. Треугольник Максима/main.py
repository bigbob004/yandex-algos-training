#4 случая: 1 - closer меньше предыдущего - смещаем правую границу в середину
#          2 - closer больше предыдушего - смещаем левую границу
#          3 - further меньше предыдущего - смещаем левую границу
#          4 - further больше предыдущего - смещаем правую границу
fin = open('input.txt', 'r')

MIN = 30.0
MAX = 4000.0
N = int(fin.readline())
speed1 = float(fin.readline())
for line in fin:
    speed2, status = line.split()
    speed2 = float(speed2)
    if status == "closer":
        if speed2 < speed1 and (speed1 + speed2) / 2 < MAX:
            MAX = (speed1 + speed2) / 2
        elif speed2 > speed1 and (speed1 + speed2) / 2 > MIN:
            MIN = (speed1 + speed2) / 2
    elif status == "further":
        if speed2 < speed1 and (speed1 + speed2) / 2 > MIN:
            MIN = (speed1 + speed2) / 2
        elif speed2 > speed1 and (speed1 + speed2) / 2 < MAX:
            MAX = (speed1 + speed2) / 2
    speed1 = speed2
fin.close()
print(MIN, MAX)
