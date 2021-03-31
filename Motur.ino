#define motor1 7
#define motor2 6
#define motorEn 9
#define potisko A1
#define uyari_ledi 10

int potiskodeger;
int motorcum;
int hiz_uyarisi = 0;
int gosterge;


void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motorEn, OUTPUT); 
  pinMode(potisko, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  motorcum = analogRead(potisko);
  motorcum=map(motorcum,0,1023,0,255); 
  analogWrite(motorEn ,motorcum ); 
  gosterge = analogRead(potisko);
  gosterge=map(gosterge,0,1023,0,12500);
  Serial.print(gosterge );
  Serial.println("rpm");
  delay(500);
  hiz_uyarisi = analogRead(potisko);
  if(hiz_uyarisi>500){
  digitalWrite(uyari_ledi, HIGH);}
  else{
    digitalWrite(uyari_ledi, LOW);
}
}
