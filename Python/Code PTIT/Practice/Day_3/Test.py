import math
from itertools import combinations


def dist_squared(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2


def is_point_inside_circle(cx, cy, r, point):
    return dist_squared((cx, cy), point) < r ** 2


def circle_from_points(p1, p2, p3):
    A = p1[0] * (p2[1] - p3[1]) - p1[1] * (p2[0] - p3[0]) + p2[0] * p3[1] - p3[0] * p2[1]
    if A == 0:
        return None
    B = (p1[0] ** 2 + p1[1] ** 2) * (p3[1] - p2[1]) + (p2[0] ** 2 + p2[1] ** 2) * (p1[1] - p3[1]) + (
            p3[0] ** 2 + p3[1] ** 2) * (p2[1] - p1[1])
    C = (p1[0] ** 2 + p1[1] ** 2) * (p2[0] - p3[0]) + (p2[0] ** 2 + p2[1] ** 2) * (p3[0] - p1[0]) + (
            p3[0] ** 2 + p3[1] ** 2) * (p1[0] - p2[0])
    D = (p1[0] ** 2 + p1[1] ** 2) * (p3[0] * p2[1] - p2[0] * p3[1]) + (p2[0] ** 2 + p2[1] ** 2) * (
            p1[0] * p3[1] - p3[0] * p1[1]) + (p3[0] ** 2 + p3[1] ** 2) * (p2[0] * p1[1] - p1[0] * p2[1])

    cx = -B / (2 * A)
    cy = -C / (2 * A)
    r_square = B ** 2 + C ** 2 - 4 * A * D

    if r_square <= 0:
        return None

    r = math.sqrt(r_square) / (2 * abs(A))

    return (cx, cy, r)


def solve(points, K):
    n = len(points)

    for p1, p2, p3 in combinations(points, 3):
        circle = circle_from_points(p1, p2, p3)
        if circle:
            cx, cy, r = circle
            inside_count = 0

            for p in points:
                if p not in [p1, p2, p3] and is_point_inside_circle(cx, cy, r, p):
                    inside_count += 1

            if inside_count == K:
                return "YES"
            else:
                return "NO"
        else:
            return "NO"

    return "NO"


def main():
    T = int(input())
    results = []

    for _ in range(T):
        N = int(input())
        K = int(input())

        points = []
        for _ in range(N):
            x, y = map(int, input().split())
            points.append((x, y))

        result = solve(points, K)
        results.append(result)

    for result in results:
        print(result)


if __name__ == "__main__":
    main()
