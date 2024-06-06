extensions = { ".gif": "image/gif",
               ".jpg": "image/jpeg",
               ".jpeg": "image/jpeg",
               ".png": "image/png",
               ".txt": "text/plain",
               ".pdf": "application/pdf",
               ".zip": "application/zip",
               ".bin": "application/octet-stream"
             }

def file_type(file: str):
    file = file.strip().lower()
    ext = file[file.rfind("."):]
    if [*file][len(file) - 1] == ext:
        return "application/octet-stream"
    return extensions.get(ext, "Unknown File extension")

def main():
    file = input("Enter the file name: ").strip()
    print(file_type(file))

if __name__ == "__main__":
    main()
