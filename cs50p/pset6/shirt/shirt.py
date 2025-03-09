from PIL import Image, ImageOps
from sys import argv, exit

def main():
    if len(argv) != 3:
        print("Too few or too many arguments")
        exit(1)

    file_path = argv[1]
    if not file_path.endswith(".jpg"):
        print("File must be a jpg file")
        exit(1)

    output_path = argv[2]
    if not output_path.endswith(".jpg"):
        print("Output file must be a jpg file")
        exit(1)
    if output_path == file_path:
        print("Output file must be different from input file")
        exit(1)
    # create output file if it doesn't exist

    try:
        shirt = Image.open("shirt.png", "r")
        before_file = Image.open(file_path, "r")
    except FileNotFoundError:
        print("File not found")
        exit(1)

    with Image.open(file_path, "r") as before_file:
        before_file = ImageOps.fit(before_file, shirt.size)
        before_file.paste(shirt, shirt)
        before_file.save(output_path, "JPEG")

if __name__ == '__main__':
    main()
