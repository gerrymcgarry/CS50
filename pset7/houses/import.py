import cs50
import sys
import csv
from cs50 import SQL
# Check command line arguments

# get sys.argv using sys module
if len(sys.argv) != 2:
    raise ValueError('Please provide 1 argument')

characters = sys.argv[1]

# TODO
open("students.db", "w").close()
db = SQL("sqlite:///students.db")
db.execute("CREATE TABLE students(first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")
# Open CSV file given by command line arguments
with open(characters) as csvDataFile:
    csvData = csv.reader(csvDataFile)
    # For each row, parse name
    line = 0
    for row in csvData:
        # Insert each student into students table of students.db
        if line == 0:
            print(row)

        else:
            name = row[0].split()
            first_name = name[0]
            last_name = ""
            middle_name = None
            house = row[1]
            birth = row[2]

            if (len(name) == 2):
                last_name = name[1]
            elif(len(name) == 3):
                middle_name = name[1]
                last_name = name[2]
            print(f"{first_name} | {middle_name} | {last_name} | {house} | {birth} ")
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)",
                       first_name, middle_name, last_name, house, birth)
        line = line + 1