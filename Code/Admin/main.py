import requests

def getcenter(points):
    x, y = zip(*points)
    center = (max(x) + min(x)) / 2., (max(y) + min(y)) / 2.
    return center

Key = "AIzaSyDAPnKQJwXhgqTLznH3JthGhVnrLBuu6p0"
r = requests.get("https://stormpetrel.mybluemix.net/getalert")

data = r.json()

while(True):
    print("Selecione o carro que deseja verificar\n")
    for i in data:
        print(i["_id"])
    placa = input("Digite a Placa do Carro: ")
    for i in data:
        if i["_id"] == placa:
            print("Status de Alerta: ", i["alerta"])
            if i["alerta"] == 1:
                print("Status senha: ", i["senha"]);
            points = [(float(i["cerca_ativa_0_lat"]), float(i["cerca_ativa_0_lon"])), (float(i["cerca_ativa_1_lat"]), float(i["cerca_ativa_1_lon"])), (float(i["cerca_ativa_2_lat"]),float(i["cerca_ativa_2_lon"])), (float(i["cerca_ativa_3_lat"]), float(i["cerca_ativa_3_lon"]))]
            center = getcenter(points)
            print("Cerca Ativa e Localização Atual: ","""https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&markers=size:mid%7Ccolor:0xff0000%7Clabel:%7C{},{}&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(center[0],center[1], i["atual_lat"], i["atual_lon"], i["cerca_ativa_0_lat"], i["cerca_ativa_0_lon"], i["cerca_ativa_1_lat"], i["cerca_ativa_1_lon"], i["cerca_ativa_2_lat"],i["cerca_ativa_2_lon"], i["cerca_ativa_3_lat"], i["cerca_ativa_3_lon"], i["cerca_ativa_0_lat"], i["cerca_ativa_0_lon"], Key))

            points = [(float(i["cerca_1_lat_0"]), float(i["cerca_1_lon_0"])),
                      (float(i["cerca_1_lat_1"]), float(i["cerca_1_lon_1"])),
                      (float(i["cerca_1_lat_2"]), float(i["cerca_1_lon_2"])),
                      (float(i["cerca_1_lat_3"]), float(i["cerca_1_lon_3"]))]
            center = getcenter(points)
            print("Cerca {}: ".format(i["cerca_1"]),
                """https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(
                    center[0], center[1], i["cerca_1_lat_0"],
                    i["cerca_1_lon_0"], i["cerca_1_lat_1"], i["cerca_1_lon_1"], i["cerca_1_lat_2"],
                    i["cerca_1_lon_2"], i["cerca_1_lat_3"], i["cerca_1_lon_3"], i["cerca_1_lat_0"],
                    i["cerca_1_lon_0"], Key))

            points = [(float(i["cerca_2_lat_0"]), float(i["cerca_2_lon_0"])),
                      (float(i["cerca_2_lat_1"]), float(i["cerca_2_lon_1"])),
                      (float(i["cerca_2_lat_2"]), float(i["cerca_2_lon_2"])),
                      (float(i["cerca_2_lat_3"]), float(i["cerca_2_lon_3"]))]
            center = getcenter(points)
            print("Cerca {}: ".format(i["cerca_2"]),
                """https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=12&scale=1&size=640x640&maptype=roadmap&format=png&visual_refresh=true&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(
                    center[0], center[1], i["cerca_2_lat_0"],
                    i["cerca_2_lon_0"], i["cerca_2_lat_1"], i["cerca_2_lon_1"], i["cerca_2_lat_2"],
                    i["cerca_2_lon_2"], i["cerca_2_lat_3"], i["cerca_2_lon_3"], i["cerca_2_lat_0"],
                    i["cerca_2_lon_0"], Key))

            quit()
