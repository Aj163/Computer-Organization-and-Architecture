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
#include "full_adder.h"
#include "equals.h"

//Easier to read in the program!
#define input_int(x) sc_in< sc_int<x> >
#define input_unsigned_int(x) sc_in< sc_uint<x> >
#define input_bool sc_in< bool >

#define integer(x) sc_int<x>
#define unsigned_integer(x) sc_uint<x>

#define output_int(x) sc_out< sc_int<x> >
#define output_unsigned_int(x) sc_out< sc_uint<x> >

#define N 2

SC_MODULE(nbit_adder)
{
	sc_in< bool > a[N], b[N];
	sc_out< bool > sum[N], carry;

	sc_signal< bool > t2[N+1], t1[N+1];

	// sc_signal< bool > t1,t3;
	full_adder *h[N];
	equal *eq[N+1];

	// void run(){
	// 	for(int i=0;i<=N;i++)
	// 		cout<<"---i = "<<i<<"---"<<t1[i]<<"---"<<t2[i];
	// }

	SC_CTOR(nbit_adder)
	{


		// eq[0] = new equal("equal");
		// *eq[0] << t2[0] << t1[0];

		char s[50] = "nbit_adder___";
		char s2[10] = "equal__";
		for(int i=1; i<=N; i++)
		{
			s[10] = i/100 + '0';
			s[11] = (i%100)/10 + '0';
			s[12] = (i%10) + '0';

			s2[5] = i/100 + '0';
			s2[6] = (i%100)/10 + '0';
			s2[7] = i%10 + '0';



			h[i-1] = new full_adder(s);
			if(i==N)
				*h[i-1] << a[i-1] << b[i-1] << t1[i-1] << carry << sum[i-1];
			else{
				cout<<"---"<<t2[i-1]<<"---";

				*h[i-1] << a[i-1] << b[i-1] << t1[i-1] << t2[i-1] << sum[i-1];
				eq[i]  = new equal(s2);
				*eq[i] <<t2[i-1]<<t1[i];
			}


			// SC_METHOD(run);
			// for(int i=0;i<=N;i++)
			// 	sensitive <<t1[i]<<t2[i];

		}
	}
};
