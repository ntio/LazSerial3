#include <SHT1x.h>
#include <Servo.h>

#define dataPin  10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);
Servo myServo;
#define TEMP_SENSOR 0
int btrojo = 2;
int btazul = 3;
int ledrojo = 8;
int ledazul = 9;
int valrojo = 0;
int valazul = 0;
int led = 13; // Pin 13
int ledStaterojo = LOW; 
int ledStateazul = LOW;
int signalVoltage;
String data = "";
int Value;
int angle;
int Valservo;
char cadena[30];
byte posicion=0;
int valor;

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(btrojo, INPUT);  //definir pin como entrada
  pinMode(btrojo,HIGH);
  pinMode(btazul, INPUT);  //definir pin como entrada
  pinMode(btazul,HIGH);
  pinMode(ledrojo,OUTPUT);
  pinMode(ledazul,OUTPUT);
  pinMode(led, OUTPUT); // Set pin 13 as digital out
  attachInterrupt(digitalPinToInterrupt(btrojo), lrojo, RISING);
  attachInterrupt(digitalPinToInterrupt(btazul), lazul, RISING);
  myServo.attach(12); 
}

void mueveservo(int valor){
    Value = valor;//data.toInt();
      angle = map(Value, 0, 255, 0, 179);
      myServo.write(angle);
      delay(30);
      data = "";
    
}

void shtxx(String v)
{
  float temp_c;
  float humidity;
  String input = v;
  String stringOne;
  // Read in one char at a time
   delay(5); // Delay for 5 ms so the next char has time to be received
      
        
  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  humidity = sht1x.readHumidity();
   if (input == "temp")
        {
          stringOne='t';
             Serial.print(stringOne + temp_c);
        }     
     else if (input == "hume")
        {
          stringOne='h';
           Serial.print(stringOne + humidity);
        }
  
 
  //delay(2000);
}

void led13(String s){
  String input = s;
  // Read in one char at a time
        delay(5); // Delay for 5 ms so the next char has time to be received

        if (input == "on")
        {
            digitalWrite(led, HIGH); // on
            Serial.print("e");
        }
        else if (input == "off")
        {
            digitalWrite(led, LOW); // off
            Serial.print("f");
        }
   
}
/*
void temperatura(){
  int celsiusTemp; 
  String stringOne='t';
  signalVoltage = analogRead(TEMP_SENSOR);
  
   // Convert to celsius Temperature
  celsiusTemp = (5 * signalVoltage * 100) / 1024;

  // Print in the serial Monitor
  //Serial.print('t');
  Serial.print(stringOne + celsiusTemp);
  
}
*/
void lrojo(){
      
      ledStaterojo = !ledStaterojo;
       digitalWrite(ledrojo,ledStaterojo);
        if (ledStaterojo == LOW){
        Serial.print("a");
       }
        else{
          Serial.print("b");
        }
        
   
}
void lazul(){
     
      ledStateazul = !ledStateazul;
     
      digitalWrite(ledazul,ledStateazul);
       if (ledStateazul == LOW){
        Serial.print("c");
       }
        else{
          Serial.print("d");
        }
      
        
   
}
void loop(){
    

    if (Serial.available()){
      
    memset(cadena,0,sizeof(cadena));
      while (Serial.available() > 0) {
      delay(5);
      cadena[posicion]=Serial.read();
      posicion++;
      
    }
   // Serial.println(cadena);  
    valor = atoi(&cadena[1]);//a partir del caracter 1
   // Serial.println(valor);  
     
      char inChar = cadena[0];
      
    //  Serial.println(inChar);
      switch (inChar) {
  case 'a':
          led13("on");
         
    break;
  case 'b':
          led13("off");
  
           
    break; 
    case 't':
          shtxx("temp");
         
    break;
    case 'h':
          shtxx("hume");
         
    break; 
     case 's':
              mueveservo(valor);
       break;
  default:
    // if nothing else matches, do the default
    // default is optional
     Serial.print("comando desconocido");
    break;
}
    posicion=0;    
    }
 
  delay(100);
  
}
