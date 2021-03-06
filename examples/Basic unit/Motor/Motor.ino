
// #define LILYGO_TWATCH_2020_V1        // If you are using T-Watch-2020 version, please open this macro definition

#include <TTGO.h>

TTGOClass *ttgo;

void setup()
{
    Serial.begin(115200);
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();

    //! begin motor attach to 33 pin , In TWatch-2020 it is IO4
    ttgo->motor_begin();    

    ttgo->eTFT->fillScreen(TFT_BLACK);
    ttgo->eTFT->setTextColor(TFT_WHITE, TFT_BLACK);
    ttgo->eTFT->drawString("Please touch screen",  50, 100, 2);

    //attach touch screen interrupt pin
    pinMode(TP_INT,INPUT);
}

void loop()
{
    if(digitalRead(TP_INT) == LOW){
         ttgo->motor->onec();    
    }
    delay(20);
}
