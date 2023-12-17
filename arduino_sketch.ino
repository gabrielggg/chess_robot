#include<SPI.h>
//#include<LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 8, d5 = 5, d6 = 6, d7 = 7;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//DATA PIN:11, CLOCK PIN:13, FSYNC PIN:4
#define FSYNC 4

#define AMUX 7
#define AMUX2 3
#define AMUX3 2
#define OUTDEMUX A0
//#define OUTDEMUX2 A6


#define WAVE_SINE     0x2000
#define WAVE_SQUARE   0x2028
#define WAVE_TRIANGLE 0x2002

//#define b_UP    A0
//#define b_DOWN  A1
//#define b_MULTI A2
//#define b_FUNC  A3

long int counter = 50; 
long int counter_ant = 0;
long int function = 0;
long int function_ant = 0;
int multi = 0;
int contador = 0;
int contador2 = 0;
int contador3= 0;
int contador4 = 0;
int func = 0;
int func_ant = 0;
int val = 0;
int val_vacio = 0;
int val_vacio2 = 0;
int val_vacio3 = 0;
int val_vacio4 = 0;
int val_vacio5 = 0;
int val_vacio6 = 0;
int val_vacio7 = 0;
int val_vacio8 = 0;
int val_vacio_color = 0;
int val_vacio2_color = 0;
int val_vacio3_color = 0;
int val_vacio4_color = 0;
int val_vacio5_color = 0;
int val_vacio6_color = 0;
int val_vacio7_color = 0;
int val_vacio8_color = 0;
String stringOne, stringTwo, stringThree, stringFour;

void AD9833setup(){
   pinMode(FSYNC, OUTPUT);
   digitalWrite(FSYNC, HIGH);
   SPI.begin();
   delay(5); 
   AD9833reset();
}

void AD9833reset(){
   WriteRegister(0x100);
   delay(10);
   //WriteRegister(0x2000);
}

void AD9833setFrequency(long frequency, int Waveform){
   long FreqWord = (frequency * pow(2, 28)) / 25.0E6;
   int MSB = (int)((FreqWord & 0xFFFC000) >> 14);
   int LSB = (int)(FreqWord & 0x3FFF);
   LSB |= 0x4000;
   MSB |= 0x4000; 
   WriteRegister(0x2100);   
   WriteRegister(LSB);
   WriteRegister(MSB);
   WriteRegister(0xC000);
   WriteRegister(Waveform);
}

void WriteRegister(int dat){ 
   SPI.setDataMode(SPI_MODE2);        
   digitalWrite(FSYNC, LOW);
   delayMicroseconds(10); 
   SPI.transfer(dat>>8);
   SPI.transfer(dat&0xFF);
   digitalWrite(FSYNC, HIGH);
   SPI.setDataMode(SPI_MODE0);
}

void setup(){
   Serial.begin(9600);
   AD9833setup();
   //pinMode(b_UP, INPUT_PULLUP);
   //pinMode(b_DOWN,INPUT_PULLUP);
   //pinMode(b_MULTI,INPUT_PULLUP);
   //pinMode(b_FUNC,INPUT_PULLUP);
   //pinMode(OUTDEMUX,INPUT_PULLUP);
   pinMode(7, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(2, OUTPUT);
   //pinMode(12, OUTPUT);
   AD9833setFrequency(10050, 0x2000);
   //AD9833setFrequency(5000, 0x2000);
   //lcd.begin(16, 2);
   //lcd.clear();
   //delay(7000);
   //////////////////////ESCAQUE 1////////////////////////////////////////////////

   digitalWrite(7, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(2, HIGH);
   delay(50);
   val_vacio = analogRead(OUTDEMUX); //posiblemente podemos hacer multiples lecturas del val vacio aquí y promediar para sacar un val vacio correcto
   //////////////////////ESCAQUE 2////////////////////////////////////////////////

   digitalWrite(7, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(2, HIGH);
   delay(50);
   val_vacio2 = analogRead(OUTDEMUX);

   //////////////////////ESCAQUE 3////////////////////////////////////////////////

   digitalWrite(7, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH);
   delay(50);
   val_vacio3 = analogRead(OUTDEMUX);

   //////////////////////ESCAQUE 4////////////////////////////////////////////////

   digitalWrite(7, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH);
   delay(50);
   val_vacio4 = analogRead(OUTDEMUX);

   //////////////////////ESCAQUE 5////////////////////////////////////////////////

   digitalWrite(7, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(2, LOW);
   delay(50);
   val_vacio5 = analogRead(OUTDEMUX);

   //////////////////////ESCAQUE 6////////////////////////////////////////////////

   digitalWrite(7, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(2, LOW);
   delay(50);
   val_vacio6 = analogRead(OUTDEMUX);

   //////////////////////ESCAQUE 7////////////////////////////////////////////////

   digitalWrite(7, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
   delay(50);
   val_vacio7 = analogRead(OUTDEMUX);

   //////////////////////ESCAQUE 8////////////////////////////////////////////////

   digitalWrite(7, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
   delay(50);
   val_vacio8 = analogRead(OUTDEMUX);
  

   

}



void loop(){ 

      //////////////////////ESCAQUE 1////////////////////////////////////////////////
      //delay(25);
      digitalWrite(7, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      delay(15);
      delayMicroseconds(10); 
      
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio - val_vacio*0.05) && val <= (val_vacio + val_vacio*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador > 500){
            //val_vacio = val;
            contador = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador++;
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println(val_vacio_color);
          Serial.println("vacio1");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio - val_vacio*0.32)-(val_vacio - val_vacio*0.32)*0.05) && val <= ((val_vacio - val_vacio*0.28)+(val_vacio - val_vacio*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println("peon1");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio - val_vacio*0.10)-(val_vacio - val_vacio*0.10)*0.05) && val <= ((val_vacio - val_vacio*0.10)+(val_vacio - val_vacio*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println("torre1");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio + val_vacio*0.23)-(val_vacio + val_vacio*0.23)*0.05) && val <= ((val_vacio + val_vacio*0.33)+(val_vacio + val_vacio*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println("caballo1");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio + val_vacio*0.056)-(val_vacio + val_vacio*0.056)*0.03) && val <= ((val_vacio + val_vacio*0.056)+(val_vacio + val_vacio*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println("dama1");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio + val_vacio*0.09)-(val_vacio + val_vacio*0.09)*0.05) && val <= ((val_vacio + val_vacio*0.09)+(val_vacio + val_vacio*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println("alfil1");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio - val_vacio*0.198)-(val_vacio - val_vacio*0.198)*0.05) && val <= ((val_vacio - val_vacio*0.198)+(val_vacio - val_vacio*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println("rey1");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio);
          Serial.println("unknown - B1");
      }

      //////////////////////ESCAQUE 2////////////////////////////////////////////////
      //delay(25);
      //delay(5);
      digitalWrite(7, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(2, HIGH);
      delay(15);
      delayMicroseconds(10); 
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio2 - val_vacio2*0.05) && val <= (val_vacio2 + val_vacio2*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador2 > 500){
            //val_vacio2 = val;
            contador2 = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador2++;
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println(val_vacio2_color);
          Serial.println("vacio2");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio2 - val_vacio2*0.32)-(val_vacio2 - val_vacio2*0.32)*0.05) && val <= ((val_vacio2 - val_vacio2*0.28)+(val_vacio2 - val_vacio2*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println("peon2");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio2 - val_vacio2*0.10)-(val_vacio2 - val_vacio2*0.10)*0.05) && val <= ((val_vacio2 - val_vacio2*0.10)+(val_vacio2 - val_vacio2*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println("torre2");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio2 + val_vacio2*0.23)-(val_vacio2 + val_vacio2*0.23)*0.05) && val <= ((val_vacio2 + val_vacio2*0.33)+(val_vacio2 + val_vacio2*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println("caballo2");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio2 + val_vacio2*0.056)-(val_vacio2 + val_vacio2*0.056)*0.03) && val <= ((val_vacio2 + val_vacio2*0.056)+(val_vacio2 + val_vacio2*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println("dama2");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio2 + val_vacio2*0.09)-(val_vacio2 + val_vacio2*0.09)*0.05) && val <= ((val_vacio2 + val_vacio2*0.09)+(val_vacio2 + val_vacio2*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println("alfil2");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio2 - val_vacio2*0.198)-(val_vacio2 - val_vacio2*0.198)*0.05) && val <= ((val_vacio2 - val_vacio2*0.198)+(val_vacio2 - val_vacio2*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println("rey2");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio2);
          Serial.println("unknown - B2");
      }

      //////////////////////ESCAQUE 3////////////////////////////////////////////////
      //delay(25);
      //delay(5);
      digitalWrite(7, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH);
      delay(15);
      delayMicroseconds(10); 
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio3 - val_vacio3*0.05) && val <= (val_vacio3 + val_vacio3*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador3 > 500){
            //val_vacio3 = val;
            contador3 = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador3++;
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println(val_vacio3_color);
          Serial.println("vacio3");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio3 - val_vacio3*0.32)-(val_vacio3 - val_vacio3*0.32)*0.05) && val <= ((val_vacio3 - val_vacio3*0.28)+(val_vacio3 - val_vacio3*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println("peon3");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio3 - val_vacio3*0.10)-(val_vacio3 - val_vacio3*0.10)*0.05) && val <= ((val_vacio3 - val_vacio3*0.10)+(val_vacio3 - val_vacio3*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println("torre3");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio3 + val_vacio3*0.23)-(val_vacio3 + val_vacio3*0.23)*0.05) && val <= ((val_vacio3 + val_vacio3*0.33)+(val_vacio3 + val_vacio3*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println("caballo3");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio3 + val_vacio3*0.056)-(val_vacio3 + val_vacio3*0.056)*0.03) && val <= ((val_vacio3 + val_vacio3*0.056)+(val_vacio3 + val_vacio3*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println("dama3");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio3 + val_vacio3*0.09)-(val_vacio3 + val_vacio3*0.09)*0.05) && val <= ((val_vacio3 + val_vacio3*0.09)+(val_vacio3 + val_vacio3*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println("alfil3");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio3 - val_vacio3*0.198)-(val_vacio3 - val_vacio3*0.198)*0.05) && val <= ((val_vacio3 - val_vacio3*0.198)+(val_vacio3 - val_vacio3*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println("rey3");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio3);
          Serial.println("unknown - B3");
      }

      //////////////////////ESCAQUE 4////////////////////////////////////////////////
      //delay(25);
      //delay(5);
      digitalWrite(7, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, HIGH);
      delay(15);
      delayMicroseconds(10); 
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio4 - val_vacio4*0.05) && val <= (val_vacio4 + val_vacio4*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador4 > 500){
            //val_vacio4 = val;
            contador4 = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador4++;
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println(val_vacio4_color);
          Serial.println("vacio4");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio4 - val_vacio4*0.32)-(val_vacio4 - val_vacio4*0.32)*0.05) && val <= ((val_vacio4 - val_vacio4*0.28)+(val_vacio4 - val_vacio4*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println("peon4");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio4 - val_vacio4*0.10)-(val_vacio4 - val_vacio4*0.10)*0.05) && val <= ((val_vacio4 - val_vacio4*0.10)+(val_vacio4 - val_vacio4*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println("torre4");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio4 + val_vacio4*0.23)-(val_vacio4 + val_vacio4*0.23)*0.05) && val <= ((val_vacio4 + val_vacio4*0.33)+(val_vacio4 + val_vacio4*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println("caballo4");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio4 + val_vacio4*0.056)-(val_vacio4 + val_vacio4*0.056)*0.03) && val <= ((val_vacio4 + val_vacio4*0.056)+(val_vacio4 + val_vacio4*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println("dama4");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio4 + val_vacio4*0.09)-(val_vacio4 + val_vacio4*0.09)*0.05) && val <= ((val_vacio4 + val_vacio4*0.09)+(val_vacio4 + val_vacio4*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println("alfil4");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio4 - val_vacio4*0.198)-(val_vacio4 - val_vacio4*0.198)*0.05) && val <= ((val_vacio4 - val_vacio4*0.198)+(val_vacio4 - val_vacio4*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println("rey4");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio4);
          Serial.println("unknown - B4");
      }

      //////////////////////ESCAQUE 5////////////////////////////////////////////////
      //delay(25);
      //delay(5);
      digitalWrite(7, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(2, LOW);
      delay(15);
      delayMicroseconds(10); 
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio5 - val_vacio5*0.05) && val <= (val_vacio5 + val_vacio5*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador4 > 500){
            //val_vacio4 = val;
            contador4 = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador4++;
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println(val_vacio4_color);
          Serial.println("vacio5");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio5 - val_vacio5*0.32)-(val_vacio5 - val_vacio5*0.32)*0.05) && val <= ((val_vacio5 - val_vacio5*0.28)+(val_vacio5 - val_vacio5*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println("peon5");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio5 - val_vacio5*0.10)-(val_vacio5 - val_vacio5*0.10)*0.05) && val <= ((val_vacio5 - val_vacio5*0.10)+(val_vacio5 - val_vacio5*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println("torre5");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio5 + val_vacio5*0.23)-(val_vacio5 + val_vacio5*0.23)*0.05) && val <= ((val_vacio5 + val_vacio5*0.33)+(val_vacio5 + val_vacio5*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println("caballo5");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio5 + val_vacio5*0.056)-(val_vacio5 + val_vacio5*0.056)*0.03) && val <= ((val_vacio5 + val_vacio5*0.056)+(val_vacio5 + val_vacio5*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println("dama5");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio5 + val_vacio5*0.09)-(val_vacio5 + val_vacio5*0.09)*0.05) && val <= ((val_vacio5 + val_vacio5*0.09)+(val_vacio5 + val_vacio5*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println("alfil5");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio5 - val_vacio5*0.198)-(val_vacio5 - val_vacio5*0.198)*0.05) && val <= ((val_vacio5 - val_vacio5*0.198)+(val_vacio5 - val_vacio5*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println("rey5");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio5);
          Serial.println("unknown - B5");
      }

      //////////////////////ESCAQUE 6////////////////////////////////////////////////
      //delay(25);
      //delay(5);
      digitalWrite(7, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(2, LOW);
      delay(15);
      delayMicroseconds(10); 
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio6 - val_vacio6*0.05) && val <= (val_vacio6 + val_vacio6*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador4 > 500){
            //val_vacio6 = val;
            contador4 = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador4++;
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println(val_vacio6_color);
          Serial.println("vacio6");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio6 - val_vacio6*0.32)-(val_vacio6 - val_vacio6*0.32)*0.05) && val <= ((val_vacio6 - val_vacio6*0.28)+(val_vacio6 - val_vacio6*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println("peon6");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio6 - val_vacio6*0.10)-(val_vacio6 - val_vacio6*0.10)*0.05) && val <= ((val_vacio6 - val_vacio6*0.10)+(val_vacio6 - val_vacio6*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println("torre6");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio6 + val_vacio6*0.23)-(val_vacio6 + val_vacio6*0.23)*0.05) && val <= ((val_vacio6 + val_vacio6*0.33)+(val_vacio6 + val_vacio6*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println("caballo6");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio6 + val_vacio6*0.056)-(val_vacio6 + val_vacio6*0.056)*0.03) && val <= ((val_vacio6 + val_vacio6*0.056)+(val_vacio6 + val_vacio6*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println("dama6");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio6 + val_vacio6*0.09)-(val_vacio6 + val_vacio6*0.09)*0.05) && val <= ((val_vacio6 + val_vacio6*0.09)+(val_vacio6 + val_vacio6*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println("alfil6");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio6 - val_vacio6*0.198)-(val_vacio6 - val_vacio6*0.198)*0.05) && val <= ((val_vacio6 - val_vacio6*0.198)+(val_vacio6 - val_vacio6*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println("rey6");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio6);
          Serial.println("unknown - B6");
      }

      //////////////////////ESCAQUE 7////////////////////////////////////////////////
      //delay(25);
      //delay(5);
      digitalWrite(7, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
      delay(15);
      delayMicroseconds(10); 
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio7 - val_vacio7*0.05) && val <= (val_vacio7 + val_vacio7*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador4 > 500){
            //val_vacio7 = val;
            contador4 = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador4++;
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println(val_vacio7_color);
          Serial.println("vacio7");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio7 - val_vacio7*0.32)-(val_vacio7 - val_vacio7*0.32)*0.05) && val <= ((val_vacio7 - val_vacio7*0.28)+(val_vacio7 - val_vacio7*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println("peon7");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio7 - val_vacio7*0.10)-(val_vacio7 - val_vacio7*0.10)*0.05) && val <= ((val_vacio7 - val_vacio7*0.10)+(val_vacio7 - val_vacio7*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println("torre7");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio7 + val_vacio7*0.23)-(val_vacio7 + val_vacio7*0.23)*0.05) && val <= ((val_vacio7 + val_vacio7*0.33)+(val_vacio7 + val_vacio7*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println("caballo7");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio7 + val_vacio7*0.056)-(val_vacio7 + val_vacio7*0.056)*0.03) && val <= ((val_vacio7 + val_vacio7*0.056)+(val_vacio7 + val_vacio7*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println("dama7");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio7 + val_vacio7*0.09)-(val_vacio7 + val_vacio7*0.09)*0.05) && val <= ((val_vacio7 + val_vacio7*0.09)+(val_vacio7 + val_vacio7*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println("alfil7");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio7 - val_vacio7*0.198)-(val_vacio7 - val_vacio7*0.198)*0.05) && val <= ((val_vacio7 - val_vacio7*0.198)+(val_vacio7 - val_vacio7*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println("rey7");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio7);
          Serial.println("unknown - B7");
      }

      //////////////////////ESCAQUE 8////////////////////////////////////////////////
      //delay(25);
      //delay(5);
      digitalWrite(7, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
      delay(15);
      delayMicroseconds(10); 
      val = analogRead(OUTDEMUX);
      //AD9833reset();
      //lcd.clear();
      if (val >= (val_vacio8 - val_vacio8*0.05) && val <= (val_vacio8 + val_vacio8*0.05)){
          //Serial.println("escaque vacio - B1");
          //Serial.println(val);
          if (contador4 > 500){
            //val_vacio8 = val;
            contador4 = 0;
            Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
          }
          contador4++;
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println(val_vacio8_color);
          Serial.println("vacio8");
          //lcd.setCursor(0, 0);
          //lcd.print("vacio");
      } else if (val >= ((val_vacio8 - val_vacio8*0.32)-(val_vacio8 - val_vacio8*0.32)*0.05) && val <= ((val_vacio8 - val_vacio8*0.28)+(val_vacio8 - val_vacio8*0.28)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println("peon8");
          //lcd.setCursor(0, 0);
          //lcd.print("peon");
      } else if (val >= ((val_vacio8 - val_vacio8*0.10)-(val_vacio8 - val_vacio8*0.10)*0.05) && val <= ((val_vacio8 - val_vacio8*0.10)+(val_vacio8 - val_vacio8*0.10)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println("torre8");
          //lcd.setCursor(0, 0);
          //lcd.print("torre");
      } else if (val >= ((val_vacio8 + val_vacio8*0.23)-(val_vacio8 + val_vacio8*0.23)*0.05) && val <= ((val_vacio8 + val_vacio8*0.33)+(val_vacio8 + val_vacio8*0.33)*0.05)){
          //Serial.println("caballo - B");
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println("caballo8");
          //lcd.setCursor(0, 0);
          //lcd.print("caballo");
      } else if (val >= ((val_vacio8 + val_vacio8*0.056)-(val_vacio8 + val_vacio8*0.056)*0.03) && val <= ((val_vacio8 + val_vacio8*0.056)+(val_vacio8 + val_vacio8*0.056)*0.03)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println("dama8");
          //lcd.setCursor(0, 0);
          //lcd.print("dama");
      } else if (val >= ((val_vacio8 + val_vacio8*0.09)-(val_vacio8 + val_vacio8*0.09)*0.05) && val <= ((val_vacio8 + val_vacio8*0.09)+(val_vacio8 + val_vacio8*0.09)*0.05)){
          //Serial.println("alfil - B");
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println("alfil8");
          //lcd.setCursor(0, 0);
          //lcd.print("alfil");
      }  else if (val >= ((val_vacio8 - val_vacio8*0.198)-(val_vacio8 - val_vacio8*0.198)*0.05) && val <= ((val_vacio8 - val_vacio8*0.198)+(val_vacio8 - val_vacio8*0.198)*0.05)){
          //Serial.println("peon - B");
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println("rey8");
          //lcd.setCursor(0, 0);
          //lcd.print("rey");
      }  else {
          
          Serial.println(val);
          Serial.println(val_vacio8);
          Serial.println("unknown - B8");
      }


   
}
