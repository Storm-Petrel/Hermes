import requests
import time


r = requests.get("https://stormpetrel.mybluemix.net/getCar?_id=LNJ4103")
data = r.json()

while data["alerta"] == False:
    print("No aguardo!")
    r = requests.get("https://stormpetrel.mybluemix.net/getCar?_id=LNJ4103")
    data = r.json()
    time.sleep(3)

print("Pegou")