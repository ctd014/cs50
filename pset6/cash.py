def main():
    while True:
        change = float(input("Change owed: "))
        if change >= 0:
            break

    change *= 100
    quarters = int(change / 25)
    dimes = int((change % 25) / 10)
    nickels = int(((change % 25) % 10) / 5)
    pennies = int((((change % 25) % 10) % 5))

    coins = quarters + dimes + nickels + pennies
    print(coins)

if __name__ == "__main__":
    main()
