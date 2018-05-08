# chess_robot


Demo Video : https://youtu.be/ExlPP1K_MaI

This project was implemented with Universal Robot UR5 but it can be implemented with any robot.

STEPS:

1) Build a chess board with sensors. Here you can check how to build it https://sites.google.com/site/bergersprojects/reedcb/ .

Here you can see the circuit diagram for the board simulation on proteus:

![alt text](https://github.com/gabrielggg/chess_robot/blob/master/img/sensory_board.png)

2) Once you have the board make sure you can comunicate it with a computer you can use any protocoll but for this project i used rs-232 (serial) and i used the USB port of my computer with a USB-to-Serial Bridge connected to my PIC (tx rx) (you can buy this from amazon).
The idea here is to process all the 64 outputs from sensors which are going to be (1 or 0) so you need to process all this data on the microcontroller and send it encoded in a way that can be decoded later on the PC with the c# snippet. i used a pic and 4 Multiplexers to be able to use less ports of the microcontroller. 

Here is the circuit diagram on proteus to ilustrate my words

Microcontroller with RS-232 interface in reality this should go to the serial port on computer and be processed by the c# snippet.
For the simulation i used a serial port emulator like on the image

![alt text](https://github.com/gabrielggg/chess_robot/blob/master/img/microcontroller.png)

Multiplexer 1 is sensing a1,a2,a3,a4,a5,a6,a7,a8,b1,b2,b3,b4,b5,b6,b7,b8 squares and sending them to microcontroller on port RB7

![alt text](https://github.com/gabrielggg/chess_robot/blob/master/img/mux1.png)

Multiplexer 2 is sensing c1,c2,c3,c4,c5,c6,c7,c8,d1,d2,d3,d4,d5,d6,d7,d8 squares and sending them to microcontroller on port RB6

![alt text](https://github.com/gabrielggg/chess_robot/blob/master/img/mux2.png)

Multiplexer 3 is sensing e1,e2,e3,e4,e5,e6,e7,e8,f1,f2,f3,f4,f5,f6,f7,f8 squares and sending them to microcontroller on port RB5

![alt text](https://github.com/gabrielggg/chess_robot/blob/master/img/mux3.png)

Multiplexer 4 is sensing g1,g2,g3,g4,g5,g6,g7,g8,h1,h2,h3,h4,h5,h6,h7,h8 squares and sending them to microcontroller on port RD0

![alt text](https://github.com/gabrielggg/chess_robot/blob/master/img/mux4.png)

Note: I done this part using CCS compiler.

3) You need to process the data coming from the serial port so i used c# snippet to do this and then this data is consumed by the python api.

4) Download a chess engine and set it up to interact with a text file. Detailed instructions : https://sites.google.com/site/therajendraadhikari/publications/chess-playing-robot/interfacing-matlab-with-chess-engine/step-by-step-guide-for-interfacing-chess-engine-with-matlab

5) Build an API that interacts with it in my case i used python to code the middleware.

6) Finally you connect your robot and your PC to the network and comunicate both via python sockets.

If you have any doubt you can contact me at gabriel.gomezdelatorre@hotmail.com





  
  
