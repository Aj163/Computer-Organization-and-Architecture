#include <systemc.h>
#include <math.h>

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

SC_MODULE(Encoder){

  sc_in< sc_uint<16> > a;
  sc_out< sc_uint<4> > b;

  void encode(){
    bool tmpa[16],tmpb[4];
    int b_ = 0;
    long a_;
  
    a_ = (long)a.read();


    for(int i=0;i<16;i++){
      if(a_%2==1)
        tmpa[i] = 1;
      else
        tmpa[i] = 0;
      a_ = a_/2;
    }

    tmpb[0] = (tmpa[1]|tmpa[3]|tmpa[5]|tmpa[7]|tmpa[9]|tmpa[11]|tmpa[13]|tmpa[15]);
    tmpb[1] = (tmpa[2]|tmpa[3]|tmpa[6]|tmpa[7]|tmpa[10]|tmpa[11]|tmpa[14]|tmpa[15]);
    tmpb[2] = (tmpa[4]|tmpa[5]|tmpa[6]|tmpa[7]|tmpa[12]|tmpa[13]|tmpa[14]|tmpa[15]);
    tmpb[3] = (tmpa[8]|tmpa[9]|tmpa[10]|tmpa[11]|tmpa[12]|tmpa[13]|tmpa[14]|tmpa[15]);

    for(int i=3;i>=0;i--){
      if(tmpb[i])
        b_ = b_+(int)pow(2,i);
    }
    b.write((sc_uint<4>)b_);


  }
  SC_CTOR(Encoder){
    SC_METHOD(encode);
    sensitive << a;

  }
};
