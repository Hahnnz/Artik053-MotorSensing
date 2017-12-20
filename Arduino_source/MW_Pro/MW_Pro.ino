int E1 = 10;      // 1번(A) 모터 Enable
int E2 = 11;      // 2번(B) 모터 Enable
int M1 = 12;      // 1번(A) 모터 PWM  
int M2 = 13;      // 2번(B) 모터 PWM
 
int value;
 
void setup() {
  pinMode(M1, OUTPUT);      // 출력핀 설정
  pinMode(M2, OUTPUT);
}
 
void loop() 
{
   for(value = 0; value <= 255; value+=5)   // PWM 속도 0 ~ 255까지 5씩 증가
   {
      digitalWrite(M1, HIGH);
      digitalWrite(M2, HIGH);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
   }
   delay(1000);   // 1000ms = 1초 대기
 
   for(value = 0; value <= 255; value+=5)
   {
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
   }
   delay(1000);
}
