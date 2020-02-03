import cs50
import sys
import csv


# get sys.argv using sys module
if len(sys.argv) != 3:
    raise ValueError('Please provide 2 arguments')

data = sys.argv[1]
sequence = sys.argv[2]
csvData = 0
result = ""
# open DNA sequence
s = open(sequence)
sequence = s.read()

# open csv file - reader & DictReader
with open(data) as csvDataFile:
    csvData = csv.reader(csvDataFile)
    line = 0
    matches = []
    for row in csvData:
        # go through each STR
        if line == 0:
            col = 0
            for shortSeq in row:
                if col > 0:
                    match = 0
                    highest = 0
                    i = 0
                    last = False
                    while (i < len(sequence) - len(shortSeq)):
                        if sequence[i:(i+len(shortSeq))] == shortSeq:
                            i = i + len(shortSeq)
                            if last == False:
                                match = 1
                            else:
                                match = match + 1
                            last = True
                        else:
                            last = False
                            i = i + 1
                        if match > highest:
                            highest = match
                    matches.append(highest)
                col = col + 1
        # compare STR counts against each row of CSV file
        if line > 0:
            col = 0
            match = True
            for column in row:
                if col > 0:
                    if (int(column) != int(matches[col-1])):
                        match = False
                col = col + 1
            if(match):
                result = row[0]
        line = line + 1
# print out match if there is one else NO MATCH
if result == "":
    print("No match")
else:
    print(result)
s.close()