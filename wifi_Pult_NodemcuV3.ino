/* Ivan Golubev 
 * Complete project pult nodemcu lua v3 esp8266
 *  
 *  
 */

// Используется портированная под esp8266 библиотека irremote
#include <ESP8266WiFi.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRrecv.h>
//#include <ESP8266mDNS.h>



// Аутентификация в сети
const char* ssid     = "";
const char* password = "";

IPAddress ip(192,168,2,29);  //статический IP
IPAddress gateway(192,168,2,1);
IPAddress subnet(255,255,255,0);


//Set вебсерверу 80 порт
WiFiServer server(80);

//MDNSResponder mdns;

//Строковая переменная для хранения HTTP запроса
String header;

//Коды кнопок


//Вывод на ir диод
const int IRoutput = D5;
const int IRinput = D6;
IRsend irsend(IRoutput);
IRrecv irrecv(IRinput);

decode_results results;

void WifiPult()
{
  WiFiClient client = server.available(); // Ожидание клиента

  if(client)
  {
    Serial.println("New Client.");
    String currentLine = ""; // Строка для хранения входящих данных от клиента 
    while(client.connected()) // Цикл на время подключения клиента
    {
      if(client.available()) // Если есть биты для чтения от клиента
      {
        char c = client.read(); // Читаем бит
        Serial.write(c); //Выводим в серийный монитор
        header +=c;
        if(c == '\n') // 
        {   // Проверки на конец запроса
          if(currentLine.length() == 0) // Заголовки HTTP всегда начинаются с кода ответа (например, HTTP / 1.1 200 OK)
          { //и тип-контента, чтобы клиент знал, что ждет, а затем пустую строку:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // парс хедеров
            if(header.indexOf("GET /task/power") >= 0) // Вкл/Выкл
            {
              Serial.println("Power NEC send");
              unsigned long data = 0x41000FF;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            
            if(header.indexOf("GET /task/menu") >= 0) // Меню
            {
              Serial.println("Menu NEC send");
              unsigned long data = 0x4108877;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/mute") >= 0) // Mute
            {
              Serial.println("Mute NEC send");
              unsigned long data = 0x41020DF;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            
            if(header.indexOf("GET /task/return") >= 0) // return
            {
              Serial.println("return NEC send");
              unsigned long data = 0x41030CF;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            

            if(header.indexOf("GET /task/vPlus") >= 0) // v+
            {
              Serial.println("v+ NEC send");
              unsigned long data = 0x41040BF;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/vMinus") >= 0) // v-
            {
              Serial.println("v- NEC send");
              unsigned long data = 0x410C03F;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/up") >= 0) // Up
            {
              Serial.println("Up NEC send");
              unsigned long data = 0x41048B7;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/Left") >= 0) // Left
            {
              Serial.println("Left NEC send");
              unsigned long data = 0x41028D7;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/Right") >= 0) // Right
            {
              Serial.println("Right NEC send");
              unsigned long data = 0x4106897;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/Down") >= 0) // Down
            {
              Serial.println("Down NEC send");
              unsigned long data = 0x410C837;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/OK") >= 0) // OK
            {
              Serial.println("OK NEC send");
              unsigned long data = 0x410A857;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/ChMinus") >= 0) // ChMinus
            {
              Serial.println("ChMinus NEC send");
              unsigned long data = 0x410E01F;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/ChPlus") >= 0) // ChPlus
            {
              Serial.println("ChPlus NEC send");
              unsigned long data = 0x410609F;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            
            if(header.indexOf("GET /task/1") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x41038C7;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/2") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x410B847;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/3") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x4107887;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/4") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x41002FD;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/5") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x410827D;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }

            if(header.indexOf("GET /task/6") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x41042BD;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            if(header.indexOf("GET /task/7") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x41022DD;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            if(header.indexOf("GET /task/8") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x410A25D;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            if(header.indexOf("GET /task/9") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x410629D;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }
            if(header.indexOf("GET /task/0") >= 0) //
            {
              Serial.println("Num NEC send");
              unsigned long data = 0x410E21D;
              unsigned int bits = 32;
              irsend.sendNEC(data, bits);
            }


            //Вывод HTML страницы
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #A9A9A9; border: none; color: white; ");
            client.println("text-decoration: none; display: inline-block; margin: 0px auto; text-align: center; font-size: 16px; cursor: pointer; padding: 10px 20px; width:100px;}");
            client.println(".button2 {background-color: #FF6347;}</style></head>");
            
            client.println("<body><h2>NodeMcu lua v3 esp8266 Kitchen Web Server</h2>");
            
            client.println("<p><a href=\"/task/power\"><button class=\"button button2\">Power</button></a></p>");
            
            
            client.println("<p><a href=\"/task/menu\"><button class=\"button\">Menu</button></p>");
            client.println("<p><a href=\"/task/1\"><button class=\"button button2\">1</button></a> <a href=\"/task/2\"><button class=\"button button2\">2</button></a> <a href=\"/task/3\"><button class=\"button button2\">3</button></a> </p>");
            client.println("<p><a href=\"/task/4\"><button class=\"button button2\">4</button></a> <a href=\"/task/5\"><button class=\"button button2\">5</button></a> <a href=\"/task/6\"><button class=\"button button2\">6</button></a> </p>");
            client.println("<p><a href=\"/task/7\"><button class=\"button button2\">7</button></a> <a href=\"/task/8\"><button class=\"button button2\">8</button></a> <a href=\"/task/9\"><button class=\"button button2\">9</button></a> </p>");
            client.println("<p> <a href=\"/task/0\"><button class=\"button button2\">0</button></a></p>");
            client.println("<p><a href=\"/task/vMinus\"><button class=\"button\">Volume-</button></a> <a href=\"/task/up\"><button class=\"button\">Up</button></a> <a href=\"/task/vPlus\"><button class=\"button\">Volume+</button></a> </p>");
            client.println("<p><a href=\"/task/Left\"><button class=\"button\">Left</button></a> <a href=\"/task/OK\"><button class=\"button button2\">OK</button></a> <a href=\"/task/Right\"><button class=\"button\">Right</button></a></p>");
            client.println("<p><a href=\"/task/mute\"><button class=\"button\">Mute</button></a> <a href=\"/task/Down\"><button class=\"button\">Down</button></a> <a href=\"/task/return\"><button class=\"button\">Return</button></a> </p>");
            client.println("<p><a href=\"/task/ChMinus\"><button class=\"button\">Ch-</button></a> <a href=\"/task/ChPlus\"><button class=\"button\">Ch+</button></a></p>");
            //client.println("<p></p>");

            
            
            client.println("</body></html>");
            break; // Сброс подключения, выходом из while 
            
          }
          else
          {
            currentLine = ""; //Если получена новая строка, очистка текущей
          }
        }
        else if(c != '\r') // Если получено что то ещё 
        {
          currentLine +=c; // Добавляю в конец
        }
      }
      
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
  
  

}

void StaticPult()
{
  if(irrecv.decode(&results))
  {
    Serial.print("Input ir signal : 0x");
    
    Serial.println((long)results.value, HEX);
    delay(50);
    irrecv.resume();
    unsigned long resVal = results.value;


    switch(resVal)
    {
      case 530663: // mute
      {
        Serial.println("Mute NEC send");
        unsigned long data = 0x41020DF;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 573503: // 1
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x41038C7;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 532703: // 2
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x410B847;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 565343: // 3
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x4107887;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 549023: // 4
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x41002FD;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 581663: // 5
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x410827D;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 528623: //6
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x41042BD;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 561263: //7
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x41022DD;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 544943: //8
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x410A25D;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 577583: //9
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x410629D;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 536783: // 0
      {
        Serial.println("Num NEC send");
        unsigned long data = 0x410E21D;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 524543: //power
      {
        Serial.println("Power NEC send");
        unsigned long data = 0x41000FF;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 553103: // menu
      {
        Serial.println("Menu NEC send");
        unsigned long data = 0x4108877;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 557693: // return
      {
        Serial.println("return NEC send");
        unsigned long data = 0x41030CF;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 587783: // v+
      {
        Serial.println("v+ NEC send");
        unsigned long data = 0x41040BF;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 525053: // v-
      {
        Serial.println("v- NEC send");
        unsigned long data = 0x410C03F;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 559223: //up
      {
        Serial.println("Up NEC send");
        unsigned long data = 0x41048B7;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 542903: // left
      {
        Serial.println("Left NEC send");
        unsigned long data = 0x41028D7;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 534743: // right
      {
        Serial.println("Right NEC send");
        unsigned long data = 0x4106897;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 567383: //down
      {
        Serial.println("Down NEC send");
        unsigned long data = 0x410C837;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 575543: // OK
      {
        Serial.println("OK NEC send");
        unsigned long data = 0x410A857;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 585743: //ch-
      {
        Serial.println("ChMinus NEC send");
        unsigned long data = 0x410E01F;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      case 526583: //ch+
      {
        Serial.println("ChPlus NEC send");
        unsigned long data = 0x410609F;
        unsigned int bits = 32;
        irsend.sendNEC(data, bits);
        break;
      }
      default:
      Serial.println("Input signal not in memory, no matches found");

      
      
    }

  }
}

void setup() 
{
  Serial.begin(115200);
  irrecv.enableIRIn();
  irsend.begin();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Вывод локального ip и старт сервера
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  /*if (MDNS.begin("Pult", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }*/
  server.begin();
  //MDNS.addService("http", "tcp", 80);

}

void loop() 
{

  WifiPult();
  StaticPult();
  
}













