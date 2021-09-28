
const int valve1 = 5;
const int valve2 = 11;
const int valve3 = 9;
const int valve4 = 6;
const int inertiapause = 15;

void setup() {
  pinMode(valve1, OUTPUT);
  pinMode(valve2, OUTPUT);
  pinMode(valve3, OUTPUT);
  pinMode(valve4, OUTPUT);
  allClosed(50);
}

void loop() {

moveNSteps(true,10,75);
allClosed(500);
moveNSteps(false,10,75);
allOpen(50);
}

void allClosed(int time) {
      digitalWrite(valve2, HIGH);
      digitalWrite(valve3, HIGH);
      digitalWrite(valve4, HIGH); 
      digitalWrite(valve1, HIGH);
      delay(time); 
}        

void allOpen(int time){
      digitalWrite(valve2, LOW);
      digitalWrite(valve3, LOW);
      digitalWrite(valve4, LOW); 
      digitalWrite(valve1, LOW);
      delay(time); 
}

void moveNSteps(bool forward, int steps, int pause) { 
  int i;  

  if (forward == false) {
    for (i = 0; i < steps; i++) {
      digitalWrite(valve2, HIGH);
      delay(inertiapause);
      digitalWrite(valve3, HIGH);
      digitalWrite(valve4, HIGH); 
      digitalWrite(valve1, LOW);
      delay(pause);         
            
      digitalWrite(valve1, HIGH); 
      delay(inertiapause);
      digitalWrite(valve2, HIGH);
      digitalWrite(valve3, HIGH);
      digitalWrite(valve4, LOW); 
      delay(pause);  
      
      digitalWrite(valve1, HIGH); 
      digitalWrite(valve2, HIGH);
      digitalWrite(valve4, HIGH);
      delay(inertiapause);
      digitalWrite(valve3, LOW);  
      delay(pause);
         
      digitalWrite(valve1, HIGH); 
      digitalWrite(valve3, HIGH);
      delay(inertiapause);
      digitalWrite(valve4, HIGH);  
      digitalWrite(valve2, LOW);  
      delay(pause);
    }
  } else {
    for (i = 0; i < steps; i++) { 
      digitalWrite(valve1, HIGH); 
      delay(inertiapause);
      digitalWrite(valve3, HIGH);   
      digitalWrite(valve4, HIGH);
      digitalWrite(valve2, LOW); 
      delay(pause);  
      digitalWrite(valve1, HIGH); 
      digitalWrite(valve2, HIGH);  
      delay(inertiapause);    
      digitalWrite(valve4, HIGH);  
      digitalWrite(valve3, LOW);
      delay(pause);
      digitalWrite(valve1, HIGH); 
      digitalWrite(valve2, HIGH);
      digitalWrite(valve3, HIGH);
      delay(inertiapause);      
      digitalWrite(valve4, LOW); 
      delay(pause);               
      digitalWrite(valve2, HIGH);
      digitalWrite(valve3, HIGH);
      digitalWrite(valve4, HIGH); 
      delay(inertiapause);
      digitalWrite(valve1, LOW); 
      delay(pause);  

    } 
  }
}
