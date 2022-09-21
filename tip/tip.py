def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")

def dollars_to_float(d):
    d1 = d.replace("$", "")
    d2 = float(d1)
    return d2

def percent_to_float(p):
    p1 = float(p.replace("%", ""))
    p2 = p1/100
    return p2

main()