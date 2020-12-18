import csv
import sys

# Main Function

def main():
    # User Input

    if len(sys.argv) < 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()

    dnalist = []
    header = exportheader()

    # Open Sequence File

    with open(sys.argv[2], 'r') as sequence:
        seq = sequence.read()
        for i in header:
            dnacount(i, seq, dnalist)

    cast_to_string(dnalist)

    # Open Database File

    with open(sys.argv[1], 'r') as data:
        database = csv.reader(data, delimiter =",")
        compare_list(database, dnalist)

# DNA Successive Counter Function

def dnacount(dnatype, seq, dnalist):
    dnalist.append(0)
    for i in range(len(seq)):
        if seq[i:i+len(dnatype)] == dnatype:
            counter = 0
            for j in range(0, len(seq), len(dnatype)):
                if seq[i+j:i+j+len(dnatype)] == dnatype:
                    counter += 1
                elif counter > dnalist[-1]:
                    dnalist[-1] = counter
                    break
                else:
                    break

# Cast List from Integer to String for Comparison

def cast_to_string(dnalist):
    for i in range(len(dnalist)):
        dnalist[i] = str(dnalist[i])

# Identify Name

def compare_list(database, dnalist):
    for row in database:
        if dnalist == row[1:]:
            print(row[0])
            return
    print("No match.")

# Export Header DNA

def exportheader():
    newheader = []
    with open(sys.argv[1], 'r') as data:
        database = csv.reader(data, delimiter = ",")
        datalist = list(database)
        selectrow = datalist[0]
        newheader = selectrow[1:len(selectrow)]
        return newheader

main()