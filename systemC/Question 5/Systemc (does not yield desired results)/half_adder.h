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

//Easier to read in the program!
#define input_int(x) sc_in< sc_int<x> >
#define input_unsigned_int(x) sc_in< sc_uint<x> >
#define input_bool sc_in< bool >

#define integer(x) sc_int<x>
#define unsigned_integer(x) sc_uint<x>

#define output_int(x) sc_out< sc_int<x> >
#define output_unsigned_int(x) sc_out< sc_uint<x> >

SC_MODULE(half_adder)
{
	sc_in< bool > a,b;
	sc_out< bool > cout_,sum;

	void adder()
	{
		bool p,q;
		p = a.read();
		q = b.read();
		sum.write(p^q);
		cout_.write(p&q);

		//cout<< "\n\ta = " << a << " b = " << b << " sum = "<< sum << " carry = " << cout_;
	}

	SC_CTOR(half_adder)
	{
		SC_METHOD(adder);
		sensitive << a << b;
	}
};
