import re
from string import ascii_lowercase

heap = {}


def evaluate(expr):
    global heap

    if expr in ascii_lowercase:
        return heap[expr]

    if re.search(r'(.+) ([+-/*]) (.+)', expr):
        arg1, op, arg2 = re.match(r'(.+) ([+-/*]) (.+)', expr).groups()
        arg1 = evaluate(arg1)
        op = op.replace('/', '//')
        arg2 = evaluate(arg2)
        return eval(str(arg1) + op + str(arg2))

    return int(expr)


def execute(command, i):
    global heap

    if command == 'END':
        return -1

    if command.startswith('PRINT'):
        arg = command.replace('PRINT ', '')
        print(evaluate(arg))
        return i + 1

    if command.startswith('GOTO'):
        arg = command.replace('GOTO ', '')
        return int(arg)

    if command.startswith('IF'):
        # IF command matching shoud NOT be greedy, 
        # as nested IF commands would be overlooked.
        test, cmd = re.match(r'IF (.+?) THEN (.+)', command).groups()
        arg1, comp, arg2 = re.match(r'(.+) ([=<>]) (.+)', test).groups()

        arg1 = evaluate(arg1)
        comp = comp.replace('=', '==')
        arg2 = evaluate(arg2)

        if eval(str(arg1) + comp + str(arg2)):
            return execute(cmd, i)

        return i + 1

    variable, expression = re.match(r'(.+) = (.+)', command).groups()
    heap[variable] = evaluate(expression)
    return i + 1


lines = ['SKIP']
n = int(input())

for _ in range(n):
    new_line = input()
    lines.append(new_line.strip())

i = 1
while True:
    i = execute(lines[i], i)
    if i == -1:
        break
