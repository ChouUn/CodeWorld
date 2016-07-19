
N = 1010
g = [0, 2, 3]
f = [0, 2, 6]
for i in range(3, N):
    g.append(g[i - 1] + g[i - 2])
    f.append(f[i - 1] * (i + 1))

for i in range(2, N):
    g[i] -= 1
    f[i] -= 1

_ = int(raw_input())
for __ in range(_):
    n = int(raw_input())
    print f[n] / g[n]
