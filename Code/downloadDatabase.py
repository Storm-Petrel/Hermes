import requests
import csv

OUT_FILE = 'db.csv'

r = requests.get("https://stormpetrel.mybluemix.net/getalert")

data = r.json()

with open(OUT_FILE, 'w', newline='') as outputfile:
        writer = csv.writer(outputfile, delimiter=',', quotechar='"')
        for i in data:
            row = [i["_id"],i["atual_lat"],i["atual_lon"],i["cerca_ativa_0_lat"],i["cerca_ativa_0_lon"],i["cerca_ativa_1_lat"],i["cerca_ativa_1_lon"],i["cerca_ativa_2_lat"],i["cerca_ativa_2_lon"],i["cerca_ativa_3_lat"],i["cerca_ativa_3_lon"],i["temporary_time"],i["travel"],i["travel_time"],i["cerca_1"],i["cerca_1_lat_0"],i["cerca_1_lon_0"],i["cerca_1_lat_1"],i["cerca_1_lon_1"],i["cerca_1_lat_2"],i["cerca_1_lon_2"],i["cerca_1_lat_3"],i["cerca_1_lon_3"],i["cerca_2"],i["cerca_2_lat_0"],i["cerca_2_lon_0"],i["cerca_2_lat_1"],i["cerca_2_lon_1"],i["cerca_2_lat_2"],i["cerca_2_lon_2"],i["cerca_2_lat_3"],i["cerca_2_lon_3"],i["alerta"],i["senha"]]
            writer.writerow(row)