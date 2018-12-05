import requests
import csv

OUT_FILE = 'alerta.csv'

r = requests.get("https://stormpetrel.mybluemix.net/getalert")

data = r.json()

with open(OUT_FILE, 'w', newline='') as outputfile:
        writer = csv.writer(outputfile, delimiter=',', quotechar='"')
        for i in data:
            row = [i["_id"],i["senha"],i["alerta"]]
            writer.writerow(row)