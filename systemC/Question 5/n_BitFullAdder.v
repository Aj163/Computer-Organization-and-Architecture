/*
	Name : 	Ashwin Joisa (16CO104)
			Praveen Raj (16CO115)
	Date : 	16/10/2017
*/

// Define 1-bit Half adder
module halfadder(sum,c_out,a,b);
	output sum,c_out;
	input a,b;
	
	xor(sum,a,b);
	and(c_out,a,b);
	
endmodule


// Define 1-bit Full adder
module fulladd(sum, c_out, a, b, c_in);
    output sum, c_out;
    input a, b, c_in;
    
	wire s1, c1, c2;

    halfadder ha1(s1,c1,a,b);
	halfadder ha2(sum,c2,c_in,s1);
	or(c_out,c1,c2);
	
endmodule 

//nbit_full_adder
module nBitAddSub(a, b, m,sum, cout);
    parameter n = 3;
	
    input[n-1:0] a, b;
    input m;
    output[n-1:0] sum;
    output cout;
    wire[n-1:0] carry;
    genvar i;
    generate
        for(i = 0; i < n; i=i+1) begin
            if(i == 0)
                fulladd fa(sum[0], carry[0], a[0], b[0]^m, m);
            else
                fulladd fa(sum[i], carry[i], a[i], b[i]^m, carry[i-1]);            
        end    
        assign cout = carry[n-1];
    endgenerate
endmodule    
