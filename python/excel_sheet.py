def convertToTitle(columnNumber: int) -> str:
    c = columnNumber
    ret = ''
    while c:
        c -= 1
        r = c % 26
        c //= 26
        ret += chr(ord("A") +r)

    return ret[::-1]

if __name__ == "__main__":
    inp = int(input("Enter the colnum: \n"))
    print(f"The column title is '{convertToTitle(inp)}'.")