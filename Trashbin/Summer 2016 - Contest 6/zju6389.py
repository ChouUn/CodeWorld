import json

def dfs(x):
    if isinstance(x, list):
        res = '['
        # print x, len(x)
        for i in range(len(x)):
            # print i
            if i != 0:
                res += ','
            res += dfs(x[i])
        res += ']'
        return res
    elif isinstance(x, dict):
        y = x.keys()
        y.sort()
        res = '{'
        # print y, len(y)
        for i in range(len(y)):
            # print i, y[i]
            if i != 0:
                res += ','
            res += '"' + str(y[i]) + '":'
            res += dfs(x[y[i]])
        res += '}'
        return res
    else:
        return '"' + str(x) + '"'

_ = int(raw_input())
for __ in range(_):
    origin = json.loads(raw_input())
    n = int(raw_input())
    for i in range(n):
        op = str(raw_input()).replace('\r', '').replace('\n', '').split(' ')
        # print op
        
        b = op[1]
        for i in ('.', '[', ']'):
            b = b.replace(i, ' ')
        b = b.split(' ')
        while '' in b: 
            b.remove('')
        # print b
        
        t = origin
        for i in range(len(b) - 1):
            if isinstance(t, list):
                t = t[int(b[i])]
            else:
                t = t[str(b[i])]
            
        if op[0] == 'SET':
            c = json.loads(op[2])
            t[b[-1]] = c
        else:
            if t.has_key(b[-1]):
                del t[b[-1]]
    
    # target = json.dumps(origin).replace(' ', '')
    print dfs(origin)
    