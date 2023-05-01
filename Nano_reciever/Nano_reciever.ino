
#define CLK_PIN 2
#define RX_PIN 3

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RX_PIN, INPUT);
  pinMode(CLK_PIN, INPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, digitalRead(RX_PIN));
  Serial.print(digitalRead(RX_PIN));
  Serial.print(",");
  Serial.println(digitalRead(CLK_PIN));

}
