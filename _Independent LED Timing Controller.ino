//led1
const int led1_pin = 8;
bool led1_isOn = false;
const int interval_1 = 250;

unsigned long pre1_time;

//led2
const int led2_pin = 9;
bool led2_isOn = false;
const int interval_2 = 1000;

unsigned long pre2_time;


//function

void blink(int pin, int interval, unsigned long &pre_time, bool &on){
  unsigned long current_time = millis();

  if(current_time - pre_time >= interval){
    pre_time += interval;

    if(on){
      digitalWrite(pin, LOW);
      on = false;
    }else{
      digitalWrite(pin, HIGH);
      on = true;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);

  pre1_time = millis();
  pre2_time = millis();

}

void loop() {
  // put your main code here, to run repeatedly:
  blink(led1_pin, interval_1, pre1_time, led1_isOn);
  blink(led2_pin, interval_2, pre2_time, led2_isOn);

}









