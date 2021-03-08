/**************************************************/
//Nama : IQBAL SANTOSA
//Kelompok : 3
//Nama Tim : Jari Bengkok
//Anggota 1: Iqbal Santosa
/**************************************************/
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;
int baca_sensor[6];

int pinEnable = 4;
int pinEnable2 = 2;

int motor_kiri1 = 5;
int motor_kiri2 = 6;

int motor_kanan1 = 3;
int motor_kanan2 = 11;

void setup()
{
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  
  pinMode(pinEnable, OUTPUT);
  pinMode(pinEnable2, OUTPUT);
  pinMode(motor_kiri1, OUTPUT);
  pinMode(motor_kiri2, OUTPUT);
  pinMode(motor_kanan1, OUTPUT);
  pinMode(motor_kanan2, OUTPUT);
  Serial.begin(9600);
}

void readsensor(){
baca_sensor[0] = analogRead(sensor1);
baca_sensor[1] = analogRead(sensor2);
baca_sensor[2] = analogRead(sensor3);
baca_sensor[3] = analogRead(sensor4);
baca_sensor[4] = analogRead(sensor5);
baca_sensor[5] = analogRead(sensor6);

Serial.println(baca_sensor[0]);  
}

void loop()
{
 readsensor();
 //Sensor 1 dan 2 mendeteksi gelap : Motor kanan aktif, Motor kiri mati
 if (baca_sensor[0] < 34 && baca_sensor[1] < 34 && baca_sensor[2] > 34 && baca_sensor[3] > 34 && baca_sensor[4] > 34 && baca_sensor[5] > 34 ){
 digitalWrite(pinEnable, HIGH);
   digitalWrite(motor_kiri1, LOW);
   digitalWrite(motor_kiri2, LOW);
   
   digitalWrite(pinEnable2, HIGH);
   digitalWrite(motor_kanan1, HIGH);
   digitalWrite(motor_kanan2, LOW);
 }
  //Sensor 3 dan 4 mendeteksi gelap : Kedua motor aktif
  if(baca_sensor[0] > 34 && baca_sensor[1] > 34 &&
     baca_sensor[2] < 34 && baca_sensor[3] < 34 &&
     baca_sensor[4] > 34 && baca_sensor[5] > 34){
  digitalWrite(pinEnable, HIGH);
   digitalWrite(motor_kiri1, HIGH);
   digitalWrite(motor_kiri2, LOW);
   
   digitalWrite(pinEnable2, HIGH);
   digitalWrite(motor_kanan1, HIGH);
   digitalWrite(motor_kanan2, LOW);
  }
  //Sensor 5 dan 6 mendeteksi gelap : Motor kanan mati, motor kiri aktif
  if(baca_sensor[0] > 34 && baca_sensor[1] > 34 &&
     baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
     baca_sensor[4] < 34 && baca_sensor[5] < 34){
  digitalWrite(pinEnable, HIGH);
   digitalWrite(motor_kiri1, HIGH);
   digitalWrite(motor_kiri2, LOW);
   
   digitalWrite(pinEnable2, HIGH);
   digitalWrite(motor_kanan1, LOW);
   digitalWrite(motor_kanan2, LOW);
  }
  //Semua sensor tidak mendeteksi gelap : Kedua motor mati
  if(baca_sensor[0] > 34 && baca_sensor[1] > 34 &&
     baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
     baca_sensor[4] > 34 && baca_sensor[5] > 34){
  digitalWrite(pinEnable, HIGH);
   digitalWrite(motor_kiri1, LOW);
   digitalWrite(motor_kiri2, LOW);
   
   digitalWrite(pinEnable2, HIGH);
   digitalWrite(motor_kanan1, LOW);
   digitalWrite(motor_kanan2, LOW);
  }
}