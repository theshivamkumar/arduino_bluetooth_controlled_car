int L1=5, L2=6, R1=9, R2=10;     //pins for left and right motors. 1 represents forward, 2 represents backward.
int led1=3, led2=11;             //headlights pin
int buzz=12;                     //horn pin
char state;                      //variable to read serial values
int Speed = 200;                 //initialising the variable handling speed of the motors (0-255)
int i=0, j=0;                    //useful counter variables

void setup(){                    //declaring all pins as outputs
 pinMode(L1, OUTPUT);
 pinMode(L2, OUTPUT);
 pinMode(R1, OUTPUT);
 pinMode(R2, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(buzz, OUTPUT);
 
 Serial.begin(38400);            //beginning serial communication
}

void loop(){
  
  if(Serial.available()!=0){            //checks whether any character is available at the serial or not
    
    state=Serial.read();                   //read the character
    state=char(state);
    Serial.println(state);
    Serial.println();
    if (state == '0'){                    //Different Speeds of the car
      Speed=0;}
    else if (state == '1'){
      Speed=100;}
    else if (state == '2'){
      Speed=180;}
    else if (state == '3'){
      Speed=200;}
    else if (state == '4'){
      Speed=255;}


    else if(state=='F'){  //Forward
      analogWrite(L1, Speed);
      analogWrite(R1, Speed);
      analogWrite(L2, 0);
      analogWrite(R2, 0);
    }
    else if(state=='G'){  //Forward Left
      analogWrite(L1, 0);
      analogWrite(R1, Speed);
      analogWrite(L2, 0);
      analogWrite(R2, 0);
    }
    else if(state=='I'){  //Forward Right
      analogWrite(L1, Speed);
      analogWrite(R1, 0);
      analogWrite(L2, 0);
      analogWrite(R2, 0);
    }
    else if(state=='B'){   //Backward
      analogWrite(L1, 0);
      analogWrite(R1, 0);
      analogWrite(L2, Speed);
      analogWrite(R2, Speed);
    }
    else if(state=='H'){   //Backward Left
      analogWrite(L1, 0);

      analogWrite(R1, 0);
      analogWrite(L2, 0);
      analogWrite(R2, Speed);
    }
    else if(state=='J'){   //Backward Right
      analogWrite(L1, 0);
      analogWrite(R1, 0);
      analogWrite(L2, Speed);
      analogWrite(R2, 0);
    }
    else if(state=='L'){   //Left
      analogWrite(L1, 0);
      analogWrite(R1, Speed);
      analogWrite(L2, Speed);
      analogWrite(R2, 0);
    }
    else if(state=='R'){   //Right
      analogWrite(L1, Speed);
      analogWrite(R1, 0);
      analogWrite(L2, 0);
      analogWrite(R2, Speed);
    }
    else if(state=='S'){   //Stop
      analogWrite(L1, 0);
      analogWrite(R1, 0);
      analogWrite(L2, 0);
      analogWrite(R2, 0);
    }


    else if(state=='W'){   //Lights Control
      if(i==0){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
      }
      else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
      }
      i=!i;
    }
    
    else if(state=='V'){   //Horn Control
          if(j==0){
        tone(buzz, 1000);
      }
      else {
        noTone(buzz);
      }
      j=!j;
    }    
  }
}
