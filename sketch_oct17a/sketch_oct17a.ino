
#define pwm1 20
#define dig1 3
#define pwm2 21
#define dig2 4

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm1, OUTPUT);
  pinMode(dig1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dig2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, HIGH);
  analogWrite(pwm2, HIGH);
  for(int i = 0; i <= 150; i += 1)
  {
    analogWrite(pwm1, i);
    delay(50);
  }
  analogWrite(pwm1, HIGH);
  digitalWrite(dig2, LOW);
  digitalWrite(dig1, HIGH);
  
  for(int i = 0; i <= 150; i += 1)
  {
    analogWrite(pwm2, i);
    delay(50);
  }
  
}
