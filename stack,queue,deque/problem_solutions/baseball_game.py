def calPoints(operations) -> int:
    values = []
    for i in operations:
        if i == "+":
            values.append(values[-1] + values[-2])
        elif i == "D":
            values.append(values[-1] * 2)
        elif i == "C":
            values.pop()
        else:
            values.append(int(i))
    return sum(values)
