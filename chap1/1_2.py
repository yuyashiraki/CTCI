# Check Permutation

str1 = raw_input()
str2 = raw_input()
arr  = [0] * 256
for i in range(len(str1)):
    c = int(str1[i])
    arr[c] += 1
for i in range(len(str2)):
    c = int(str2[i])
    if not arr[c]:
        print "NO"
        exit()
    arr[c] -= 1
print "YES"
