import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

fromaddr = "[Your email here]"
toaddr = "[To]"
msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "Hermes - Alert!"


bodyt = open("alert.txt", 'r', encoding='utf-8')
body = MIMEText(bodyt.read(), 'html')
msg.attach(body)

#SMTP for gmail
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "[Your Password Here]")
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
bodyt.close()
server.quit()
