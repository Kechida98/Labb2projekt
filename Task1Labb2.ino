
volatile uint8_t* ddrb = (volatile uint8_t*)0x24;
volatile uint8_t* portb = (volatile uint8_t*)0x25;
volatile uint8_t* ddrd = (volatile uint8_t*)0x2A;
volatile uint8_t* portd = (volatile uint8_t*)0x2B;

void setup() {
  *ddrb |= (1 << 5);//output
  *ddrd &= ~(1 << 3);//portd synkroniserad input
  *portd |= (1<<3);//pull upp resistor för pin 3 aktiverad
}
void loop() {
  if (*portd & (1 << 3)) {
    *portb ^=(1<<5);//High
    delay(1000);
    *portb &=~(1<<5);
    delay(random(1000,10001));
    }else {
    *portb &= ~(1 << 5);//LOW
   }
}