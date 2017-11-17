#include <systemc.h>
#include <string.h>
#include <stdlib.h>
#include "flip_flop.h"

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

SC_MODULE(Register){
  sc_in< bool > rst,clk;
  sc_in< bool > inp[32];
  sc_out< bool > out[32];
  flip_flop *ff[32];


  SC_CTOR(Register){
    char a[] = "flip_flop__";
    for(int i = 0;i<32;i++){
      int temp = i;
      a[(strlen(a)-1)] = (temp%10)+'0' ;
      temp = temp/10;
      a[(strlen(a)-2)] = temp%10 +'0';
      ff[i] = new flip_flop(a);

      ff[i]->clk(clk);
      ff[i]->rst(rst);
      ff[i]->d(inp[i]);
      ff[i]->q(out[i]);
    }

}

};
