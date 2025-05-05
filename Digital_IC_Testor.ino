// Project start date :- 010423 ("ddMMyy")
// by default all digital pins are in input mode high imedeance
// which can generate random input if nothin connected
// for default value you can use INPUT_PULLUP (to use inbuilt pullup registor)
// pinMode(ledPin, INPUT_PULLUP);

#define TRUE (1)
#define FALSE (0)

void ResetAllPins()
{
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, LOW);
  
}

void setup() 
{
  ResetAllPins();
}

void loop() 
{
  int R_A0 = digitalRead(A0);
  if (R_A0 == LOW) 
  {
    //digitalWrite(A5, HIGH);  
    int R_A1 = digitalRead(A1);
    int R_A2 = digitalRead(A2);
    int R_A3 = digitalRead(A3);
    int R_A4 = digitalRead(A4);
    
    if (R_A1 == LOW && R_A2 == LOW && R_A3 == LOW && R_A4 == LOW) // AND gate // 7408 // 0000
    {
      if(TestANDGate(1,2,3) && TestANDGate(4,5,6) && TestANDGate(13,12,11) && TestANDGate(10,9,8))
      {
        digitalWrite(A5, HIGH);  
      }
      else digitalWrite(A5, LOW);  
    }
    
    if (R_A1 == LOW && R_A2 == LOW && R_A3 == LOW && R_A4 == HIGH) // OR gate // 7432 // 0001
    {
      if(TestORGate(1,2,3) && TestORGate(4,5,6) && TestORGate(13,12,11) && TestORGate(10,9,8))
      {
        digitalWrite(A5, HIGH);  
      }
      else digitalWrite(A5, LOW);  
    } 

    if (R_A1 == LOW && R_A2 == LOW && R_A3 == HIGH && R_A4 == LOW) // NOT gate // 7404 // 0010
    {
      if(TestNOTGate(1,2) && TestNOTGate(3,4) && TestNOTGate(5,6) && TestNOTGate(13,12) && TestNOTGate(11,10) && TestNOTGate(9,8))
      {
        digitalWrite(A5, HIGH);  
      }
      else digitalWrite(A5, LOW);  
    } 

     if (R_A1 == LOW && R_A2 == LOW && R_A3 == HIGH && R_A4 == HIGH) // NAND gate // 7400 // 0011
    {
      if(TestNANDGate(1,2,3) && TestNANDGate(4,5,6) && TestNANDGate(13,12,11) && TestNANDGate(10,9,8))
      {
        digitalWrite(A5, HIGH);  
      }
      else digitalWrite(A5, LOW);  
    } 

     if (R_A1 == LOW && R_A2 == HIGH && R_A3 == LOW && R_A4 == LOW) // NOR gate // 7402 // 0100
    {
      if(TestNORGate(2,3,1) && TestNORGate(5,6,4) && TestNORGate(12,11,13) && TestNORGate(9,8,10))
      {
        digitalWrite(A5, HIGH);  
      }
      else digitalWrite(A5, LOW);  
    }  
      
    

  } 
  else 
  {
    digitalWrite(A5, LOW);  
    delay(2000);
  }
}



int TestANDGate(int InPin1, int InPin2, int OutPin) //7408
{
      pinMode(InPin1, OUTPUT);
      pinMode(InPin2, OUTPUT);
      pinMode(OutPin, INPUT);  
      
      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, HIGH);  
      int result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, HIGH);
      result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return TRUE;
      
    lbl_false:
      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return FALSE; 
      
}

int TestORGate(int InPin1, int InPin2, int OutPin) // 7432
{
      pinMode(InPin1, OUTPUT);
      pinMode(InPin2, OUTPUT);
      pinMode(OutPin, INPUT);  
      
      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, HIGH);  
      int result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, HIGH);
      result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return TRUE;
      
    lbl_false:
      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return FALSE; 
      
}

int TestNANDGate(int InPin1, int InPin2, int OutPin) // 7400 
{
      pinMode(InPin1, OUTPUT);
      pinMode(InPin2, OUTPUT);
      pinMode(OutPin, INPUT);  
      
      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, HIGH);  
      int result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, HIGH);
      result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return TRUE;
      
    lbl_false:
      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return FALSE; 
      
}

int TestNORGate(int InPin1, int InPin2, int OutPin) // 7402
{
      pinMode(InPin1, OUTPUT);
      pinMode(InPin2, OUTPUT);
      pinMode(OutPin, INPUT);  
      
      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, HIGH);  
      int result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, HIGH);
      result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      digitalWrite(InPin1, HIGH);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      digitalWrite(InPin1, LOW);
      digitalWrite(InPin2, LOW);
      result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 

      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return TRUE;
      
    lbl_false:
      pinMode(InPin1, INPUT);
      pinMode(InPin2, INPUT);
      pinMode(OutPin, INPUT);
      return FALSE; 
      
}

int TestNOTGate(int InPin, int OutPin) // 7404
{
      pinMode(InPin, OUTPUT);
      pinMode(OutPin, INPUT);  
      
      digitalWrite(InPin, HIGH);
      int result = digitalRead(OutPin);
      if(result != LOW) goto lbl_false; 

      digitalWrite(InPin, LOW);
      result = digitalRead(OutPin);
      if(result != HIGH) goto lbl_false; 
      
      pinMode(InPin, INPUT);
      pinMode(OutPin, INPUT);
      return TRUE;
      
    lbl_false:
      pinMode(InPin, INPUT);
      pinMode(OutPin, INPUT);
      return FALSE; 
      
}


