def main():
    fun = input()
    print(convert(fun))




def convert(inp):
    inp = inp.replace(":)","🙂")
    inp = inp.replace(":(","🙁")
    return inp


main()
