while True:
    try:
        s = input().lower().strip()
        s = s[0].upper() + s[1:]
        if s[-1] not in '.!?':
            s += '.'
        s = s.split()
        if len(s) > 1 and len(s[-1]) == 1:
            res = s[-2] + s[-1]
            print(' '.join(s[:-2]), res, sep=' ')
        else:
            print(' '.join(s))
    except EOFError:
        break