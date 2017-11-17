/*
  export SYSTEMC_HOME=/usr/local/systemc-2.3.1a/
  g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 hello.cpp -lsystemc
  export LD_LIBRARY_PATH=/usr/local/systemc-2.3.1a/lib-linux64
  ./a.out
*/

/*
	Name : 	Ashwin Joisa (16CO104)
			Praveen Raj (16CO115)
	Date : 	16/10/2017
*/

// All systemc modules should include systemc.h header file
#include <systemc.h>
#include "half_adder.h"
#include "or.h"

//Easier to read in the program!
#define input_int(x) sc_in< sc_int<x> >
#define input_unsigned_int(x) sc_in< sc_uint<x> >
#define input_bool sc_in< bool >

#define integer(x) sc_int<x>
#define unsigned_integer(x) sc_uint<x>

#define output_int(x) sc_out< sc_int<x> >
#define output_unsigned_int(x) sc_out< sc_uint<x> >

SC_MODULE(full_adder)
{
	sc_in< bool > a,b, Cin;
	sc_out< bool > cout_,sum;

	half_adder *h1;
	half_adder *h2;
	Or *o;

	sc_signal< bool > t1, t2, t3;




	SC_CTOR(full_adder)
	{
		h1 = new half_adder("Half_Adder1");
		h2 = new half_adder("Half_Adder2");
		o = new Or("Or");
		*h1 <<a<<b<<t1<<t2;
	 	*h2 <<t2<<Cin<<t3<<sum;
		*o <<t3<<t1<<cout_;

	}
};
