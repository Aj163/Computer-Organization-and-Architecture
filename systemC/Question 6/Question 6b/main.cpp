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
#include "node.h"

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

	srand(time(0));
	sc_signal< unsigned_integer(10) > amsg;
	sc_signal< unsigned_integer(10) > bmsg[3];

	node_a na("NodeA");
	na<<bmsg[0]<<bmsg[1]<<bmsg[2]<<amsg;

	node_b nb("NodeB");
	nb<<amsg<<bmsg[0]<<bmsg[1]<<bmsg[2];

	

	//Dumping into VCD
	sc_trace_file *trace = sc_create_vcd_trace_file("msg");
	sc_trace(trace, amsg, "Msg_A");
	sc_trace(trace, bmsg[0], "Msg_B1");
	sc_trace(trace, bmsg[1], "Msg_B2");
	sc_trace(trace, bmsg[2], "Msg_B3");

	sc_start(410, SC_NS);
	cout<<endl<<endl;
	
	sc_close_vcd_trace_file(trace);

	return 0;
}