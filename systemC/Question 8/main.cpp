#include <systemc.h>
#include "register.h"
#include "test_bench.h"

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

int sc_main (int argc,char* argv[]){


  sc_signal< bool > clk,rst;
  sc_signal< bool > inp_sig[32],out_sig[32];
  sc_clock clk_sig("clk_sig",10,SC_NS);
  sc_signal< sc_int<32> > out_sig_temp,inp_sig_temp;

  sc_trace_file *Trace;


  test_bench_driver tbd("test_bench_driver");
  for(int i =0;i<32;i++)
    tbd.inp[i](inp_sig[i]);
  tbd.rst(rst);
  tbd.clk(clk);
  tbd.real_clk(clk_sig);

  Register r ("Register");
  for(int i= 0;i<32;i++){
    r.inp[i](inp_sig[i]);
    r.out[i](out_sig[i]);
  }
  r.rst(rst);
  r.clk(clk);



  test_bench_monitor tbm("test_bench_monitor");
  for(int i = 0;i<32;i++){
    tbm.inp[i](inp_sig[i]);
    tbm.out[i](out_sig[i]);
  }
  tbm.rst(rst);
  tbm.clk(clk);
  tbm.real_clk(clk_sig);
  tbm.out_sig(out_sig_temp);
  tbm.inp_sig(inp_sig_temp);


  Trace = sc_create_vcd_trace_file("Register");
  sc_trace(Trace,rst,"RESET");
  sc_trace(Trace,clk,"Clk");
  sc_trace(Trace,inp_sig_temp,"Input");
  sc_trace(Trace,out_sig_temp,"Stored");


  sc_start();
  sc_close_vcd_trace_file(Trace);
  return 0;
}
