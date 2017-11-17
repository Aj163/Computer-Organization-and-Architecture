#include <systemc.h>

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

SC_MODULE(test_bench_driver){
  sc_out< bool > d,clk,rst;
  sc_in< bool > real_clk;

  void pulse(){
    clk.write(0);
    wait();
    clk.write(1);
    wait();
  }
  void run(){
    //wait();
    rst.write(1);
    wait();

    rst.write(0);
    wait();		

    d.write(0);
    pulse();

    d.write(1);
    pulse();

    d.write(0);
    pulse();
  
    sc_stop();


  }

  SC_CTOR(test_bench_driver){
    SC_THREAD(run);
    sensitive << real_clk.pos();
  }
};

SC_MODULE(test_bench_monitor){

  sc_in< bool >d,q,q_,clk,real_clk,rst;

  void run(){
    if(clk.read()||rst.read())
      cout<<"\tRESET =  "<<rst.read()<<"  D = "<<d.read()<<"  Q = "<<q.read()<<"  QNeg = "<<q_.read()<<endl;


  }

  SC_CTOR(test_bench_monitor){
    SC_METHOD(run);
    sensitive << real_clk.pos();
  }
};
