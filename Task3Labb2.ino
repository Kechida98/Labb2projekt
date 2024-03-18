volatile uint8_t* ddrb = (volatile uint8_t*)0x24;
volatile uint8_t* portb = (volatile uint8_t*)0x25;
volatile uint8_t* portd = (volatile uint8_t*)0x2B;
volatile uint8_t* ddrd = (volatile uint8_t*)0x2A;

volatile uint8_t* pind =(volatile uint8_t*)0x29;

void setup() {
  //outups för ledsen
  *ddrb |=(1<<5); //portb5 etc
  *ddrb |=(1<<0);
  *ddrb |=(1<<4);
  *ddrb |=(1<<3);

// inputs för pinbuttons
  *ddrd &=~(1<<6);
  *ddrd &=~(1<<7);
  *ddrd &=~(1<<3);//pinc o etc
  *ddrd &=~(1<<2);

//sätter på pull up resistor för buttons
  *portd |=(1<<6);
  *portd |=(1<<7);
  *portd |=(1<<3);
  *portd |=(1<<2);
}

void loop() {
 if((*pind & (1<<6))==0) {
    *portb |= (1<<5);
  } else {
    *portb &=~(1<<5);
  }
  if((*pind & (1<<7))==0){
    *portb |= (1<<0);
  }else{
    *portb &=~(1<<0);
  }
  if((*pind & (1<<3))==0){
    *portb |=(1<<4);
  }else{
    *portb &=~(1<<4);
  }
  if((*pind & (1<<2))==0){
    *portb |=(1<<3);
  }else{
    *portb &=~(1<<3);
   }  
  }
   