#define FREQ        250   // Sampling frequency

// ----------------------- Variables for servo signal generation -------------
unsigned int  period; // Sampling period
unsigned long loop_timer;
unsigned long now, difference;

unsigned long add1,add2,add3,add4;

unsigned long esc1 = 1000,
              esc2 = (int)(2500+450)/2,
              esc3 = 1000,
              esc4 = 1000;

bool DEBUG = false; 

void setup() {
  // put your setup code here, to run once:
    // Set pins #4 #5 #6 #7 as outputs
    DDRD |= B11110000;

    period = (1000000/FREQ) ; // Sampling period in µs

    // Initialize loop_timer
    loop_timer = micros();
    //Serial.begin(9600);
    add1=add2=add3=add4=10;
    if (DEBUG) Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Serial.println(esc1);
  applyMotorSpeed();
  /**
  esc1 = esc1 + add1;
  esc2 = esc2 + add2;
  esc3 = esc3 + add3;
  esc4 = esc4 + add4;
  **/
  esc1 = analogRead(A0);
  esc1 = map(esc1,0,1023,450,2500);
  if (DEBUG) Serial.println(esc1);
  
  esc2 = esc2; //(int)(2500 + 450)/2;
  esc3 = esc1;
  esc4 = esc1; //random(450,2600);
  delayMicroseconds(25);

/**
  if(esc1 <= 450 || esc1 >= 2600) {
    add1 = -add1;  
  }
  
  if(esc2 <= 450 || esc2 >= 2600) {
    add2 = -add2;  
  }
  
  if(esc3 <= 450 || esc3 >= 2600) {
    add3 = -add3;  
  }
  
  if(esc4 <= 450 || esc4 >= 2600) {
    add4 = -add4;  
  }
**/  
  
}
