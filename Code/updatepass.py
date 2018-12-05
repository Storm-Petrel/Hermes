import sys
import requests

placa= sys.argv[1]
print(placa)
a = "https://stormpetrel.mybluemix.net/getSenha?_id="+placa+"&_senha=aguardando" 

r = requests.get(a)