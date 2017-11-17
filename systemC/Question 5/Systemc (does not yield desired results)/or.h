#include <systemc.h>

/*
	Name : 	Ashwin Joisa (16CO104)
			Praveen Raj (16CO115)
	Date : 	16/10/2017
*/

SC_MODULE(Or){
  sc_in< bool > inp_1,inp_2;
  sc_out< bool > out;

  void run(){
    out.write((inp_1.read() | inp_2.read()));
  }

  SC_CTOR(Or){
    SC_METHOD(run);
    sensitive << inp_1<<inp_2;
  }
};
