
import socket                
s = socket.socket()          
port = 8080              
s.connect(('192.168.43.227', 8080)) 
print(s.recv(1024)) 
s.close()        