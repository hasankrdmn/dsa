def dailyTemperatures(temperatures):
    output = [0] * len(temperatures)
    stack = []
    for index, temperature in enumerate(temperatures):
        while stack and temperature > stack[-1][0]:
            temp, ind = stack.pop()
            output[ind] = index - ind
        stack.append([temperature, index])
    return (output)