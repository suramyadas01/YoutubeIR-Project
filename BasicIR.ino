//This project uses the IRremote library. The rights to the library belongs to Ken Shirriff.


//The sensor is connected to PIN 11
#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  //Using pin 9 and 10 as VCC and GND respectively for easy connections.
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

//HOW DOES IT WORK??
// We read the incoming values. Each value a has a designated code. 
// Decide what function you want to assign to each button and note down it's code.
//Then just use if-else ladder to check for the required values.
// In my case, if you press and hold a button on the remote, 
// the code changes to "4294967295" irrespective of what button is pressed.
// The lastKey variable checks if a button is pressed and held and switches the data signal to the last unique value. So everytime 
// the "held" state is generated, it loops back to the button that was last pressed and uses its value. 
// You may or may not have this problem. You will have to modify the codes accordingly.

void loop() {
  if (irrecv.decode(&results)) {
    String str = String(results.value);
    if(str == "4294967295") str = lastKey;
    if(str == "551504055"){
        lastKey = str;
        Serial.println("UP");
      }
    //  Explanation: When the channel up button is pressed on the remote, the generated code is 551504055. I wanted the mouse
    //  cursor to move up when this button is pressed. So I passed a string "UP" to the computer via the serial line. This "UP" can be 
    //  read by the python program which can move the mouse cursor up. See the python code for more.
    else if(str == "551491815"){
        lastKey = str;
        Serial.println("DOWN");
    }
    // Same thing is copied for all mouse functions.
    // UP         -> MOUSE CURSOR UP
    // UP_RIGHT   -> MOUSE CURSOR DIAGONALLY UPWARDS TOWARDS RIGHT
    // UP_LEFT    -> MOUSE CURSOR DIAGONALLY UPWARDS TOWARDS LEFT
    // DOWN       -> MOUSE CURSOR DOWN
    // DOWN_RIGHT -> MOUSE CURSOR DIAGONALLY DOWNWARDS TOWARDS RIGHT
    // DOWN_LEFT  -> MOUSE CURSOR MOUSE CURSOR DIAGONALLY DOWNWARDS TOWARDS LEFT
    // LEFT       -> MOUSE CURSOR LEFT
    // RIGHT      -> MOUSE CURSOR RIGHT
    // BL         -> MOUSE BUTTON LEFT
    // BR         -> MOUSE BUTTON RIGHT
    // SC_UP      -> SCROLL UP
    // SC_UP      -> SCROLL DOWN
    
    else if(str == "551495895"){
        lastKey = str;
        Serial.println("LEFT");
    }
    else if(str == "551512215"){
        lastKey = str;
        Serial.println("RIGHT");
    } 
    else if(str == "551528535"){
         lastKey = str;
         Serial.println("OK");
      }
    else if(str == "551520375"){
         lastKey = str;
         Serial.println("UP_LEFT");
      }   
    else if(str == "551536695"){
         lastKey = str;
         Serial.println("UP_RIGHT");
      }
    else if(str == "551544855"){
         lastKey = str;
         Serial.println("DOWN_LEFT");
      }
     else if(str == "551535705"){
         lastKey = str;
         Serial.println("BL");
      }
     else if(str == "551525985"){
         lastKey = str;
         Serial.println("BR");
      }
    else if(str == "551524455"){
         lastKey = str;
         Serial.println("DOWN_RIGHT");
      }            
    else if(str == "551485695"){
         lastKey = str;
         Serial.println("SC_UP");
      }
    else if(str == "551518335"){
         lastKey = str;
         Serial.println("SC_DOWN");
      }
    
    // Two buttons are specifically dedicated to access websites directly. See python code for more. 
    else if(str == "551486460"){
         lastKey = str;
         Serial.println("YOUTUBE");
      }            
    else if(str == "551519100"){
         lastKey = str;
         Serial.println("NETFLIX");
      }        
    
    //if no button which we want to emulate is pressed, lastKey changes to '', that is, a simple character,just as a placeholder. 
    else lastKey = " ";
    irrecv.resume(); // Receive the next value
  }
}
