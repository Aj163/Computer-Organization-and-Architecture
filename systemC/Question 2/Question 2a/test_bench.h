#include <systemc.h>

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

SC_MODULE(test_bench_driver){
  sc_out< sc_uint<16> > a;
  sc_in< bool > clk;

  void run(){
    //wait();
    wait();
    for(int i=0;i<16;i++){

        a.write((sc_uint<16>)pow(2,i));
        wait();
    }

    sc_stop();


  }

  SC_CTOR(test_bench_driver){
    SC_THREAD(run);
    sensitive << clk.pos();
  }
};

SC_MODULE(test_bench_monitor){

  sc_in< sc_uint<16> > a;
  sc_in< sc_uint<4> > b;
  sc_in< bool > clk;

  void run(){
    int inb;
    long long ina;
    


    ina = (long long)a.read();

    inb = (int)b.read();



    int arr[16];
    long long temp;

    temp = ina;

    cout <<"\t\t"<<"input = ";
    for(int i=0;i<16;i++){
      arr[i] = temp%2;
      temp = temp/2;
    }
    for(int i=15;i>=0;i--){
      cout<<arr[i];
    }
    cout<<"\toutput = "<<inb;
    cout<<endl;


  }

  SC_CTOR(test_bench_monitor){
    SC_METHOD(run);
    sensitive << clk.pos();
  }
};
