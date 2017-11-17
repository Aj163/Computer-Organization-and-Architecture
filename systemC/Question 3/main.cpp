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
#include "driver.h"
#include "half_adder.h"

//Easier to read in the program!
#define input_int(x) sc_in< sc_int<x> >
#define input_unsigned_int(x) sc_in< sc_uint<x> >
#define input_bool sc_in< bool >

#define integer(x) sc_int<x>
#define unsigned_integer(x) sc_uint<x>

#define output_int(x) sc_out< sc_int<x> >
#define output_unsigned_int(x) sc_out< sc_uint<x> >


int sc_main(int argc, char* argv[])
{
	sc_signal< bool > a_in , b_in, cout_out, sum_out;
	sc_trace_file *Trace;

	Driver d("Driver");
	d.a(a_in);
	d.b(b_in);

	half_adder h("Half_adder");
	h.a(a_in);
	h.b(b_in);
	h.cout_(cout_out);
	h.sum(sum_out);


	Trace = sc_create_vcd_trace_file("Half_adder");
	sc_trace(Trace,a_in,"a");
	sc_trace(Trace,b_in,"b");
	sc_trace(Trace,sum_out,"sum");
	sc_trace(Trace,cout_out,"cout");

	sc_start(50, SC_NS);
	sc_close_vcd_trace_file(Trace);

	cout<<endl<<endl;
	return 0;
}
