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

#define N 2

SC_MODULE(test_bench)
{
	output_bool a[N], b[N];
	input_bool sum[N], carry;

	SC_CTOR(test_bench)
	{
		SC_THREAD(run);
		//sensitive << a[N-1];
	}

	void run()
	{
		for(int i=0; i<(1<<N); i++)
			for(int j=0; j<(1<<N); j++)
			{
				for(int k=0; k<N; k++)
					a[N-k-1].write((bool)(((i&(1<<k)) != 0)));
				for(int k=0; k<N; k++)
					b[N-k-1].write((bool)(((j&(1<<k)) != 0)));
				wait(10, SC_NS);

				cout<<"\n\tA = ";
				for(int k=0; k<N; k++)
					cout<<a[k];
				cout<<", B = ";
				for(int k=0; k<N; k++)
					cout<<b[k];
				cout<<", Sum  = ";
				for(int k=0; k<N; k++)
					cout<<sum[k];
				cout<<", Carry = "<<carry;
			}

		for(int k=0; k<N; k++)
		{
			a[k].write(0);
			b[k].write(0);
		}
		sc_stop();
	}
};
