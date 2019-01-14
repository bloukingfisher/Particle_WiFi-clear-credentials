/*
 * Project Particle-clear_wifi_credentials
 * Description: Quickly clear any existing wifi credentials
 * Author: Jurie Pieterse
 * Date: January 14, 2019
 */

// PRESS THE SETUP/MODE BUTTON TO CLEAR CREDENTIALS
SYSTEM_THREAD(ENABLED); 

int LED = 7;
bool wifiClear = true; //True = don't change, false = clear

void button_handler(system_event_t event, int duration, void *)
{
  if (duration)
    wifiClear = !wifiClear;
}

void setup() {
  pinMode(LED, OUTPUT);
  
  System.on(button_status, button_handler);
  
}

void loop() {


  // this is controlled with the MODE button

  if (wifiClear)
  {
    //nothing to do we're keeping the credentials
  }
  else
  {
    // button pressed, let's forget all networks    
    WiFi.clearCredentials(); //forget
    wifiClear = !wifiClear;  // set it back to true so it doesn't cycle 
    digitalWrite(LED, HIGH);
    delay(100);
    WiFi.disconnect();  //disconnect from the current
    delay(100);
    WiFi.listen();  //start listening for a new network
    delay(60000);   //hanging out for a minute to let user know we forgot
  }
  
    //normal user code, just flashing the LED
    digitalWrite(LED, HIGH);       
    delay(1000);
    digitalWrite(LED, LOW);
    delay(3000);
                    
}
