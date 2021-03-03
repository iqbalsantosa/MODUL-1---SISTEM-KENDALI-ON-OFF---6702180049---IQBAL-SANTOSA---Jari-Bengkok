int LDR = A0;
int LED = 3;
int dataSensor;
int pwmA = 6;
int pwmB = 5;
int pinEnable = 7;


void setup()
{
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(pinEnable, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  dataSensor = analogRead(LDR);
  Serial.println(dataSensor);
  
  if(dataSensor < 100){
  digitalWrite(LED, HIGH);
  belokkiri();
  }
  else
  digitalWrite(LED, LOW);
  belokkanan();
}

void belokkanan(){
  digitalWrite(pinEnable, HIGH);
  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, LOW);
}
void belokkiri(){
  digitalWrite(pinEnable, HIGH);
  digitalWrite(pwmA, LOW);
  digitalWrite(pwmB, HIGH);
}