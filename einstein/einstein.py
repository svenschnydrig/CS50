def main():

    # Output using our own function
    m = int(input("What's the mass? " ))
    E = calculate(m)
    print(E)

# Create our own function
def calculate(number):
    E = number * 300000000**2
    return E
main()