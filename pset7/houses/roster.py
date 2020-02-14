import cs50
import sys
from cs50 import SQL

# get sys.argv using sys module
if len(sys.argv) != 2:
    raise ValueError('Please provide 1 argument')

house = sys.argv[1]

db = SQL("sqlite:///students.db")
d = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ?;", house)
s = sorted(d, key=lambda i: (i['last'], i['first']))
for row in s:
    if row["middle"] == None:
        print(f"{row['first']} {row['last']}, born {row['birth']}")
    else:
        print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")