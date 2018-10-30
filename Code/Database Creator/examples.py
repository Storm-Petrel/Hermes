import csv
from faker import Faker

fake = Faker()


for x in range(0, 10):
    placa = fake.pystr(min_chars=3, max_chars=3).upper() + str(fake.pydecimal(left_digits=1, right_digits=1, positive=True)) + str(fake.pydecimal(left_digits=1, right_digits=1, positive=True))
    placa = placa.replace(".","")
    atualLat = str(fake.geo_coordinate(center=-8.059845, radius=0.001))
    atualLon = str(fake.geo_coordinate(center=-34.905552, radius=0.001))
    geo0Lat = str(fake.geo_coordinate(center=-8.021154, radius=0.001))
    geo0Lon = str(fake.geo_coordinate(center=-34.933909, radius=0.001))
    geo1Lat = str(fake.geo_coordinate(center=-8.027868, radius=0.001))
    geo1Lon = str(fake.geo_coordinate(center=-34.852109, radius=0.001))
    geo2Lat = str(fake.geo_coordinate(center=-8.122738, radius=0.001))
    geo2Lon = str(fake.geo_coordinate(center=-34.874526, radius=0.001))
    geo3Lat = str(fake.geo_coordinate(center=-8.052431, radius=0.001))
    geo3Lon = str(fake.geo_coordinate(center=-34.959744, radius=0.001))

    csvRow = [placa,atualLat,atualLon,geo0Lat,geo0Lon,geo1Lat,geo1Lon,geo2Lat,geo2Lon,geo3Lat,geo3Lon,"0","0"]

    with open('cars.csv', 'a', newline='\n') as csvfile:
        spamwriter = csv.writer(csvfile, delimiter=',',quotechar='|',quoting=csv.QUOTE_MINIMAL)
        spamwriter.writerow(csvRow)
