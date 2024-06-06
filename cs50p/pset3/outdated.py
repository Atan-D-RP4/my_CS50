months = { "January": 1, "February": 2, "March": 3, "April": 4,
           "May": 5, "June": 6, "July": 7, "August": 8,
           "September": 9, "October": 10, "November": 11, "December": 12 }

def main():
    while True:
        input_date = input("Enter a date (mm/dd/yyyy): ").strip()
        if not input_date[0].isdigit():
            if input_date.find(",") == -1:
                continue
            month, day, year = input_date.split(" ")
            month = months.get(month)
            day = int(day.replace(',', ""))
            year = int(year)
            if day < 1 or day > 31 or month is None:
                continue
            print(f"{year:02d}-{month:02d}-{day:02d}")
        else:
            try:
                month, day, year = map(int, input_date.split("/"))
            except ValueError:
                continue
            if month < 1 or month > 12 or day < 1 or day > 31 or year < 0:
                continue
            print(f"{year:02d}-{month:02d}-{day:02d}")
        break

if __name__ == "__main__":
    main()
