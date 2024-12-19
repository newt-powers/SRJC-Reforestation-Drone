
//the goal of this program is to use a DC(?) motor to capture and
//drop seeds on the reforestation drone at regular intervals
//author: Newt Powers
//date created: 12/17/24

//initially following this tutorial until receiving motors: https://www.tutorialspoint.com/arduino/arduino_dc_motor.htm
//talks about speed control

//define the arduino pin that turns the motor as pin 9
int motorPin = 9;

void setup() {
  //setting the pin to output a signal, not receive it
  pinMode(motorPin, OUTPUT);
  //baud rate
  Serial.begin(9600);
  while(!Serial);
  //prompt the user to input a speed value
  Serial.println("speed 0 to 255");  
}

void loop() {
    //if the  user wrote a value to the console
    if(Serial.available()) {
      //var speed becomes said value
      int speed = Serial.parseInt();
      if(speed >= 0 && speed <= 255) {
        //turn the motor at the speed written
        analogWrite(motorPin, speed);
      }
    }

}
