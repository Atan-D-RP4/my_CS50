import sys
import requests

def main():
    coins = 0
    if len(sys.argv) != 2:
        print("Missing command line argument")
        sys.exit(1)
    else:
        try:
            coins = float(sys.argv[1])
        except ValueError:
            print("Command line argument is not an number")
            sys.exit(1)
    value = coins * get_bitcoin_price()
    # use a comma as thousands separator
    print(f"${value:,.4f}")

def get_bitcoin_price():
    url = "https://api.coindesk.com/v1/bpi/currentprice.json"
    response = requests.get(url)
    response.raise_for_status()
    data = response.json()
    return data["bpi"]["USD"]["rate_float"]

if __name__ == '__main__':
    main()
