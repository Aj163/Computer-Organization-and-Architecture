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


SC_MODULE(test_bench)
{
	output_bool a, b, Cin;
	input_bool sum, Cout;

	SC_CTOR(test_bench)
	{
		SC_THREAD(run);
		sensitive << a <<b <<Cin;
	}

	void run()
	{
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				for(int k=0; k<2; k++)
				{
					a.write(i);
					b.write(j);
					Cin.write(k);
					wait(10, SC_NS);

					cout<<"\n\tA = "<<a<<", B = "<<b<<", Cin = "<<Cin<<endl;
					cout<<"\tSum = "<<sum<<", Cout = "<<Cout<<endl;
				}
		
		a.write(0);
		b.write(0);
		Cin.write(0);
	}
};