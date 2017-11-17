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
	output_unsigned_int(10) smsg[3];

	void receive()
	{
		for(int i=0; i<3; i++)
			smsg[i].write(rand()%1024);
	}

	SC_CTOR (node_b)
	{
		SC_METHOD(receive);
		sensitive << rmsg;
	}
};

SC_MODULE (node_a)
{
	input_unsigned_int(10) rmsg[3];
	output_unsigned_int(10) smsg;
	int temp;

	void send()
	{
		while(true)
		{
			wait(rand()%50, SC_NS);
			temp = rand()%1024;
			smsg.write(temp);
			//cout<<"\n\tSent by A : "<<temp;
		}
	}

	void receive()
	{
		cout<<"\n\tSent by A : "<<temp;
		cout<<"\tReceived by A : "<<rmsg[0].read()<<"\t"<<rmsg[1].read()<<"\t"<<rmsg[2].read()<<"\tTime : "<<sc_time_stamp();
	}

	SC_CTOR (node_a)
	{
		temp = 0;
		SC_THREAD(send);

		SC_METHOD(receive);
		sensitive << rmsg[0] << rmsg[1] << rmsg[2];
	}
};
