#include <Servo.h> 

int servoPin = 5; 
Servo Servo1;

////MOTORS
#define enA 11
#define in1 10
#define in2 9

#define in3 8
#define in4 7

#define enB 6
 
#define led 12
#define ldr 13

long result = 0;
long temp=0;
int start_bit=0;


int bit1=0;
int bit2=0;
int bit3=0;

// int flag_f=1;
 

void setup() {
  Serial.begin(9600); 
 
  
 pinMode(led,OUTPUT);//LEDS
  
 pinMode(ldr,INPUT);//sensor
 
 
 Servo1.attach(servoPin);


  pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);
}

void forward_motors(void){
 Serial.println("enter forward_motors");
 

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA,120);

digitalWrite(in3,HIGH);
digitalWrite(in4, LOW);
analogWrite(enB,120);
 
}


void back_motors(void){

 Serial.println("back_motors");
 

digitalWrite(in1, LOW);
digitalWrite(in2,HIGH );
analogWrite(enA,120);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enB,12
0);
}

void stop_motors(void){
 
  
Serial.println("stop_motors");
digitalWrite(in1, LOW);
digitalWrite(in3, LOW);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
}

void open_leds(void){

Serial.println("open_leds");

digitalWrite(led,HIGH);

}

void stop_leds(void){

Serial.println("stop_leds");
digitalWrite(led,LOW);

}


void left_servo(){
  Serial.println("servo_left");
  
                  Servo1.write(20);
                 
                       }
                       
void right_servo(void){
  
Serial.println("servo_right");

                       Servo1.write(110);
                      
                       }
                       


  
  

void order(long message){
  switch (message){
    case 001:
      forward_motors();
      break;

      case 010:
      back_motors();
      break;

      case 011:
      stop_motors();
      break;

      case 100:
      open_leds();
      break;

      case 101:
      stop_leds();
      break;

      case 110:
      left_servo();
      break;

      case 111:
      right_servo();
      break;
      
     default:
      Serial.println(binary);
      Serial.println("wrong signal");
      break;}
      
      }
      
     
void loop()
{  

if((start_bit==0) && (digitalRead(ldr)==0))
{delay(120);
start_bit=1;
}

while(start_bit){
  
  bit1=!(digitalRead(ldr));
 delay(80);
  bit2=!(digitalRead(ldr));
 delay(80);
  bit3=!(digitalRead(ldr));
 
  
  start_bit=0;
  }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     



  result = 100*bit1 + 10*bit2 + bit3 ;
  Serial.println(result);
 
  if(temp != result){
  
  order(result);
  Serial.println("result");
 
  temp=result;
 
 
  }
  
  }
