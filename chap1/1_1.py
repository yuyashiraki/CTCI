# Check char in a string is unique

data = raw_input()
arr  = [0] * 256
for i in range(len(data)):
    c = int(data[i])
    if arr[c] > 0:
        print "NO"
        exit()
    arr[int(data[i])] = 1
print "YES"
