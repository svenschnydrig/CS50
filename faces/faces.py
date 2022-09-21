def main():

    # Output using our own function
    message = input()
    message = convert(message)
    print(message)

# Create our own function
def convert(string):
    string1 = string.replace(":)", "🙂")
    string2 = string1.replace(":(", "🙁")
    return string2

main()