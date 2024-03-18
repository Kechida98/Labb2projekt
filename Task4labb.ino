volatile uint8_t* ddrb = (volatile uint8_t*)0x24;
volatile uint8_t* portb = (volatile uint8_t*)0x25;
volatile uint8_t* portd = (volatile uint8_t*)0x2B;
volatile uint8_t* ddrd = (volatile uint8_t*)0x2A;
volatile uint8_t* pind =(volatile uint8_t*)0x29;

int counter = 0;

void setup() {

  *ddrb |= (1 << 5); 
  *ddrb |= (1 << 0);
  *ddrb |= (1 << 4); 
  *ddrb |= (1 << 3); 
  *ddrb |= (1 << 2);

 
  *ddrd &= ~(1 << 6); 
  *ddrd &= ~(1 << 7); 
  *ddrd &= ~(1 << 3); 
  *ddrd &= ~(1 << 2); 

 
  *portd |= (1 << 6); 
  *portd |= (1 << 7); 
  *portd |= (1 << 3); 
  *portd |= (1 << 2);

  Serial.begin(9600);
}

void loop() {
  delay(150);
  int buttonCount=0;
  
 
  
  if (!(*pind & (1 << 6))) {
    *portb |= (1 << 5);
    counter++; 
    Serial.println(counter);
    buttonCount++;
  } else {
    *portb &= ~(1 << 5); 
  }

  if (!(*pind & (1 << 7))) {
    *portb |= (1 << 0); 
    counter++; 
    Serial.println(counter);
    buttonCount++;
  } else {
    *portb &= ~(1 << 0);
  }

  if (!(*pind & (1 << 3))) {
    *portb |= (1 << 4); 
    counter++; 
    Serial.println(counter);
    buttonCount++;
  } else {
    *portb &= ~(1 << 4); 
  }

  if (!(*pind & (1 << 2))) {
    *portb |= (1 << 3); 
    counter++;
    Serial.println(counter);
    buttonCount++;
  } else {
    *portb &= ~(1 << 3);
  }

  if(buttonCount >=2){
    *portb |=(1<<2);
    delay(3000);
    *portb &=~(1<<2);
  }

  if (counter ==10 ) {
    *portb |= (1 << 2);
    delay(3000); 
    *portb &= ~(1 << 2); 
    counter = 0;
    Serial.println("Counter reset.");
  } 
}