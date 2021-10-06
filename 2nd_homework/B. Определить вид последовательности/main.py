def is_there_one_sign(signs):
    if signs["ASCENDING"] != 0 and signs["DESCENDING"] != 0:
        return "RANDOM"
    if signs["CONSTANT"]:
        if signs["ASCENDING"]:
            return "WEAKLY ASCENDING"
        if signs["DESCENDING"]:
            return "WEAKLY DESCENDING"
        return "CONSTANT"
    if signs["ASCENDING"]:
        return "ASCENDING"
    return "DESCENDING"


signs = {"CONSTANT": False,
         "ASCENDING": False,
         "DESCENDING": False,
         }


cur = int(input())
next = int(input())


while next != -2e9:
    if next > cur:
        signs["ASCENDING"] = True
    elif next < cur:
        signs["DESCENDING"] = True
    else:
        signs["CONSTANT"] += True
    cur = next
    next = int(input())


print(is_there_one_sign(signs))
