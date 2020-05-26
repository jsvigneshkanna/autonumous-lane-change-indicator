void setup() {

  pinMode(6,OUTPUT); //output pin for motor left forward
  pinMode(7,OUTPUT);//output pin for motor left reverse
  
  pinMode(8,OUTPUT);//output pin for motor right forward
  pinMode(9,OUTPUT);//output pin for motor rigth reverse
  int t;
  Serial.begin(9600);
}

void loop() {
  int t;
  if(Serial.available()){ //getting the input from bluetooth app
    t = Serial.read();
    Serial.println(t);
  }

  switch(t){
    case '1':  // calling function for forward direction
      forward();
      break;

    case '2':  // calling function for right direction
      right();
      break;

    case '3':   // calling function for left direction
      left();
      break;

    case '4':  // calling function for backward direction
      backward();
      break;

    case '5':  // calling function for stopping the car
      stop_car();
      break;

    case '6':  // calling function for slowing the car
      medium();
      break;

    default:
      break;
    
  }

  
  
}
void forward(){ 
    analogWrite(6,255);
    analogWrite(7,0);// function for forward direction
    analogWrite(8,255);
    analogWrite(9,0);
  }

  void backward(){ 
    analogWrite(6,0);//function for reverse direction
    analogWrite(7,255);
    analogWrite(8,0);
    analogWrite(9,255);
  }

  void right(){ 
    analogWrite(6,255);
    analogWrite(7,0);// function for right direction
    analogWrite(8,0);
    analogWrite(9,255);
  }

  void left(){ 
    analogWrite(6,0);// function for left direction
    analogWrite(7,255);
    analogWrite(8,255);
    analogWrite(9,0);
  }

  void medium(){  
    analogWrite(6,180);// function for slowing down the car
    analogWrite(7,0);
    analogWrite(8,180);
    analogWrite(9,0);
  }

  void stop_car(){  
    analogWrite(6,0);//function to stop the car
    analogWrite(7,0);
    analogWrite(8,0);
    analogWrite(9,0);
  }
