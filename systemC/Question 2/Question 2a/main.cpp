#include <systemc.h>
#include "encoder.h"
#include "test_bench.h"

/*
  Name :  Ashwin Joisa (16CO104)
      Praveen Raj (16CO115)
  Date :  16/10/2017
*/

int sc_main (int argc,char* argv[]){


  sc_signal< sc_uint<16> > a_in;
  sc_signal< sc_uint<4> > b_in;
  sc_clock clk_sig("clk_sig",10,SC_NS);

  sc_trace_file *Trace;


  test_bench_driver tbd("test_bench_driver");
  tbd.a(a_in);
  tbd.clk(clk_sig);

  Encoder en("Encoder");
  en.a(a_in);
  en.b(b_in);

  test_bench_monitor tbm("test_bench_monitor");
  tbm.a(a_in);
  tbm.b(b_in);
  tbm.clk(clk_sig);


  Trace = sc_create_vcd_trace_file("Encoder");
  sc_trace(Trace,a_in,"input");
  sc_trace(Trace,b_in,"output");


  sc_start();
  sc_close_vcd_trace_file(Trace);
  return 0;
}
