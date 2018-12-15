import sys


if __name__=='__main__':
    line = sys.stdin.readline()
    check = 0
    count = 0
    for i in range(len(line)):
        if check == 0:
            if line[i] == 'H':
                check = 1
        elif check == 1:
            if line[i] == 'O':
                check = 2
        elif check == 2:
            if line[i] == 'N':
                check = 3
        elif check == 3:
            if line[i] == 'I':
                check =0
                count += 1
    print(count)
