// C++ code
//

#define VERMELHO_NORTE 12
#define AMARELO_NORTE 11
#define VERDE_NORTE 10

#define VERMELHO_LESTE 7
#define AMARELO_LESTE 6
#define VERDE_LESTE 5

#define ALERTA 4

void setup()
{
  pinMode(VERMELHO_NORTE, OUTPUT);
  pinMode(AMARELO_NORTE, OUTPUT);
  pinMode(VERDE_NORTE, OUTPUT);
  pinMode(VERMELHO_LESTE, OUTPUT);
  pinMode(AMARELO_LESTE, OUTPUT);
  pinMode(VERDE_LESTE, OUTPUT);
  pinMode(ALERTA, INPUT);
}

void loop() 
{ 
  if(digitalRead(ALERTA) == HIGH){		
		digitalWrite(VERMELHO_NORTE, HIGH);
		digitalWrite(AMARELO_NORTE,LOW); 
		digitalWrite(VERDE_NORTE,LOW); 
		digitalWrite(VERMELHO_LESTE, LOW);
		digitalWrite(AMARELO_LESTE,LOW); 
		digitalWrite(VERDE_LESTE,HIGH);  
		delay(5000); 

		digitalWrite(VERMELHO_NORTE, HIGH);
		digitalWrite(AMARELO_NORTE,LOW); 
        digitalWrite(VERDE_NORTE,LOW); 
        digitalWrite(VERMELHO_LESTE, LOW);
        digitalWrite(AMARELO_LESTE,HIGH); 
        digitalWrite(VERDE_LESTE,LOW);  
        delay(2500); 

        digitalWrite(VERMELHO_NORTE, LOW);
        digitalWrite(AMARELO_NORTE,LOW); 
        digitalWrite(VERDE_NORTE,HIGH); 
        digitalWrite(VERMELHO_LESTE, HIGH);
        digitalWrite(AMARELO_LESTE,LOW); 
        digitalWrite(VERDE_LESTE,LOW);  
        delay(5000);

        digitalWrite(VERMELHO_NORTE, LOW);
        digitalWrite(AMARELO_NORTE,HIGH); 
        digitalWrite(VERDE_NORTE,LOW); 
        digitalWrite(VERMELHO_LESTE, HIGH);
        digitalWrite(AMARELO_LESTE,LOW); 
        digitalWrite(VERDE_LESTE,LOW);  
        delay(2500);
     } else {
       digitalWrite(VERMELHO_NORTE, LOW);
       digitalWrite(AMARELO_NORTE, HIGH);
       digitalWrite(VERDE_NORTE, LOW);
       digitalWrite(VERMELHO_LESTE, LOW);
       digitalWrite(AMARELO_LESTE, HIGH);
       digitalWrite(VERDE_LESTE, LOW);
       delay(200);
       
       digitalWrite(AMARELO_NORTE, LOW);
       digitalWrite(AMARELO_LESTE, LOW);
       delay(200);
     }
}
  
  

