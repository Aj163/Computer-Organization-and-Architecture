#include <systemc.h>
#include "flip_flop.h"
#include "test_bench.h"

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

int sc_main (int argc,char* argv[]){


  sc_signal< bool > d_in,q_out,q__out,clk,rst;
  sc_clock clk_sig("clk_sig",10,SC_NS);

  sc_trace_file *Trace;


  test_bench_driver tbd("test_bench_driver");
  tbd.d(d_in);
  tbd.rst(rst);
  tbd.clk(clk);
  tbd.real_clk(clk_sig);

  flip_flop ff("flip_flop");
  ff.d(d_in);
  ff.q(q_out);
  ff.q_(q__out);
  ff.rst(rst);
  ff.clk(clk);

  test_bench_monitor tbm("test_bench_monitor");
  tbm.d(d_in);
  tbm.q(q_out);
  tbm.q_(q__out);
  tbm.clk(clk);
  tbm.rst(rst);
  tbm.real_clk(clk_sig);


  Trace = sc_create_vcd_trace_file("D_Flip_Flop");
  sc_trace(Trace,clk,"Clk");
  sc_trace(Trace,d_in,"D");
  sc_trace(Trace,q_out,"Q");
  sc_trace(Trace,q__out,"QNeg");


  sc_start();
  sc_close_vcd_trace_file(Trace);
  return 0;
}
