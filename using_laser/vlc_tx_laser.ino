#define enA 11
#define in1 10
#define in2 9

#define in3 8
#define in4 7

#define enB 6
 
#define laser 13

void setup() {
  
  Serial.begin(9600); // 9600 bits per second
  pinMode(laser,OUTPUT); //digital PWM 3 on output


 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  
//digitalWrite(led,HIGH);
  WriteMessage(3);
  delay(5000);
  
  WriteMessage(5);
  delay(5000);
  
  WriteMessage(7);
  delay(5000);
  
  WriteMessage(9);
  delay(5000);

  WriteMessage(11);
  delay(5000);
 
  WriteMessage(13);
  delay(5000);
  
  WriteMessage(15);
  delay(5000);
 
}

void WriteMessage(int num){
  switch (num){
    case 3:
      //code for 3 is  0011
      LaserFlash(false, false, true,true);
      break;
      
    case 5:
      //code for 5 is 0101
      LaserFlash( false, true, false,true);
      break;
      
    case 7:
      //code for 7 is 0111
      LaserFlash(false, true, true,true);
      break;
      
    case 9:
      //code for 9 is 1001
      LaserFlash(true, false, false,true);
      break;
      
    case 11:
      //code for 11 is 1011
     LaserFlash(true, false, true,true);
      break;
      
    case 13:
      //code for 13 is 1101
      LaserFlash( true, true, false,true);
      break;
      
    case 15:
      //code for 15 is  1111
     LaserFlash(true, true, true,true);
      break;
    
    default:
      Serial.println(num);
      Serial.println("not signal");
      break;
  }
}


void LaserFlash( boolean a, boolean b, boolean c ,boolean start_bit){
  

////////////////LS
  if (start == true){
    Serial.println("start_bit");
    digitalWrite(laser,HIGH);
    delay(80);
    
  }
  
  
  if (a == true){
    Serial.println("a_h");
    digitalWrite(laser,HIGH);
     delay(80);
     
  }
 
  if (a == false){
    Serial.println("a_l");
    digitalWrite(laser,LOW);
    delay(80);
    
  }
  
  if (b == true){
    Serial.println("b_h");
    digitalWrite(laser,HIGH);
    delay(80);
  }
   if (b == false){
    Serial.println("b_l");
    digitalWrite(laser,LOW);
    delay(80);
  }
  
 
if (c == false){
  Serial.println("c_l");
    digitalWrite(laser,LOW);
    delay(80);
  }
  
  if (c == true){
    Serial.println("c_h");
    digitalWrite(laser,HIGH);
    delay(80);
  }

 digitalWrite(laser,LOW);



}
