import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

fromaddr = "hermes.alerta@gmail.com"
toaddr = "hermes.central.seguranca@gmail.com"
msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "Alerta!"

bodyt = open("alert.txt", 'r', encoding='utf-8')
body = MIMEText(bodyt.read(), 'html')
msg.attach(body)

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "!C3S@R!S")
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
bodyt.close()
server.quit()
