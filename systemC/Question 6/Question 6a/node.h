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

SC_MODULE (node_b)
{
	input_unsigned_int(10) rmsg;
	output_unsigned_int(10) smsg;

	void send()
	{
		wait(10, SC_NS);
		while(true)
		{
			wait(20, SC_NS);
			smsg.write(rand()%1024);
		}
	}

	void receive()
	{
		cout<<"\n\tReceived by B : "<<rmsg.read()<<"\t Time : "<<sc_time_stamp();
	}

	SC_CTOR (node_b)
	{
		SC_THREAD(send);

		SC_METHOD(receive);
		sensitive << rmsg;
	}
};

SC_MODULE (node_a)
{
	input_unsigned_int(10) rmsg;
	output_unsigned_int(10) smsg;

	void send()
	{
		while(true)
		{
			wait(20, SC_NS);
			smsg.write(rand()%1024);
		}
	}

	void receive()
	{
		cout<<"\n\tReceived by A : "<<rmsg.read()<<"\t Time : "<<sc_time_stamp();
	}

	SC_CTOR (node_a)
	{
		SC_THREAD(send);

		SC_METHOD(receive);
		sensitive << rmsg;
	}
};
