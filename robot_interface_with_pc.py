import time
import socket
import string
HOST = "192.168.1.75"    # The remote host
PORT = 30002              # The same port as used by the server
print ("Starting Program")

comer=0
B=""
linea1=""
vector="a1a2a3a4a5a6a7a8b1b2b3b4b5b6b7b8c1c2c3c4c5c6c7c8d1d2d3d4d5d6d7d8e1e2e3e4e5e6e7e8f1f2f3f4f5f6f7f8h1h2h3h4h5h6h7h8"
vector1="abcdefgh"
vector2="12345678"
vari=0
varix=0
varixa=0
varip=0
primero=0
segundo=0
tercero=0
cuarto=0
yep=""
yep2=""
vez=[1,2,3,4,5,6,7,8]

##A="o"
casilla=0.051
gab=0
while(1):
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   s.connect((HOST, PORT))
   time.sleep(0.05)
   #s.send (b"movej(p[0.046, 0.642, 0.656, 0.0202, -0.0155, -3.7278], a=0.600 , v=0.30000)")
   #s.send (b"\n")
   time.sleep(3)
   fichero = open("in.txt","r")
   fichero1 = open("out.txt","r")
   linea = fichero.readline()
   #linea1 = fichero1.readline()
   
   
   while linea != "":
      print (linea.rstrip())
      A=linea
      linea = fichero.readline()
      z=linea
      z1= linea1
      print(A[9:11])
      print(A[11:13])
      linea1 = fichero1.readline()
      
      time.sleep(1)
   
   if(A!=B):


     print(A[11:13])
     
     while(vari<8):

        if(A[9:10]==vector1[vari:vari+1]):
           segundo=varip
           #print(vez[varip])
           #print(varip)
           #print(A[9:11])
           #print(vector[vari:vari+2])

        
        if(A[10:11]==vector2[vari:vari+1]):
           primero=varip
           #print(vez[varip])
           #print(varip)
           #print(A[11:13])
           #print(vector[vari:vari+2])
          # print(A[11:13])

        if(A[11:12]==vector1[vari:vari+1]):
           cuarto=varip
           #print(vez[varip])
           #print(varip)
           #print(A[9:11])
           #print(vector[vari:vari+2])

        
        if(A[12:13]==vector2[vari:vari+1]):
           tercero=varip
           #print(vez[varip])
           #print(varip)
           #print(A[11:13])
           #print(vector[vari:vari+2])
          # print(A[11:13])
           

        if (varip==7):
           varip=-1

        varip=varip+1   
        vari=vari+1
       # print(varip)
     vari=0
     varip=0
     print(primero)
     print(segundo)
     print(tercero)
     print(cuarto)
     #cordx1= (primero +1)* casilla
     #cordy1= (segundo +1)* casilla
     #cordx2= (tercero +1)* casilla
     #cordy2= (cuarto +1)* casilla

     cordy1= ((primero +1)* casilla) - casilla + 0.519
     cordx1= ((segundo +1)* casilla) - casilla - 0.130
     cordy2= ((tercero +1)* casilla) - casilla + 0.519
     cordx2= ((cuarto +1)* casilla) - casilla  - 0.130

     #cordy1= ((primero +1)* casilla) - casilla + 0.519
     #cordx1= ((segundo +1)* casilla) - casilla - 0.130
     #cordy2= ((tercero +1)* casilla) - casilla + 0.519
     #cordx2= ((cuarto +1)* casilla) - casilla  - 0.130
     
     fichero2 = open("out1.txt","r")
     gab=0
     comer=0
     uu= ("movej(p[ 0.044, 0.544, 0.17, 2.0362, -2.326, 0.0247], a=0.590000, v=0.60000)")
     s.send(bytes(uu,'utf-8'))
     s.send (b"\n")
     time.sleep(2) 
     while(gab<64):
      
       lineax = fichero2.readline()
       
       if(A[11:13]==lineax[2:4]):
           #s.send (b"movej(p[0.046, 0.642, 0.456, 0.0202, -0.0155, -3.7278], a=0.600 , v=0.30000)")
           #s.send (b"\n")
           #time.sleep(10)
           fichero2.close()
           comer=1
           uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
           s.send(bytes(uu1,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
           uu1= ("movej(p[ %s, %s, 0.0388, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
           s.send(bytes(uu1,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
           #print("hola")
           ur=("set_digital_out(0,True)")
           s.send(bytes(ur,'utf-8'))
           s.send (b"\n")
           time.sleep(1)
           uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
           s.send(bytes(uu1,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
           uu= ("movej(p[ 0.219, 0.704, 0.051, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)")
           s.send(bytes(uu,'utf-8'))
           s.send (b"\n")
           time.sleep(5)
           ur=("set_digital_out(0,False)")
           s.send(bytes(ur,'utf-8'))
           s.send (b"\n")
           time.sleep(1)
           uu= ("movej(p[ %s, %s, 0.067,  2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx1,cordy1))
           s.send(bytes(uu,'utf-8'))
           s.send (b"\n")
           time.sleep(2) 
           uu= ("movej(p[ %s, %s, -0.0168, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx1,cordy1))
           s.send(bytes(uu,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
           ur=("set_digital_out(0,True)")
           s.send(bytes(ur,'utf-8'))
           s.send (b"\n")
           time.sleep(1)
       #activo electrovalvula cierro la garra
           uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx1,cordy1))
           s.send(bytes(uu1,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
           uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
           s.send(bytes(uu1,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
           uu1= ("movej(p[ %s, %s, -0.0168, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
           s.send(bytes(uu1,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
       
           ur=("set_digital_out(0,False)")
           s.send(bytes(ur,'utf-8'))
           s.send (b"\n")
           time.sleep(1)
        #activo electrovalvula abro garra
           uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
           s.send(bytes(uu1,'utf-8'))
           s.send (b"\n")
           time.sleep(2)

           uu= ("movej(p[ 0.319, 0.604, 0.051, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)")
           s.send(bytes(uu,'utf-8'))
           s.send (b"\n")
           time.sleep(5)

           uu= ("movej(p[ 0.319, 0.604, -0.027, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)")
           s.send(bytes(uu,'utf-8'))
           s.send (b"\n")
           time.sleep(2) 

           uu= ("movej(p[ 0.044, 0.544, 0.17, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)")
           s.send(bytes(uu,'utf-8'))
           s.send (b"\n")
           time.sleep(2)
           break
           print(A[11:13])  #aca tengo que mandar la orden al robot para comer
           print(lineax[2:4])
           print(lineax[0:2])
       gab=gab+1     
     fichero2.close()
     #if(A[11:13]==lineax[2:4]):
      #  print(A[11:13])
       # print(lineax[2:4])
     if(comer==0):  
       #s.send (b"movej(p[0.046, 0.642, 0.556, 0.0202, -0.0155, -3.7278], a=0.600 , v=0.30000)")
       #s.send (b"\n")
       #time.sleep(10)
       #s.send (b"movej(p[0.09713, 0.42401, -0.1217,3.0148, -0.7635, -0.0238], a=0.5962634015954636, v=0.471975511965976)" + b"\n")
      
       uu= ("movej(p[ %s, %s, 0.067,  2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx1,cordy1))
       s.send(bytes(uu,'utf-8'))
       s.send (b"\n")
       time.sleep(2) 
       uu= ("movej(p[ %s, %s, -0.0168, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx1,cordy1))
       s.send(bytes(uu,'utf-8'))
       s.send (b"\n")
       time.sleep(2)
       ur=("set_digital_out(0,True)")
       s.send(bytes(ur,'utf-8'))
       s.send (b"\n")
       time.sleep(1)
       #activo electrovalvula cierro la garra
       uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx1,cordy1))
       s.send(bytes(uu1,'utf-8'))
       s.send (b"\n")
       time.sleep(2)
       
       #uux= ("movej(p[ %s, %s, 0.0417, 3.0148, -0.7635, -0.0238], a=0.590000, v=0.60000)"%(cordx1,cordy1))
       #s.send(bytes(uux,'utf-8'))
       #s.send (b"\n")
       #time.sleep(5)

       
       uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
       s.send(bytes(uu1,'utf-8'))
       s.send (b"\n")
       time.sleep(2)
       uu1= ("movej(p[ %s, %s, -0.0168, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
       s.send(bytes(uu1,'utf-8'))
       s.send (b"\n")
       time.sleep(2)
       
       ur=("set_digital_out(0,False)")
       s.send(bytes(ur,'utf-8'))
       s.send (b"\n")
       time.sleep(1)
        #activo electrovalvula abro garra
       uu1= ("movej(p[ %s, %s, 0.067, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)"%(cordx2,cordy2))
       s.send(bytes(uu1,'utf-8'))
       s.send (b"\n")
       time.sleep(2)

       uu= ("movej(p[ 0.319, 0.604, 0.051, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)")
       s.send(bytes(uu,'utf-8'))
       s.send (b"\n")
       time.sleep(5)

       uu= ("movej(p[ 0.319, 0.604, -0.027, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)")
       s.send(bytes(uu,'utf-8'))
       s.send (b"\n")
       time.sleep(2) 

       uu= ("movej(p[ 0.044, 0.544, 0.17, 2.0362, -2.326, 0.0247], a=1.590000, v=1.60000)")
       s.send(bytes(uu,'utf-8'))
       s.send (b"\n")
       time.sleep(2) 
       #s.send (b"movej(p[ %s, %s, -0.1217, 3.0148, -0.7635, -0.0238], a=0.590000, v=0.30000)"%(cordx2,cordy2))
       #s.send (b"\n")
       #time.sleep(15)
       print("xxxxx111aaa")  #esta es la orden al robot solo para moverse
     #print(A)
     #print(z1)

   B=A
   data = s.recv(1024)
   s.close()
