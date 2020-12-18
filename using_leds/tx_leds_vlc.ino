#define in1 7
#define in2 8
#define in3 9
#define in4 10
#define enA 11
#define enB 6
#define LED 13
#define left 2
#define right 3


unsigned int wait =0;
void setup() {
  
  Serial.begin(9600); // 9600 bits per second
  pinMode(13,OUTPUT); //digital PWM 3 on output
 pinMode(left,INPUT);
pinMode(right,INPUT);


  pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);

}

void loop() {
  
  
  WriteMessage(3);
  Motors_Forward();
  Motors_Forward_no_line();
  delay(50);
 Motors_Forward();
  delay(3500);
  WriteMessage(7);
 
  WriteMessage(5);
  Motors_Backward();
  delay(2000);
  
 // WriteMessage(7);
  
  WriteMessage(9);
   delay(2000);

  WriteMessage(11);
   delay(2000);
 
  WriteMessage(13);
   delay(2000);
  
  WriteMessage(15);
   delay(2000);
 
}

void WriteMessage(int num){
  switch (num){
    case 3:
      //code for 3 is  0011
      LedFlash(false, false, true,true);
      break;
      
    case 5:
      //code for 5 is 0101
      LedFlash( false, true, false,true);
      break;
      
    case 7:
      //code for 7 is 0111
      LedFlash(false, true, true,true);
      break;
      
    case 9:
      //code for 9 is 1001
      LedFlash(true, false, false,true);
      break;
      
    case 11:
      //code for 11 is 1011
      LedFlash(true, false, true,true);
      break;
      
    case 13:
      //code for 13 is 1101
      LedFlash( true, true, false,true);
      break;
      
    case 15:
      //code for 15 is  1111
      LedFlash(true, true, true,true);
      break;
    
    default:
      Serial.println(num);
      Serial.println("not signal");
      break;
  }
}


void LedFlash( boolean a, boolean b, boolean c ,boolean d){
  

////////////////LS
  if (d == true){
    Serial.println("d");
    digitalWrite(LED,HIGH);
    delay(200);
    
  }
  
  
  if (a == true){
    Serial.println("a_h");
    digitalWrite(LED,HIGH);
     delay(200);
     
  }
 
  if (a == false){
    Serial.println("a_l");
    digitalWrite(LED,LOW);
    delay(200);
    
  }
  
  if (b == true){
    Serial.println("b_h");
    digitalWrite(LED,HIGH);
    delay(200);
  }
   if (b == false){
    Serial.println("b_l");
    digitalWrite(LED,LOW);
    delay(200);
  }
  
 
if (c == false){
  Serial.println("c_l");
    digitalWrite(LED,LOW);
    delay(200);
  }
  
  if (c == true){
    Serial.println("c_h");
    digitalWrite(LED,HIGH);
    delay(200);
  }

 digitalWrite(LED,LOW);

 
}

void Motors_Forward_no_line(void){
  digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3,LOW);
digitalWrite(in4, HIGH);}


void Motors_Forward(void){
   
Serial.println("enter forward_motors");
 analogWrite(enA,180);
 analogWrite(enB,180);
 
while(wait <250){
  
if((digitalRead(left)) && (digitalRead(right))){
Serial.println("forward");

 digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3,LOW);
digitalWrite(in4, HIGH);}

 else if((digitalRead(left)) && !(digitalRead(right))){
  
Serial.println("right");
digitalWrite(in1,LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW);
digitalWrite(in4,LOW);
}

else if(!(digitalRead(left)) && (digitalRead(right))){
  //
Serial.println("left");
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
//left
digitalWrite(in3,LOW);
digitalWrite(in4, HIGH);

}

else {
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
//left
digitalWrite(in3,LOW);
digitalWrite(in4, LOW);
  }

  wait++;
}

//WriteMessage(7);
Motors_Stop();
wait=0;

  }

  
void Motors_Backward(void){
   
Serial.println(" back_motors");
 analogWrite(enA,130);
 analogWrite(enB,130);
 
while(wait<250){
if((digitalRead(left)) && (digitalRead(right))){
Serial.println("back");

 digitalWrite(in1,HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3,HIGH);
digitalWrite(in4, LOW);}

 else if((digitalRead(left)) && !(digitalRead(right))){
  
Serial.println("right");
digitalWrite(in1,HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, LOW);
digitalWrite(in4,LOW);
}

else if(!(digitalRead(left)) && (digitalRead(right))){
  //
Serial.println("left");
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
//left
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);

}

else {
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
//left
digitalWrite(in3,LOW);
digitalWrite(in4, LOW);
  }

wait++;
  }
  //WriteMessage(7);
Motors_Stop();
wait=0;
}
  

 void Motors_Stop(void){
 Serial.println("stop"); 
 digitalWrite(in1, LOW);
digitalWrite(in2, LOW);

digitalWrite(in3,LOW);
digitalWrite(in4, LOW);
  
}
