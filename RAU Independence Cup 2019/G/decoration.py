from collections import Counter


n, p = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

# n, p = [6, 3]
# arr = [1, 2, 1, 2, 3, 4]


# n, p = [14, 3]
# arr = [3, 4, 1, 1, 1, 2, 3, 1, 2, 1, 1, 5, 6, 7]


def main():
    counter = Counter(arr)
    res = 0

    while True:
        most_common_keys_and_values = counter.most_common(p)
        if len(most_common_keys_and_values) == p and all([value > 0 for key, value in most_common_keys_and_values]):
            res += 1
            for key, value in most_common_keys_and_values:
                if value == 1:
                    del counter[key]
                else:
                    counter[key] = value - 1

        else:
            break
    print(res)
    return res


if __name__ == '__main__':
    main()
