/*
	export SYSTEMC_HOME=/usr/local/systemc-2.3.1a/
	g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -lsystemc
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
#include "tb_full_adder.h"
#include "full_adder.h"

//Easier to read in the program!
#define input_int(x) sc_in< sc_int<x> >
#define input_unsigned_int(x) sc_in< sc_uint<x> >
#define input_bool sc_in< bool >

#define integer(x) sc_int<x>
#define unsigned_integer(x) sc_uint<x>

#define output_int(x) sc_out< sc_int<x> >
#define output_unsigned_int(x) sc_out< sc_uint<x> >
#define output_bool sc_out< bool >


int sc_main(int argc, char *argv[])
{
	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING ); 

	sc_signal<bool> a, b, Cin, sum, Cout;

	test_bench tb("Test_Bench");
	tb << a << b << Cin << sum << Cout;

	full_adder f("Full_Adder");
	f << a << b << Cin << Cout << sum;

	//Dumping into VCD
	sc_trace_file *trace = sc_create_vcd_trace_file("full_adder");
	sc_trace(trace, a, "A");
	sc_trace(trace, b, "B");
	sc_trace(trace, Cin, "Cin");
	sc_trace(trace, sum, "Sum");
	sc_trace(trace, Cout, "Cout");

	//Each clock cycle is 10 ns
	//100 clock cycles - 1000 ns
	sc_start(90, SC_NS); 
	cout<<endl<<endl;

	sc_close_vcd_trace_file(trace);

	return 0;
}