#include <systemc.h>

/*
	Name : 	Ashwin Joisa (16CO104)
			Praveen Raj (16CO115)
	Date : 	16/10/2017
*/

SC_MODULE(equal){
  sc_in< bool > inp;
  sc_out< bool > out;

  void run(){
    out.write(inp.read());
  }

  SC_CTOR(equal){
    SC_METHOD(run);
    sensitive << inp;
  }
};
