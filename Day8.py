ans1 = 0
with open('input.in') as f:
    for line in f:
        wires, output = line.strip().split(' | ')
        output_len = [len(x) for x in output.split()]
        for x in output_len:
            if x in [2,3,4,7]:
                ans1 += 1

ans2 = 0
with open('input.in') as f:
    for line in f:
        wires, output = line.strip().split(' | ')
        wires = wires.split()
        output = output.split()

        displays = {0: '', 1: '', 2: '', 3: '', 4: '', 5: '', 6: '', 7: '', 8: '', 9: ''}
        left_triple = []
        right_triple = []

        for w in wires:
            l = len(w)
            if l == 2: displays[1] = set(w)
            if l == 3: displays[7] = set(w)
            if l == 4: displays[4] = set(w)
            if l == 5: left_triple.append(set(w))
            if l == 6: right_triple.append(set(w))
            if l == 7: displays[8] = set(w)

        for w in right_triple:
            if displays[4].issubset(set(w)): 
                displays[9] = set(w)
            else:
                if displays[7].issubset(set(w)):
                    displays[0] = set(w)
                else:
                    displays[6] = set(w)

        for w in left_triple:
            if displays[7].issubset(set(w)): 
                displays[3] = set(w)
            else:
                if len(set(w).intersection(displays[4])) == 3:
                    displays[5] = set(w)
                else:
                    displays[2] = set(w)

        digits = ''
        for n in output:
            s = set(n)
            for i, key in enumerate(displays.values()):
                if s == key:
                    digits = digits + str(i)
        ans2 += int(digits)


print("Part 1")
print(ans1)
print("Part 2")
print(ans2)