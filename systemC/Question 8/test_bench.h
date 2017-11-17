#include <systemc.h>

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

SC_MODULE(test_bench_driver){
  sc_out< bool > clk,rst;
  sc_in< bool > real_clk;
  sc_out< bool > inp[32];


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

    inp[2].write(1);
    inp[5].write(1);
    inp[10].write(1);
    pulse();

    inp[2].write(0);
    inp[7].write(1);
    inp[11].write(1);
    pulse();

    rst.write(1);
    wait();

    for(int i = 0;i<32;i++){
      inp[i].write(0);
    }
    inp[20].write(1);
    inp[4].write(1);
    inp[0].write(1);


    rst.write(0);
    wait();

    inp[0].write(1);
    inp[5].write(1);
    inp[1].write(1);
    pulse();

    inp[0].write(0);
    inp[5].write(0);
    inp[10].write(1);
    inp[2].write(1);
    inp[31].write(1);
    inp[28].write(1);
    pulse();

    sc_stop();


  }

  SC_CTOR(test_bench_driver){
    SC_THREAD(run);
    sensitive << real_clk.pos();
  }
};

SC_MODULE(test_bench_monitor){

  sc_in< bool > clk,real_clk,rst;
  sc_in< bool > inp[32],out[32];
  sc_out< sc_int<32> > inp_sig, out_sig;

  void run(){
    if(clk.read()||rst.read()){
      cout<<"\tRESET =  "<<rst.read()<<"  Input = ";
      for(int i = 31;i>=0;i--){
        cout<< inp[i].read();
      }
      cout<<"  Stored = ";
      for(int i = 31;i>=0;i--){
        cout<< out[i].read();
      }
      cout<<"\n"<<endl;
      long tempa = 0,tempb = 0;
      for(int i = 0;i<32;i++){
        if(inp[i].read() == 1){
          tempa = tempa+(long)pow(2,i);
        if(out[i].read()==1)
          tempb = tempb+(long)pow(2,i);
        }
      }
      inp_sig.write(tempa);
      out_sig.write(tempb);

    }
  }

  SC_CTOR(test_bench_monitor){
    SC_METHOD(run);
    sensitive << real_clk.pos();
  }
};
