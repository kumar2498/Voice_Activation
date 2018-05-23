String voice;
int 
led1 = 2, 
led2 = 3,  
led3 = 4,  
led4 = 5,  
led5 = 6;  
 
void allon(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); 
     digitalWrite(led4, HIGH); 
     digitalWrite(led5, HIGH); 
}
void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT); 
}

void loop() {
  while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c; 
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 

       
       if( (voice == "*all on") || (voice =="*everything on") || (voice =="*power on") || (voice =="*turn on")) {allon();}  //Turn Off All Pins (Call Function)
  else if((voice == "*power down")|| (voice =="*everything off")|| (voice =="*shutdown")|| (voice =="*shut down")|| (voice =="*all off")|| (voice =="*all of")|| (voice =="*everything of")|| (voice =="*turn off")){alloff();} //Turn On  All Pins (Call Function)

  
  else if((voice == "*lights on")|| (voice =="*turn on lights")|| (voice =="*LED on")|| (voice =="*turn on LED")) {digitalWrite(led1, HIGH);} 
  else if((voice == "*fan on")|| (voice =="*fan up")|| (voice =="*fans on")|| (voice =="*rotate the wings")|| (voice =="*I need some air")) {digitalWrite(led2, HIGH);}
  else if((voice == "*speakers on") || (voice =="*speaker on")) {digitalWrite(led3, HIGH);}
  /*else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);}
  else if(voice == "*bathroom lights on") {digitalWrite(led5, HIGH);}*/

  else if((voice == "*computer off")|| (voice =="*turn off computer")|| (voice =="*monitors off")|| (voice =="*turn off monitor"))  {digitalWrite(led1, LOW);} 
  else if((voice == "*fan off")|| (voice =="*fan off")|| (voice =="*fans off")|| (voice =="*stop the wings")|| (voice =="*I don't need air")){digitalWrite(led2, LOW);}
  else if((voice == "*speakers off") || (voice =="*speaker off")) {digitalWrite(led3, LOW);}
  /* else if(voice == "*bedroom lights off") {digitalWrite(led4, LOW);}
  else if(voice == "*bathroom lights off") {digitalWrite(led5, LOW);}*/
//-----------------------------------------------------------------------//  
voice="";}}
