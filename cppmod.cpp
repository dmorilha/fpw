//==========================================
//  cppmod.cpp, finally, my C++ code

#include "kernel_api.h"
#include "new.h"
#include "cppmod.h"

class Driver {
public:
  // destructor
  ~Driver(void) {
    printk(KERN_INFO "Goodbye C++ driver\n");
  }

  // constructor
  Driver(const unsigned int dev_id) :
    id_(dev_id) {
    printk(KERN_INFO "C++ driver started\n");
  }
  
  // another constructor
  Driver(void) :
    id_(0) {
    printk(KERN_INFO "C++ driver started (another constructor)\n");
  }

private:
  const unsigned int id_;
};

static Driver * g_driver = nullptr;

extern "C" int start_driver(void * const data) {
	g_driver = new Driver(*static_cast<unsigned int * const>(data));
	if ( ! g_driver) {
	  return -1;
  }
	return 0;
}

extern "C" void stop_driver(void) {
  if (g_driver) {
	  delete g_driver;
  }
}
