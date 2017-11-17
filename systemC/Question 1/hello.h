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
#define output_bool sc_out< bool >


SC_MODULE(hello_world)
{
	input_bool clk;

	SC_CTOR(hello_world)
	{
		SC_METHOD(print);
		sensitive<<clk.pos();
	}

	void print()
	{
		cout<<"\n\tHello World !! - Timestamp (Clock cycles) : "<<sc_time_stamp();
	}
};