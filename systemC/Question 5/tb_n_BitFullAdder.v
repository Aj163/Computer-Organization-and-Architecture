/*
	Name : 	Ashwin Joisa (16CO104)
			Praveen Raj (16CO115)
	Date : 	16/10/2017
*/

module testbench;
    parameter n = 3;
    wire[n-1:0] sum;
    wire cout;
    reg[n-1:0] a, b;
    reg m;
    nBitAddSub uut(
		.a(a), .b(b) , .m(m), .sum(sum), .cout(cout));    
    initial begin 
        $dumpfile("nBitFullAdder.vcd");
        $dumpvars(0, testbench);
        m=0;
        a = 0; b = 0;
		$display("\nOutput for addition operation\n");
		#5 b = 1;
        #5 b = 4;
        #5 b = 6;
        
        #5 a = 2;
		#5 b = 6;
        #5 b = 1;
        
        
        #5 a = 4;
		#5 b = 0;
        #5 b = 2;
		

        #10 m=1;
		$display("\nOutput for subtraction operation\n");
        a = 3; b = 0;
        #5 b = 2;
        #5 b = 4;
        #5 b = 1;
        
        #5 a = 2; 
		#5 b = 5;
        #5 b = 7;
        
        
        #5 a = 5; 
		#5 b = 3;
        #5 b = 0;

            
    end 
    initial begin
        $display("M\tA\tB\tSUM\tCARRY");
        $monitor("%b\t%3b\t%3b\t%3b\t%b",m,a,b,sum,cout); 
    end    
endmodule
