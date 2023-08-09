#include <Servo.h>
#include <IRremote.h>
//--------------------------IR Reciever
int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;
//-------------------------------------
//--------------------------Servo Motor
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
//--------------------------------------Front Left Wheel
int motor1pin1 = 6;  //Forward
int motor1pin2 = 7;  //Backward
//--------------------------------------Front Right Wheel
int motor2pin1 = 4;  //Forward
int motor2pin2 = 5;  //Backward
//--------------------------------------Back Left Wheel
int motor3pin1 = 9;  //Backward
int motor3pin2 = 10; //Forward
//--------------------------------------Back Right Wheel
int motor4pin1 = 11; //Backward
int motor4pin2 = 12; //Forward
//--------------------------------------
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  //------------------------------------
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  //------------------------------------
  myservo.attach(2);  // attaches the servo on pin 2 to the servo object
}

void loop() {

//-----------------------------------------------------------------------------------------------Head Turning---------------------------------------------------------------------------------------
 /* for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15 ms for the servo to reach the position
  }*/
//-----------------------------------------------------------------------------------------------MOVEMENT------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------Forward Button
if(irrecv.decode(&results))//Forward Button
{
    if(results.value == 0x57E39966)    
    {
      digitalWrite(motor4pin2, HIGH);
      digitalWrite(motor2pin1, HIGH); 
      digitalWrite(motor1pin1, HIGH); 
      digitalWrite(motor3pin2, HIGH);   
      Serial.println("Forward");
    }
    else
    {
      digitalWrite(motor1pin1, LOW); 
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor3pin2, LOW);  
      digitalWrite(motor4pin2, LOW);
    }
    delay(30);  
    irrecv.resume(); 
}
//-----------------------------------------------------------------------------------------------Back Button
if(irrecv.decode(&results))//Back Button
{
    if(results.value == 0x57E3CD32)    
    {
      digitalWrite(motor4pin1, HIGH);
      digitalWrite(motor2pin2, HIGH); 
      digitalWrite(motor1pin2, HIGH); 
      digitalWrite(motor3pin1, HIGH);     
    }
    else
    {
      digitalWrite(motor4pin1, LOW);
      digitalWrite(motor2pin2, LOW); 
      digitalWrite(motor1pin2, LOW); 
      digitalWrite(motor3pin1, LOW);  
    }
    delay(30);  
    irrecv.resume(); 
}
//-----------------------------------------------------------------------------------------------Left Button
if(irrecv.decode(&results))//Left Button
{
    if(results.value == 0x57E37986)    
    {
       digitalWrite(motor1pin2, HIGH);
       digitalWrite(motor3pin1, HIGH);   
       digitalWrite(motor2pin1, HIGH);
       digitalWrite(motor4pin1, HIGH); 
    }
    else
    {
       digitalWrite(motor1pin2, LOW);
       digitalWrite(motor3pin1, LOW);   
       digitalWrite(motor2pin1, LOW);
       digitalWrite(motor4pin1, LOW); 
    }
    delay(30);  
    irrecv.resume(); 
}
//-----------------------------------------------------------------------------------------------Right Button
if(irrecv.decode(&results))//Right Button
{
    if(results.value == 0x57E3B54A)    
    {
       digitalWrite(motor1pin1, HIGH);
       digitalWrite(motor3pin2, HIGH);   
       digitalWrite(motor2pin2, HIGH);
       digitalWrite(motor4pin2, HIGH); 
    }
    else
    {
       digitalWrite(motor1pin1, LOW);
       digitalWrite(motor3pin2, LOW);   
       digitalWrite(motor2pin2, LOW);
       digitalWrite(motor4pin2, LOW); 
    }
    delay(30);  
    irrecv.resume(); 
}
//-----------------------------------------------------------------------------------------------Power Button
if(irrecv.decode(&results))//Power Button
{
    if(results.value == 0x57E3E817)    
    {
      //Write Code Here     
    }
    delay(30);  
    irrecv.resume(); 
}
//-----------------------------------------------------------------------------------------------
/*if (irrecv.decode(&results)){
    // Print Code in HEX
        Serial.println(results.value, HEX);
        irrecv.resume();
  }*/
}
