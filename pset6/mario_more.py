from cs50 import get_int

def main():

    """Get a positive integer from the user"""
    while True:
        print("Height: ", end = "")
        n = get_int()
        if n >= 0 and n <= 23:
            break

    """Print out double half pyramid"""
    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end="")
        for k in range(i + 1):
            print("#", end="")
        print("  ", end="")
        for k in range(i + 1):
            print("#", end="")
        print()

if __name__ == "__main__":
    main()
