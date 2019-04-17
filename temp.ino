#include <Adafruit_DHT_Particle.h>
#define DHTTYPE DHT22
#define DHTPIN D0

DHT dht(DHTPIN, DHTTYPE);
float temperature;
char temperatureString[10];
int led = D7;

void setup() {
    
    pinMode(led, OUTPUT);
    Particle.variable("temperature", &temperatureString[0], STRING);
    dht.begin();

    }

void loop() {

    digitalWrite(led, HIGH);
    temperature = dht.getTempCelcius();
    sprintf(temperatureString, "%.2f", temperature);
    
    Particle.publish("temp", temperatureString, PRIVATE);
    delay(30000);
    digitalWrite(led, LOW);
    delay(30000);

    }
