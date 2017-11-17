#include <systemc.h>
#include <math.h>

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

SC_MODULE(Decoder){

  sc_out< sc_uint<16> > a;
  sc_in< sc_uint<4> > b;

  void decode(){
    bool tmpa[16],tmpb[4];
    int b_ = 0;
    long a_ = 0;

    b_ = (int)b.read();


    for(int i=0;i<4;i++){
      if(b_%2==1)
        tmpb[i] = 1;
      else
        tmpb[i] = 0;
      b_ = b_/2;
    }
    tmpa[0] = !tmpb[0] & !tmpb[1] & !tmpb[2] & !tmpb[3];
    tmpa[1] = tmpb[0] & !tmpb[1] & !tmpb[2] & !tmpb[3];
    tmpa[2] = !tmpb[0] & tmpb[1] & !tmpb[2] & !tmpb[3];
    tmpa[3] = tmpb[0] & tmpb[1] & !tmpb[2] & !tmpb[3];
    tmpa[4] = !tmpb[0] & !tmpb[1] & tmpb[2] & !tmpb[3];
    tmpa[5] = tmpb[0] & !tmpb[1] & tmpb[2] & !tmpb[3];
    tmpa[6] = !tmpb[0] & tmpb[1] & tmpb[2] & !tmpb[3];
    tmpa[7] = tmpb[0] & tmpb[1] & tmpb[2] & !tmpb[3];
    tmpa[8] = !tmpb[0] & !tmpb[1] & !tmpb[2] & tmpb[3];
    tmpa[9] = tmpb[0] & !tmpb[1] & !tmpb[2] & tmpb[3];
    tmpa[10] = !tmpb[0] & tmpb[1] & !tmpb[2] & tmpb[3];
    tmpa[11] = tmpb[0] & tmpb[1] & !tmpb[2] & tmpb[3];
    tmpa[12] = !tmpb[0] & !tmpb[1] & tmpb[2] & tmpb[3];
    tmpa[13] = tmpb[0] & !tmpb[1] & tmpb[2] & tmpb[3];
    tmpa[14] = !tmpb[0] & tmpb[1] & tmpb[2] & tmpb[3];
    tmpa[15] = tmpb[0] & tmpb[1] & tmpb[2] & tmpb[3];


    for(int i=15;i>=0;i--){
      if(tmpa[i])
        a_ = a_+(long)pow(2,i);
    }
    a.write((sc_uint<16>)a_);


  }
  SC_CTOR(Decoder){
    SC_METHOD(decode);
    sensitive << b;

  }
};
