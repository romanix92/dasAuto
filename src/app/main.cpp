#include <iostream>
#include <unistd.h>
#include "3rdparty/gpio/GPIOManager.h"
#include "3rdparty/gpio/GPIOConst.h"


int main()
{
  GPIO::GPIOManager* gp = GPIO::GPIOManager::getInstance();
  int pin = GPIO::GPIOConst::getInstance()->getGpioByKey("P8_13");

  gp->exportPin(pin);
  gp->setDirection(pin, GPIO::OUTPUT);
  while(true)    
  {
      sleep(1);
      gp->setValue(pin, GPIO::HIGH);
      sleep(1);
      gp->setValue(pin, GPIO::LOW);
  }
  gp->~GPIOManager();

  return 0;
}
