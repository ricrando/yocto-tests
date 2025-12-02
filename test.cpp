#include "yocto_api.h"
#include "yocto_temperature.h"
#include "yocto_humidity.h"
#include "yocto_pressure.h"

#include <iostream>
#include <string>

#include <chrono>

int main() {

  std::cout<<"Try to connect to Yocto USB"<<std::endl;
  std::string errmsg;
  if (YAPI::RegisterHub("usb", errmsg) != YAPI::SUCCESS) {
    std::cerr << "RegisterHub error: " << errmsg << std::endl;
    return 1;
  }

  //access first available module
  YModule* mod=YModule::FirstModule();
  std::cout<<"Module "<<mod->get_productName()
	   <<" S/N "<<mod->get_serialNumber()
	   <<std::endl;

  
  YTemperature* temp = YTemperature::FirstTemperature();
  if (temp == NULL) {
    std::cerr << "No temperature sensor found" << std::endl;
  } else {
    double tval = temp->get_currentValue();
    std::cout<<"Temperature: "<<tval<<" C"<<std::endl;
  }

  YHumidity* hum = YHumidity::FirstHumidity();
  if (hum == NULL) {
    std::cerr << "No humidity sensor found" << std::endl;
  } else {
    double hval = hum->get_currentValue();
    std::cout<<"Humidity: "<<hval<<" %"<<std::endl;
  }

  YPressure* pre = YPressure::FirstPressure();
  if (pre == NULL) {
    std::cerr << "No pressure sensor found" << std::endl;
  } else {
    double pval = pre->get_currentValue();
    std::cout<<"Pressure: "<<pval<<" hPa"<<std::endl;
  }

  /* Disable timelogger
  YDataLogger* dlog = YDataLogger::FirstDataLogger();
  if (dlog == NULL) {
    std::cerr << "No datalogger found" << std::endl;
  } else {
    auto now=dlog->get_timeUTC();
    std::cout<<"UTC "<<now<<std::endl;
    //stop
    dlog->set_recording(YDataLogger::RECORDING_OFF);
    //reset datalogger
    dlog->forgetAllDataStreams();
    // start?
  }
  */
  
  std::cout<<"Terminate and quit"<<std::endl;
  YAPI::FreeAPI();
  return 0;
}
