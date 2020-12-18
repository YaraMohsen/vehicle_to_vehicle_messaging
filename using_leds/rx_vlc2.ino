#include <Servo.h> 

int servoPin = 5; 
Servo Servo1;

////MOTORS
#define in1 7
#define in2 8
#define in3 9
#define in4 10
#define ldr 13
#define enA 11
#define enB 6
#define left 2
#define right 3


 long result = 0;
long temp=0;
int start_bit=0;


int bit1=0;
int bit2=0;
int bit3=0;

 int flag_f=0;
 int test=0;

void setup() {
  Serial.begin(9600); 
 
  pinMode(A0,INPUT);
   pinMode(12,OUTPUT);//LEDS
  
 pinMode(ldr,INPUT);//sensor
 
 
 Servo1.attach(servoPin);

 ///MOTORS &SEN2
 pinMode(left,INPUT);
pinMode(right,INPUT);

  pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);
 
}

int back_motors(void){
  //test =digitalRead(ldr);
 // Serial.println(test );
 Serial.println("test_enter back ward_motors");
  analogWrite(enA,180);
 analogWrite(enB,180);
/*
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3,HIGH);
digitalWrite(in4, LOW);*/


while((digitalRead(left)) || (digitalRead(right))){
 if(digitalRead(ldr)==1)
 {test=1;}
Serial.println("for_black");

while((digitalRead(left)) && !(digitalRead(right))){
Serial.println("right");
digitalWrite(in1, HIGH);
digitalWrite(in2,LOW);

digitalWrite(in3, LOW);
digitalWrite(in4,LOW);
}

while(!(digitalRead(left)) && (digitalRead(right))){
Serial.println("left");
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);

digitalWrite(in3,HIGH);
digitalWrite(in4, LOW);
}

digitalWrite(in2, HIGH);
digitalWrite(in1, LOW);

digitalWrite(in4,HIGH);
digitalWrite(in3, LOW);

 
 
 if( (test==1)&&( digitalRead(ldr)==0 )){
     Serial.println("FLAG");
   flag_f=1;
   test=0;
  stop_motors();
    return 1;
  }
}
test=0;
 stop_motors();
  return 0;
}  

int forward_motors(void){
 
 Serial.println("back_motors");
 
 analogWrite(enA,180);
 analogWrite(enB,180);
/*
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3,HIGH);
digitalWrite(in4, LOW);*/


while((digitalRead(left)) || (digitalRead(right))){
 if(digitalRead(ldr)==1)
 {test=1;}
Serial.println("forward black");

if((digitalRead(left)) && !(digitalRead(right))){
Serial.println("right");
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, LOW);
digitalWrite(in4,LOW);
}

else if(!(digitalRead(left)) && (digitalRead(right))){
Serial.println("left");
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);

digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
}
else {
digitalWrite(in2,LOW);
digitalWrite(in1, HIGH);

digitalWrite(in4,LOW);
digitalWrite(in3, HIGH);
}
 
 
 if((test==1)&& ( digitalRead(ldr)==0 )){
     Serial.println("FLAG");
   flag_f=1;
  stop_motors();
  test=0;
    return 1;
  }
}
test=0;
  stop_motors();
  return 0;
}

void open_leds(void){

Serial.println("open_leds");

digitalWrite(12,HIGH);

}

void stop_leds(void){

Serial.println("stop_leds");
digitalWrite(12,LOW);

}


void left_servo(){
  Serial.println("servo_left");
  
                  Servo1.write(20);
                 
                       }
                       
void right_servo(void){
  
Serial.println("servo_right");

                       Servo1.write(110);
                      
                       }
                       

void stop_motors(void){
 
  
Serial.println("stop_motors");
digitalWrite(in1, LOW);
digitalWrite(in3, LOW);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);
}
  
  

void order(long binary){
  switch (binary){
    case 1:
     forward_motors();
      break;

      case 10:
      back_motors();
      break;

      case 11:
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
{ int x = analogRead(A0 );
 Serial.println(x);
 delay(5000);
  /*
if((start_bit==0) && ((digitalRead(ldr)==0)|| flag_f==1))
{delay(250);
start_bit=1;
 flag_f=0;
}

while(start_bit){
  
  bit1=!(digitalRead(13));
 delay(200);
  bit2=!(digitalRead(13));
 delay(200);
  bit3=!(digitalRead(13));
  delay(50);
  
  start_bit=0;
  }
  

 
  result = 100*bit1 + 10*bit2 + bit3 ;
 // Serial.println(result);
  
  if(temp != result){
  
  order(result);
  //Serial.println("temp");
 
  temp=result;
 
 
  }*/
  
  }
