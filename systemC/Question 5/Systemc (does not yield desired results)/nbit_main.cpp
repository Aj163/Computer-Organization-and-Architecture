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
#include "tb_nbit_adder.h"
#include "nbit_adder.h"

//Easier to read in the program!
#define input_int(x) sc_in< sc_int<x> >
#define input_unsigned_int(x) sc_in< sc_uint<x> >
#define input_bool sc_in< bool >

#define integer(x) sc_int<x>
#define unsigned_integer(x) sc_uint<x>

#define output_int(x) sc_out< sc_int<x> >
#define output_unsigned_int(x) sc_out< sc_uint<x> >
#define output_bool sc_out< bool >

#define N 2

int sc_main(int argc, char *argv[])
{
	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING );

	sc_signal<bool> a[N], b[N], sum[N], carry;
	//integer(N) A, B, Sum;

	test_bench tb("Test_Bench");
	for(int i=0; i<N; i++)
		tb << a[i];
	for(int i=0; i<N; i++)
		tb << b[i];
	for(int i=0; i<N; i++)
		tb << sum[i];
	tb << carry;

	nbit_adder nb("nbit_Adder");
	for(int i=0; i<N; i++)
		nb << a[i];
	for(int i=0; i<N; i++)
		nb << b[i];
	for(int i=0; i<N; i++)
		nb << sum[i];
	nb << carry;

	//Dumping into VCD
	sc_trace_file *trace = sc_create_vcd_trace_file("nbit_adder");

	char sa[50] = "A___";
	for(int i=0; i<N; i++)
	{
		sa[1] = i/100 + '0';
		sa[2] = (i%100)/10 + '0';
		sa[3] = (i%10) + '0';
		sc_trace(trace, a[i], sa);
	}
	//sc_trace(trace, B, "B");
	//sc_trace(trace, Sum, "Sum");

	sc_start((1<<N)*(1<<N)*10+10, SC_NS);
	cout<<endl<<endl;

	sc_close_vcd_trace_file(trace);

	return 0;
}
