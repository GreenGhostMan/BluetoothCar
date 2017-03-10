/*
 This Code use 1 dc motor and 1 servo motor and motor shield.
 Please don't copy direct.It may crush cause of copy/paste .
 Please Refer command character and do coding.
 ***********************************************************
 GhostMan( The Green Hacker )
 ***********************************************************
 
#include <MotorShieldR3.h>
MotorShieldR3 yellowCar;
#define pinfrontLights    7    //Pin that activates the Front lights.
#define pinbackLights     4    //Pin that activates the Back lights.   
char command = 'S';
int velocity = 0;   

void setup() 
{       
  Serial.begin(115200);  //Set the baud rate to that of your Bluetooth module.
  pinMode(pinfrontLights , OUTPUT);
  pinMode(pinbackLights , OUTPUT);
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      yellowCar.Forward_4W(velocity);
      break;
    case 'B':  
      yellowCar.Back_4W(velocity);
      break;
    case 'L':  
      yellowCar.Left_4W();
      break;
    case 'R':
      yellowCar.Right_4W();  
      break;
    case 'S':  
      yellowCar.Stopped_4W();
      break; 
    case 'I':  //FR  
      yellowCar.ForwardRight_4W(velocity);
      break; 
    case 'J':  //BR  
      yellowCar.BackRight_4W(velocity);
      break;        
    case 'G':  //FL  
      yellowCar.ForwardLeft_4W(velocity);
      break; 
    case 'H':  //BL
      yellowCar.BackLeft_4W(velocity);
      break;
    case 'W':  //Font ON 
      digitalWrite(pinfrontLights, HIGH);
      break;
    case 'w':  //Font OFF
      digitalWrite(pinfrontLights, LOW);
      break;
    case 'U':  //Back ON 
      digitalWrite(pinbackLights, HIGH);
      break;
    case 'u':  //Back OFF 
      digitalWrite(pinbackLights, LOW);
      break; 
    case 'D':  //Everything OFF 
      digitalWrite(pinfrontLights, LOW);
      digitalWrite(pinbackLights, LOW);
      yellowCar.Stopped_4W();
      break;         
    default:  //Get velocity
      if(command=='q'){
        velocity = 255;  //Full velocity
        yellowCar.SetSpeed_4W(velocity);
      }
      else{ 
        //Chars '0' - '9' have an integer equivalence of 48 - 57, accordingly.
        if((command >= 48) && (command <= 57)){ 
          //Subtracting 48 changes the range from 48-57 to 0-9.
          //Multiplying by 25 changes the range from 0-9 to 0-225.
          velocity = (command - 48)*25;       
          yellowCar.SetSpeed_4W(velocity);
        }
      }
    }
  } 
}
// v is horn
// x is tringle

*/
