#include <systemc.h>

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

SC_MODULE(flip_flop){
  sc_in< bool > d,clk,rst;
  sc_out< bool > q;

  void d_flip_flop(){
    if(rst.read()){
        q.write(0);
        // q_.write(1);
        return;
    }

    bool temp = d.read();
    q.write(temp);
    // q_.write(!temp);
  }

  SC_CTOR(flip_flop){
    SC_METHOD(d_flip_flop);
    sensitive << clk.pos()<<rst;
  }
};
