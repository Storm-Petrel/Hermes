import requests
import csv

OUT_FILE = 'pos.csv'

r = requests.get("https://stormpetrel.mybluemix.net/getalert")

data = r.json()

with open(OUT_FILE, 'w', newline='') as outputfile:
        writer = csv.writer(outputfile, delimiter=',', quotechar='"')
        for i in data:
            row = [i["_id"],i["atual_lat"],i["atual_lon"],i["cerca_ativa_0_lat"],i["cerca_ativa_0_lon"],i["cerca_ativa_1_lat"],i["cerca_ativa_1_lon"],i["cerca_ativa_2_lat"],i["cerca_ativa_2_lon"],i["cerca_ativa_3_lat"],i["cerca_ativa_3_lon"],i["temporary_time"],i["travel"],i["senha"],i["travel_time"]]
            writer.writerow(row)