// Library based off: DHT library from Seeed Studio
// Library found at: https://github.com/Seeed-Studio/Grove_Temperature_And_Humidity_Sensor
// Component found at: http://www.seeedstudio.com/depot/grove-temperaturehumidity-sensor-pro-p-838.html?cPath=144_147
// Modified by: Jake Rye

#ifndef SensorDht22_H
#define SensorDht22_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// 8 MHz(ish) AVR ---------------------------------------------------------
#if (F_CPU >= 7400000UL) && (F_CPU <= 9500000UL)
#define COUNT 3
// 16 MHz(ish) AVR --------------------------------------------------------
#elif (F_CPU >= 15400000UL) && (F_CPU <= 19000000L)
#define COUNT 6
#else
#error "CPU SPEED NOT SUPPORTED"
#endif

// how many timing transitions we need to keep track of. 2 * number bits + extra
#define MAXTIMINGS 85

class SensorDht22 {
  public:
    // Public functions
    SensorDht22(uint8_t id, uint8_t pin, String humidity_instruction, String temperature_instruction);
    void begin(void);
    String get(void);
    bool set(String instruction);
    
  private:
    // Private Functions
    void getSensorData(void);
    //String getJsonString(void);
    boolean read(void);
    void getRawSensorData(void);
    void filterSensorData(void);
    
    // Private Variables
    uint8_t data[6];
    uint8_t id_, pin_, count_;
    uint32_t last_read_time_;
    boolean first_reading_;
    float humidity_raw_;
    float temperature_raw_;
    String humidity_instruction_;
    String temperature_instruction_;
    float humidity_;
    float temperature_;

};

#endif // SensorDht22_H_
