// include the library code:
#include <LiquidCrystal.h>
#include <IRremote.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// initialize IR receiver
int RECV_PIN = 19;

IRrecv irrecv(RECV_PIN);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  irrecv.enableIRIn();// start the receiver
  lcd.print("Bootup Successful!"); //initial message
}

//define hexadecimal values to variables
#define W 0x4BB641BE // up button
#define t 0x4BB6A15E // right button
#define m 0x4BB621DE // left button
void setup();
void loop();

decode_results results; //mandatory! defines results as decode_results from library

void loop() {
 if (irrecv.decode(&results)) {
   if (results.value == W) {
     lcd.clear(); // clears the LCD screen
     lcd.print("Welcome"); // then print new message
   }
   else if (results.value == t) {
     lcd.clear();
     lcd.print("test");
   }
   else if (results.value == m) {
     lcd.clear();
     lcd.print("more 2 c0me");
   }
   irrecv.resume(); 
 }
}
