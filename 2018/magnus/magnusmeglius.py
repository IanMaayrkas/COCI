line = input()


def comecusu():
    check = 0
    count = 0
    for c in line:
        if c == "HONI"[check]:
            check += 1
            if check == 4:
                check = 0
                count += 1
    print(count)


def tricky():
    check = 0
    for c in line:
        check += (c == "HONI"[check % 4])
    count = check // 4
    # likely actually slower
    print(count)


def iknowregex():
    """E invece col cazzo, non le so."""
    import re  # ma se lo fai davvero non importare dentro a funzioni pls
    honi = re.compile("H.*?O.*?N.*?I")
    count = len(honi.findall(line))  # matcherà qualunque cosa malissimo e piangerai
    print(count)

