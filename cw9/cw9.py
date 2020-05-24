import random
import math

def d2(a, b):
    if a == 1  and b == 2:
        return 1
    if a == 9 and b == 10:
        return 1
    if a > b:
        return d(b, a)

    return pow(a, 3) + pow(b, 3) - pow(a, 2) * b - a * pow(b, 2) + 4 * pow(a, 2) - 4 * pow(b, 2) + 4 * a + 4 * b + 1

def d(a, b):
    if a == 1  and b == 10:
        return 1
    if a == 10 and b == 1:
        return 1
    return abs(a-b)

def E(S, l):
    sum = 0
    if l == 1:
        sum = d(S[0], (S[1])) + d(S[1], (S[2])) + d(S[2], (S[3]))
        sum = sum + d(S[3], (S[4])) + d(S[4], (S[5])) + d(S[5], (S[6]))
        sum = sum + d(S[6], (S[7])) + d(S[7], (S[8])) + d(S[8], (S[9]))
        sum = sum + d(S[9], (S[1]))
    else:
        sum = d2(S[0], (S[1])) + d2(S[1], (S[2])) + d2(S[2], (S[3]))
        sum = sum + d2(S[3], (S[4])) + d2(S[4], (S[5])) + d2(S[5], (S[6]))
        sum = sum + d2(S[6], (S[7])) + d2(S[7], (S[8])) + d2(S[8], (S[9]))
        sum = sum + d2(S[9], (S[1]))
    return sum

def fun(DE, T):
    temp = DE / T
    temp = temp * -1
    return math.exp(temp)

def fun_T(T, time):
    temp = math.log(time + 1)
    temp = temp + 1
    return T/temp

S = random.sample(range(1, 11), 10)
S_save = S[:]
print(S)

T = 5
L = 3
M = 100
accepted = 1000
time = 0

while accepted >= L:
    accepted = 0
    generated = 0
    while generated < M:
        index = random.sample(range(1, 11), 2)
        temp1 = index[0] - 1
        temp2 = index[1] - 1
        S_p = S[:]
        temp3 = S_p[temp1]
        S_p[temp1] = S_p[temp2]
        S_p[temp2] = temp3
        DE = E(S_p, 1) - E(S, 1)
        if DE < 0 or random.random() < fun(DE, T):
            S = S_p
            accepted = accepted + 1
        generated = generated + 1
    T = fun_T(T, time)
    time = time + 1

print(S,E(S, 1))

S = S_save
T = 10
L = 3
M = 100
accepted = 1000
time = 0

while accepted >= L:
    accepted = 0
    generated = 0
    while generated < M:
        index = random.sample(range(1, 11), 2)
        temp1 = index[0] - 1
        temp2 = index[1] - 1
        S_p = S[:]
        temp3 = S_p[temp1]
        S_p[temp1] = S_p[temp2]
        S_p[temp2] = temp3
        DE = E(S_p,2) - E(S,2)
        if DE < 0 or random.random() < fun(DE, T):
            S = S_p
            accepted = accepted + 1
        generated = generated + 1
    T = fun_T(T, time)
    time = time + 1

print(S,E(S, 2))