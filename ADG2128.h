#ifndef ADG2128
#define ADG2128


#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #ifndef I2CWRITE(x)
    #define I2CWRITE(x) Wire.write(x)
  #endif
  #ifndef I2CREAD()
    #define I2CREAD() Wire.read()
  #endif
#else
  #include "WProgram.h"
  #ifndef I2CWRITE(x)
    #define I2CWRITE(x) Wire.send(x)
  #endif
  #ifndef I2CREAD()
    #define I2CREAD() Wire.receive()
  #endif
#endif

#include <inttypes.h>

#define ADG2128ADDRESS 0x70
#define MATRIX0 0x70
#define MATRIX1 0x71
#define MATRIX2 0x72
#define MATRIX3 0x73
#define MATRIX4 0x74
#define MATRIX5 0x75
#define MATRIX6 0x76
#define MATRIX7 0x77

#define ON 0x80
#define OFF 0x00

#define X0 0x00
#define X1 0x08
#define X2 0x10
#define X3 0x18
#define X4 0x20
#define X5 0x28
#define X6 0x40
#define X7 0x48
#define X8 0x50
#define X9 0x58
#define X10 0x60
#define X11 0x68

#define Y0 0x00
#define Y1 0x01
#define Y2 0x02
#define Y3 0x03
#define Y4 0x04
#define Y5 0x05
#define Y6 0x06
#define Y7 0x07

#define RBX0 0x34
#define RBX1 0x3C
#define RBX2 0x74
#define RBX3 0x7C
#define RBX4 0x35
#define RBX5 0x3D
#define RBX6 0x75
#define RBX7 0x7D
#define RBX8 0x36
#define RBX9 0x3E
#define RBX10 0x76
#define RBX11 0x7E

#define RBY0 0x01
#define RBY1 0x02
#define RBY2 0x04
#define RBY3 0x08
#define RBY4 0x10
#define RBY5 0x20
#define RBY6 0x40
#define RBY7 0x80


class PatchBay {
public:  
  PatchBay();
  void begin(uint8_t address = ADG2128ADDRESS);
  void set(uint8_t input, uint8_t output, bool state);
  void set(uint8_t input, uint8_t output, bool state, bool immediate);
  uint8_t read(uint8_t input);
  void clear(void);
  
protected:
  
  
private:
  uint8_t _address;

};

#endif