from itertools import permutations


def compute_coefs(renovation, n):
    coefs = [0] * (n + 1)  # value of coefs[i] means: Xi appears coefs[i] times

    variable_number = {}  # tool_number: assigned_variable_number

    for i in range(1, n+1):
        # in initial order Tool1 at X1 position, Tool2 at X2 position etc
        variable_number[i] = i

    current_tool = renovation[0]

    for tool in renovation[1:]:
        coefs[variable_number[tool]] += 2
        variable_number[current_tool] = variable_number[tool]
        current_tool = tool

    res = 0
    new_coefs = sorted(coefs, reverse=True)

    for i in range(len(new_coefs)):
        res += (i + 1) * new_coefs[i]
    return res


if __name__ == '__main__':
    n, m = map(int, input().split())
    renovation = list(map(int, input().split()))

    ans = compute_coefs(renovation, n)
    print(ans)
