import sys


def main():
    namespace = locals()
    f = open(sys.argv[1], "r")
    save = open("output.txt", "w")
    content = f.read()
    content = content.replace(" ", "")
    y = 0
    x = 0
    namespace["content_0"] = []
    for ch in content:
        if ch == "\n":
            x = x + 1
            y = 0
            namespace["content_" + str(x)] = []
            save.write("\n")
            continue
        ch = convert_char(ch)
        save.write(ch)
        print(ch, end="")
        namespace["content_" + str(x)].append(ch)
        y = y + 1
    f.close()
    save.close()
    return 0


def convert_char(character):
    if character == '0':
        return " "
    elif character == "1":
        return "."
    elif character == '2':
        return "`"
    elif character == '3':
        return ":"
    elif character == '4':
        return "~"
    elif character == '5':
        return "*"
    elif character == '6':
        return "="
    elif character == '7':
        return "&"
    elif character == '8':
        return "%"
    elif character == '9':
        return "#"
    else:
        raise OSError


if __name__ == "__main__":
    try:
        main()
    except IndexError:
        print("please enter parameter!\n")
        exit(2)
    except FileNotFoundError:
        print("file not found!\n")
        exit(3)











