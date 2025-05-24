
#include <WiFi.h>
#include <ESP32Servo.h>


Servo ServoL;
Servo ServoR;


static const int servoPinL = 13; // GPIO for ServoL
static const int servoPinR = 12; // GPIO for ServoR (choose another GPIO pin when needed)

const char* ssid     = "REPLACE_WITH_MY_SSID";
const char* password = "REPLACE_WITH_MY_PASSWORD";

WiFiServer server(80);


String header;


String valueStringL = String(5); // Stores angle for ServoL
String valueStringR = String(5); // Stores angle for ServoR
int pos1 = 0; 
int pos2 = 0; 


unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);


  ServoL.attach(servoPinL);
  ServoR.attach(servoPinR);


  ServoL.write(90);
  ServoR.write(90);
  valueStringL = "90";
  valueStringR = "90"; 



  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();  

  if (client) {                           
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          
    String currentLine = "";                
    while (client.connected() && currentTime - previousTime <= timeoutTime) { 
      currentTime = millis();
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (c == '\n') {                   
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>");
            client.println("body { text-align: center; font-family: \"Trebuchet MS\", Arial; margin-left:auto; margin-right:auto;}");
            client.println(".slider { -webkit-appearance: none; margin: 0 auto; width: 300px; height: 15px; background: #FFD700; outline: none; -webkit-transition: .2s; transition: opacity .2s;}");
            client.println(".slider::-webkit-slider-thumb { -webkit-appearance: none; appearance: none; width: 25px; height: 25px; background: #008CBA; cursor: pointer;}");
            client.println(".slider::-moz-range-thumb { width: 25px; height: 25px; background: #008CBA; cursor: pointer;}");
            client.println("</style>");
            client.println("<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>");

            // Web Page Content for two servos
            client.println("</head><body>");
            client.println("<h2>ESP32 Dual Servo Control</h2>");

            client.println("<h3>ServoL Control</h3>");
            client.println("<p>Angle: <span id=\"servoAngleL\"></span></p>");
            client.println("<input type=\"range\" min=\"0\" max=\"180\" class=\"slider\" id=\"servoSliderL\" onchange=\"updateServoL(this.value)\" value=\""+valueStringL+"\"/>");

            client.println("<h3>ServoR Control</h3>");
            client.println("<p>Angle: <span id=\"servoAngleR\"></span></p>");
            client.println("<input type=\"range\" min=\"0\" max=\"180\" class=\"slider\" id=\"servoSliderR\" onchange=\"updateServoR(this.value)\" value=\""+valueStringR+"\"/>");

            client.println("<script>");
            // JavaScript for ServoL
            client.println("var sliderL = document.getElementById(\"servoSliderL\");");
            client.println("var servoPL = document.getElementById(\"servoAngleL\");");
            client.println("servoPL.innerHTML = sliderL.value;"); // Initial display
            client.println("sliderL.oninput = function() { servoPL.innerHTML = this.value; }"); // Update display on input
            client.println("function updateServoL(pos) { ");
            client.println("$.get(\"/?servoL=\"+pos+\"&\"); {Connection: close};}");

            // JavaScript for ServoR
            client.println("var sliderR = document.getElementById(\"servoSliderR\");");
            client.println("var servoPR = document.getElementById(\"servoAngleR\");");
            client.println("servoPR.innerHTML = sliderR.value;"); // Initial display
            client.println("sliderR.oninput = function() { servoPR.innerHTML = this.value; }"); // Update display on input
            client.println("function updateServoR(pos) { ");
            client.println("$.get(\"/?servoR=\"+pos+\"&\"); {Connection: close};}");
            client.println("</script>");

            client.println("</body></html>");

            if(header.indexOf("GET /?servoL=") >= 0) {
              pos1 = header.indexOf('=');
              pos2 = header.indexOf('&');
              valueStringL = header.substring(pos1 + 1, pos2);

              // Rotate ServoL
              ServoL.write(valueStringL.toInt());
              Serial.print("ServoL angle: ");
              Serial.println(valueStringL);
            }
            if(header.indexOf("GET /?servoR=") >= 0) {
              pos1 = header.indexOf('='); 
              int startSearchPos = header.indexOf("GET /?servoR=") + strlen("GET /?servoR=");
              pos1 = header.indexOf('=', startSearchPos); 

              if (pos1 != -1 && pos2 != -1) {\
                  valueStringR = header.substring(pos1 + 1, pos2);
                  // Rotate ServoR
                  ServoR.write(valueStringR.toInt());
                  Serial.print("ServoR angle: ");
                  Serial.println(valueStringR);
              }
            }

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }

    header = "";

    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
