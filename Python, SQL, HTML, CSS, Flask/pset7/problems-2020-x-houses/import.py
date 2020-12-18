from cs50 import SQL
import csv
import sys

db = SQL("sqlite:///students.db")

if len(sys.argv) < 2:
    print("Usage: python import.py characters.csv")
    sys.exit()

with open(sys.argv[1], 'r') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    for row in reader:
        if len(row[0].split()) < 2:
            continue
        elif len(row[0].split()) < 3:
            name = row[0].split()
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (:a, :b, :c, :d, :e)",
                       {"a": name[0], "b": None, "c": name[1], "d": row[1], "e": row[2]})
        else:
            name = row[0].split()
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (:a, :b, :c, :d, :e)",
                       {"a": name[0], "b": name[1], "c": name[2], "d": row[1], "e": row[2]})