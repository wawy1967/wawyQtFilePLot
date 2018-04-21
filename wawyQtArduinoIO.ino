    
    int led = 13;
    int ch = 0;
    void setup() {
      Serial.begin(9600);
      pinMode(led,OUTPUT);
    }    
    void loop() {
      if (Serial.available() > 0) 
      {
         ch = Serial.read();
         if (ch == 'n')
           digitalWrite(led, HIGH);
         if (ch == 'f')
           digitalWrite(led, LOW);
      }     
      int sensorValue = analogRead(A0);
      double celcuis = (sensorValue/1024.0)*500.0;
      Serial.println(celcuis);
      delay(1);
    }
    
    
