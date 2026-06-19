  #include <Servo.h>
int mc1pin = 2; //motor control 1
int mc2pin = 4; //motor control 2
Servo mc1;
Servo mc2;

const int Bpin; //button pin
int Bstate = LOW; //button state


void setup() {
  // put your setup code here, to run once:
  
pinMode(mc1pin, OUTPUT);
pinMode(mc2pin, OUTPUT);
mc1.attach(mc1pin);
mc2.attach(mc2pin);
digitalWrite(LED_BUILTIN, LOW);

pinMode(Bpin, INPUT_PULLUP);


}
void loop() {
  // put your main code here, to run repeatedly:

int Bstate=digitalRead(Bpin);
if (Bstate == LOW && (mc1.read() != 1500) || (mc2.read() != 1500) ){
  mc1.write(1500);
  mc2.write(1500);
}
 else 
digitalWrite(LED_BUILTIN, HIGH);
mc1.write(1000); //backwards
mc2.write(1000);
delay(10000);
mc1.write(1500); //stop
mc2.write(1500);
delay(1000);
mc1.write(2000); //forwards
mc2.write(2000);
delay(10000);
digitalWrite(LED_BUILTIN, LOW);

}
