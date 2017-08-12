// set up motor controller pins
int Aenable = 10;
int x = 12;
int y = 13;
int Benable = 11;
int x0 = 8;
int y0 = 9;

// set up bluetooth module on a seperate serial port so that we can upload to the arduino without unplugging rx
#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(6, 7); // RX | TX

int trackSpeed = 255;
void setup() {
  // set motor controller pins as outputs
  pinMode(Aenable, OUTPUT);
  pinMode(x, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(Benable, OUTPUT);
  pinMode(x0, OUTPUT);
  pinMode(y0, OUTPUT);

  // initialise bluetooth serial connection
  BT_Serial.begin(38400);
}

void loop() {
  // if there is an input from the bluetooth
  if(BT_Serial.available() > 0) {
    
    // create a char and set it to the input
    char movement;
    movement = BT_Serial.read();

     // switch to tell what is sent from the bluetooth module and move the tank accordingly
     switch(movement) {
        // forward
        case 'F':
          car(trackSpeed, trackSpeed, HIGH, LOW, HIGH, LOW);
          break;
          
        // backward  
        case 'B':
          car(trackSpeed, trackSpeed, LOW, HIGH, LOW, HIGH);
          break;
          
        // turn left  
        case 'G':
          car(trackSpeed, trackSpeed, LOW, LOW, HIGH, LOW);
          break;
          
        // turn right  
        case 'I':
          car(trackSpeed, trackSpeed, HIGH, LOW, LOW, LOW);
          break;

        // go backwards right  
        case 'J':
          car(trackSpeed, trackSpeed, LOW, LOW, LOW, HIGH);
          break;

        // go backwards left
        case 'H':
          car(trackSpeed, trackSpeed, LOW, HIGH, LOW, LOW);
          break;

        // spin left  
        case 'L':
          car(trackSpeed, trackSpeed, LOW, HIGH, HIGH, LOW);
          break;

        // spin right  
        case 'R':
          car(trackSpeed, trackSpeed, HIGH, LOW, LOW, HIGH);
          break; 

        // stop         
        case 'S':
          car(trackSpeed, trackSpeed, LOW, LOW, LOW, LOW);
          break;

        // speed 1
        case '1':
          trackSpeed = 25;
          break;

        // speed 2
        case '2':
          trackSpeed = 50;
          break;

        // speed 3
        case '3':
          trackSpeed = 75;
          break;

        // speed 4
        case '4':
          trackSpeed = 100;
          break;

        // speed 5
        case '5':
          trackSpeed = 125;
          break;

        // speed 6
        case '6':
          trackSpeed = 150;
          break;

        // speed 7
        case '7':
          trackSpeed = 175;
          break;

        // speed 8
        case '8':
          trackSpeed = 200;
          break;

        // speed 9
        case '9':
          trackSpeed = 225;
          break;

        // speed 10
        case 'q':
          trackSpeed = 255;
          break;       
    }  
  }
}

void car(int speedLeft, int speedRight, int xValue, int yValue, int x0Value, int y0Value) {
  analogWrite(Aenable, speedLeft);
    analogWrite(Benable, speedRight);

  digitalWrite(x, xValue);
    digitalWrite(y, yValue);

  digitalWrite(x0, x0Value);
   digitalWrite(y0, y0Value);
}

