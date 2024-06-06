from sys import argv
import pyfiglet

def main():
    font = pyfiglet.FigletFont().getFonts()[0]
    if len(argv) > 1:
        if argv[1] == "-f" or argv[1] == "--font":
            if argv[2] in pyfiglet.FigletFont().getFonts():
                font = argv[2]
            else:
                exit(1)
        else:
            exit(1)
    print(argv[0] + " " + argv[1] + " " + argv[2])
    text = input("Enter text to convert to ASCII: ").strip()
    ascii_banner = pyfiglet.figlet_format(text, font=font)
    print(ascii_banner)

if __name__ == "__main__":
    main()
