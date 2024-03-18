volatile uint8_t* ddrb = (volatile uint8_t*)0x24;
volatile uint8_t* portb = (volatile uint8_t*)0x25;
volatile uint8_t* portd = (volatile uint8_t*)0x2B;
volatile uint8_t* ddrd = (volatile uint8_t*)0x2A;
volatile uint8_t* portc = (volatile uint8_t*)0x28;
volatile uint8_t* ddrc = (volatile uint8_t*)0x27;

unsigned long previousMsB5 =0;
unsigned long previousMsB0 =0;
unsigned long previousMsD3 =0;
unsigned long previousMsC4 =0;

const long intervalB5 =1750;
const long intervalB0=2000;
const long intervalD3=1500;
const long intervalC4=350;

void setup() {
  //outpot
  *ddrb |= (1 << 5);
  *ddrb |= (1 << 0);
  *ddrd |=(1 << 3);
  *ddrc |=(1 << 4); 
}


void loop() {
  unsigned long currentMs = millis();

  if(currentMs - previousMsB5 >= intervalB5){
    previousMsB5=currentMs;
    *portb ^=(1<<5);//Togglar den på
    
  }
  if(currentMs - previousMsB0 >= intervalB0){
    previousMsB0=currentMs;
    *portb ^=(1<<0);//Togglar den på
  }

    if(currentMs - previousMsD3 >= intervalD3){
      previousMsD3 =currentMs;
      *portd ^=(1<<3);//Sätter på den biten med xor avgör
    }

    if(currentMs - previousMsC4 >= intervalC4){
      previousMsC4 =currentMs;
      *portc ^=(1<<4);//samma på alla 3
    }
}

