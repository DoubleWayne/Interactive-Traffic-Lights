// Project 4. Interactive Traffic Lights

int carRed = 12;
int carYellow = 11;
int carGreen = 10;
int button = 9;//Button pins
int pedRed = 8;//Set up pedestrian lights
int pedGreen = 7;
int crossTime = 5000;//Time allowed for pedestrians to pass

unsigned long changeTime;//Time after the button is pressed

void setup() {
  // All LEDs are set to output mode
  pinMode(carRed,OUTPUT);
  pinMode(carYellow,OUTPUT);
  pinMode(carGreen,OUTPUT);
  pinMode(pedRed,OUTPUT);
  pinMode(pedGreen,OUTPUT);

  pinMode(button,INPUT);//The button is set to input mode

  digitalWrite(carGreen,HIGH);//At the beginning, the car light is green
  digitalWrite(pedRed,HIGH);//At the beginning, the pedetrian light is red
}


void loop() {
  int state = digitalRead(button);//Check if the button is pressed and if there is a 5s wait time since the last press
  if(state == HIGH && (millis()-changeTime)> 5000){
  //Call the light changing function
  
  changeLights();

  }

}
void changeLights(){

    digitalWrite(carGreen,LOW);//Car light green light off

    digitalWrite(carYellow,HIGH);//Car light yellow light on
    delay(2000);// Wait 2s
    digitalWrite(carYellow,LOW);//Car light yellow light off

    digitalWrite(carRed,HIGH);//Car light red light on
    delay(1000);//Wait 1s for safety reasons

    digitalWrite(pedRed,LOW);//pedetrian light red off
    digitalWrite(pedGreen,HIGH);//pedetrian light green on
    delay(crossTime);//Wait a crosstime(5s)

    //pedetrian light blink, Reminder: It's almost time to cross the road
    
    for(int x=0;x<10;x++){
      digitalWrite(pedGreen,HIGH);
      delay(250);
      digitalWrite(pedGreen,LOW);
      delay(250);
    }

    digitalWrite(pedRed,HIGH);//pedetrian light red on
    delay(500);

    digitalWrite(carRed,LOW);//car light red off

    digitalWrite(carYellow,HIGH);//car light yellow on
    delay(1000);
    digitalWrite(carYellow,LOW);//car light yellow off

    digitalWrite(carGreen,HIGH);//car light green on

    changeTime = millis();//Records the time since the last light change

    //return to the main fuction loop

  }