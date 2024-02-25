import socket

HOST = '192.168.0.106'
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
    
    # process data
    clean_data = data.decode().strip()
    print(clean_data)
    
conn.close()