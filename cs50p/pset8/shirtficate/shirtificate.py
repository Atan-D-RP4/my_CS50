import fpdf
from PIL import Image, ImageDraw, ImageOps

def main():
    name = input("Name: ").strip()
    text1 = "CS50 Shirtificate"
    text2 = f"{name} took CS50"

    try:
        shirt = Image.open("shirtificate.png")
    except:
        print("Error: shirtificate.png not found")
        return

    # Move the shirt below to make space for "CS50 Shirtificate" text
    shirt = ImageOps.expand(shirt, (0, 100))

    # Draw the name on the shirt
    draw = ImageDraw.Draw(shirt)
    # draw larger text
    draw.text((250, 100), text1, fill="black")
    draw.text((225, 300), text2, fill="white")

    # Save the shirtificate as pdf
    shirt.save("shirtificate(1).png")
    pdf = fpdf.FPDF()
    pdf.add_page()
    pdf.image("shirtificate(1).png", x=10, y=10, w=190)
    pdf.output("shirtificate.pdf")


if __name__ == "__main__":
    main()
