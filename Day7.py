import statistics

def p1(s: str):
    nums = [int(n) for n in s.replace("\n", "").split(",")]
    alignment = statistics.median(nums)
    return sum([abs(i - alignment) for i in nums])


def p2(s: str):
    nums = [int(n) for n in s.replace("\n", "").split(",")]
    alignment = int(statistics.mean(nums))
    return min(
        sum(abs(i - a) * (abs(i - a) + 1) / 2 for i in nums)
        for a in [alignment, alignment + 1]
    )
    
input = "16,1,2,0,4,2,7,1,2,14"
print(p1(input))
print(p2(input))