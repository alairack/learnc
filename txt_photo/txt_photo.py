import sys


def main():
    with open(sys.argv[1], "r") as f:
        with open("output.txt", "w") as save:
            content = f.read()
            content = content.replace(" ", "")
            convert = [" ", ".", "`", ":", "~", "*", "=", "&", "%", "#"]
            for ch in content:
                if ch != "\n":
                    ch = convert[int(ch)]
                save.write(ch)
                print(ch, end="")
    return 0


if __name__ == "__main__":
    try:
        main()
    except IndexError:
        print("please enter parameter!\n")
        exit(2)
    except FileNotFoundError:
        print("file not found!\n")
        exit(3)
    except ValueError:
        print("the numbers in file is unsupported!\n")
        exit(4)
