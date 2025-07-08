from collections import deque

for t in range(int(input())):
    xa, ya, xb, yb = map(int, input().split())
    n = int(input())

    point = set()
    for i in range(n):
        x, y1, y2 = map(int, input().split())
        for y in range(y1, y2 + 1):
            point.add((x, y))

    if not (xa, ya) in point or not (xb, yb) in point:
        print(-1)
    else:
        ok = False
        dq = deque([(xa, ya, 0)])

        while len(dq) > 0:
            ux, uy, step = dq.popleft()
            if ux == xb and uy == yb:
                ok = True
                print(step)
                break

            for dx in range(-1, 2):
                for dy in range(-1, 2):
                    ox, oy = ux + dx, uy + dy
                    if (ox, oy) in point:
                        point.remove((ox, oy))
                        dq.append((ox, oy,step + 1))

        if not ok:
            print(-1)
