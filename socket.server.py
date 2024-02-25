import socket

HOST = 'raspberrypi'
PORT = 1333
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('Socket created')

# managing error exeption
try:
    s.bind((HOST, PORT))
except:
    print('Bind failed')
    
s.listen(1)
print('Socket awaiting messages')
(conn, addr) = s.accept()
print('Connected')

# awaiting for message
while True:
    data = conn.recv(1024)
    print(data)
    
conn.close()