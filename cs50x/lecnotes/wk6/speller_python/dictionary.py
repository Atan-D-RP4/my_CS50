# A Python Program to show how powerful it is.
# This program implements the dictionary.c part of PSet 5's Speller

words = set()

def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rsrtip()
        word add(line)
    close(file)
    return True

def size():
    return len(words)

def unload():
    return True