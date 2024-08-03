def main():
    name = input()
    print(newmethod(name))


def newmethod(inp):
    return inp.replace(' ','...')

main()

