import random, math

def GCD(a, b):
    if a % b == 0:
        return b
    else:
        return GCD(b, a%b)


def Fact_number(N):
    N_2 = pow(N,2)
    while True:
        # 1
        a = random.randint(1,N)

        # 2
        var = GCD(N,a)
        if var > 1:
            return var
        # 3
        r = 0
        temp = pow(a,r) - 1
        while temp % N == 0 and temp < N_2:
            r = r + 1
            temp = pow(a, r) - 1
        if r % 2 == 0:

            # 4
            temp1 = GCD(N, pow(a, r/2) + 1)
            if temp1 > 1:
                return temp1
            temp2 = GCD(N, pow(a, r/2) - 1)
            if temp2 > 1:
                return temp2


print(Fact_number(12))
print(Fact_number(91))
print(Fact_number(143))
print(Fact_number(1859))
print(Fact_number(1737))
print(Fact_number(13843))
print(Fact_number(988027))