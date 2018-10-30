import csv
import random

FEED_FILE = 'test.csv'
OUT_FILE = 'test3.csv'


rowcount = 0
r1 = random.randint(0,9)
r2 = random.randint(0,9)
r3 = random.randint(0,9)
r4 = random.randint(0,9)
r5 = random.randint(0,9)
r6 = random.randint(0,9)
r7 = random.randint(0,9)
r8 = random.randint(0,9)
r9 = random.randint(0,9)
r10 = random.randint(0,9)

randomrows = [r1,r2,r3,r4,r5,r6,r7,r8,r9,r10]

with open(OUT_FILE, 'w', newline='') as outputfile:
    with open(FEED_FILE, newline='') as feed:
        writer = csv.writer(outputfile, delimiter=',', quotechar='"')
        reader = csv.reader(feed, delimiter=',', quotechar='"')
        for row in reader:
            if rowcount in randomrows:
                row[1] = "{:.6f}".format(float(row[1])+0.9)
                row[2] = "{:.6f}".format(float(row[2])+0.9)
                row = [row[0],row[1],row[2]]
                writer.writerow(row)
            else:
                row = [row[0],row[1],row[2]]
                writer.writerow(row)
            rowcount = rowcount + 1
