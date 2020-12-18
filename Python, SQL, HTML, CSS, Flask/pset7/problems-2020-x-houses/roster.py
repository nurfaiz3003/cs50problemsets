from cs50 import SQL
import sys

if len(sys.argv) < 2:
    print("Usage: python roster.py Gryffindor")
    sys.exit()

db = SQL("sqlite:///students.db")
students = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", sys.argv[1])
for i in students:
    if i['middle'] == None:
        print(i['first'] + " " + i['last'] + ", born " + str(i['birth']))
    else:
        print(i['first'] + " " + i['middle'] + " " + i['last'] + ", born " + str(i['birth']))