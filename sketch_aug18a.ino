#define light 2 //CONNECTED TO RELAY 1

#define fan 3 //CONNECTED TO RELAY 2

String voiceString;

String light1="*tesla turn on the lights#";

String light2="*it's too dark tesla#";

String light3="*lights on tesla#";

String light4="*tesla turn off the lights#";

String light5="*turn off the lights#";

String light6="*i dont need lights now#";

String fan1="*tesla please turn on the fan#";

String fan2="*turn on the fan please#";

String fan3="*fan on tesla#";

String fan4="*tesla please turn off the fan#";

String fan5="*turn off the fan tesla#";

String fan6="*tesla i dont need fan right now#";

String FL1="*turn ON everything#";

String FL2="*it's too dark and hot tesla#";

String FL3="*i want fan and light#";

String FL4="*turn off everything tesla#";

String FL5="*no need of fan and light tesla#";

String FL6="*turn off everythinh tesla#";

String GD="*goodnight tesla#";

void setup() {

Serial.begin(9600);

pinMode(light,OUTPUT);

pinMode(fan,OUTPUT);

delay(3000);

}

void loop()

{

while (Serial.available())

{

delay(10);

if (Serial.available() >0) {

char c = Serial.read();

voiceString += c;

}

Serial.println(voiceString);

}

if (voiceString.length() >0)

{

if((voiceString.equalsIgnoreCase(light1))||(voiceString.equalsIgnoreCase(light2))||(voiceString.equalsIgnoreCase(light3)))

digitalWrite(light,HIGH);

else if((voiceString.equalsIgnoreCase(light4))||(voiceString.equalsIgnoreCase(light5))||(voiceString.equalsIgnoreCase(light6)))

digitalWrite(light,LOW);

else if((voiceString.equalsIgnoreCase(fan1))||(voiceString.equalsIgnoreCase(fan2))||(voiceString.equalsIgnoreCase(fan3)))

digitalWrite(fan,HIGH);

else if((voiceString.equalsIgnoreCase(fan4))||(voiceString.equalsIgnoreCase(fan5))||(voiceString.equalsIgnoreCase(fan6)))

digitalWrite(fan,LOW);

else if((voiceString.equalsIgnoreCase(FL1))||(voiceString.equalsIgnoreCase(FL2))||(voiceString.equalsIgnoreCase(FL3)))

{

digitalWrite(fan,HIGH);

digitalWrite(light,HIGH);

}

else if((voiceString.equalsIgnoreCase(FL4))||(voiceString.equalsIgnoreCase(FL5))||(voiceString.equalsIgnoreCase(FL6)))

{

digitalWrite(light,LOW);

digitalWrite(fan,LOW);

}

voiceString="";

}

}
