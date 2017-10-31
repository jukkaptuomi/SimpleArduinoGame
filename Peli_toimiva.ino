/*
 *  Counting presses
 */
int x=1;
int y=2 ;
int n=2;

int switchPin1 = 2;
int switchPin2 = 3;              // switch is connected to pin 2
int val1;
int val2;                        // variable for reading the pin status
int buttonState1;
int buttonState2;                // variable to hold the button state
int buttonPresses = 0;          // how many times the button has been pressed

long randNumber;
int vastaus;
int oikeaVastaus;

int valo1=8;
int valo2=9;

void setup() {
  randomSeed(analogRead(0));
  
  pinMode(valo1,OUTPUT);
  pinMode(valo2,OUTPUT);
  pinMode(switchPin1, INPUT);    // Set the switch pin as input
  pinMode(switchPin2, INPUT);
  Serial.begin(9600);           // Set up serial communication at 9600bps
  buttonState1 = digitalRead(switchPin1);
  buttonState2 = digitalRead(switchPin2);   // read the initial state
}


void loop(){
  if((n>=y)&&(oikeaVastaus!=vastaus)){n=n-3;Serial.print("Pääsit kierrokselle");Serial.println(n);
  n=2; y=2; x=1; oikeaVastaus=0; vastaus=0;}
  val1 = digitalRead(switchPin1);      // read input value and store it in val
  val2 = digitalRead(switchPin2);
  if (val1 != buttonState1) {          // the button state has changed!
    if (val1 == LOW) {                // check if the button is pressed
              // increment the buttonPresses variable
      digitalWrite(valo1,HIGH);
    delay(150);
    digitalWrite(valo1,LOW);
    delay(150);
      n++;
      vastaus++;
    }
  }
 if (val2 != buttonState2) {          // the button state has changed!
    if (val2 == LOW) {                // check if the button is pressed
               // increment the buttonPresses variable
      digitalWrite(valo2,HIGH);
    delay(150);
    digitalWrite(valo2,LOW);
    delay(150);
      n++;
      vastaus--;
    }
 }
buttonState1 = val1;
buttonState2 = val2;  // save the new state in our variable
if (oikeaVastaus==vastaus)
       {oikeaVastaus=0;
       vastaus=0;
         
         while ((n==y)&&(x!=y)){
        delay(350);
        x++;
        vastaus=0;
        randNumber=random(1,3);
                 if (randNumber<2){oikeaVastaus++;
            digitalWrite(valo1,HIGH);
    delay(150);
    digitalWrite(valo1,LOW);
    delay(150);}
                 else {oikeaVastaus--;            digitalWrite(valo2,HIGH);
    delay(150);
    digitalWrite(valo2,LOW);
    delay(150);};}}

                   if (x==y){
                    x=1;
                     n=2;
                     y++;
                    
                      }
                   
}
