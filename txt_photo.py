import sys


def main():
    namespace = locals()
    with open(sys.argv[1], "r") as f:
        with open("output.txt", "w") as save:
            content = f.read()
            content = content.replace(" ", "")
            convert = [" ", ".", "`", ":", "~", "*", "=", "&", "%", "#"]
            x = 0
            namespace["content_0"] = []
            for ch in content:
                if ch == "\n":
                    x = x + 1
                    namespace["content_" + str(x)] = []
                    save.write("\n")
                    continue
                try:
                    ch = convert[int(ch)]
                except IndexError:
                    raise ValueError
                save.write(ch)
                print(ch, end="")
                namespace["content_" + str(x)].append(ch)
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
