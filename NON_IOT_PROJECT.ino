void setup() {
  // put your setup code here, to run once:
  pinMode(16,OUTPUT); // 16 = D0
  pinMode(5,OUTPUT); // 16 = D1
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(16,HIGH);
  delay(100); // milisecond = 1 detik
  digitalWrite(16,LOW);
  digitalWrite(5,HIGH);
  delay(100); // milisecond = 1 detik
  digitalWrite(5,LOW);
};
