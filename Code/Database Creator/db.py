import couchdb
import csv

couch = couchdb.Server("https://b1cd6a2b-b7a5-444a-8110-4a10b399f9b1-bluemix:14025bd4e581ffdaa78a6ad998a5a5f03000a6c832c69f59fc212685f4bfa301@b1cd6a2b-b7a5-444a-8110-4a10b399f9b1-bluemix.cloudant.com")
db = couch['teste']

csvfile = open('cars2.csv', 'r')

fieldnames = ("_id","atual_lat","atual_lon","cerca_ativa_0_lat","cerca_ativa_0_lon","cerca_ativa_1_lat","cerca_ativa_1_lon","cerca_ativa_2_lat","cerca_ativa_2_lon","cerca_ativa_3_lat","cerca_ativa_3_lon","travel","travel_time")
reader = csv.DictReader(csvfile, fieldnames)
for row in reader:
    if db.get(row["_id"]) == None:
       db.save(row)
