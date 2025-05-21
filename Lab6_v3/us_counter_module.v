module us_counter(
  input clk,
  output reg [31:0] count
);
reg [31:0] count0;
parameter divisor = 32'd50;
initial begin
	count0 = 32'd0;
	count = 32'd0;
end
always @(posedge clk) begin
    	// count0 converts the 50MHz input clock to a 1MHz clock
    	// we increment the count output register according to the 1MHz clock
  	count0 <= count0 + 32'd1;
  	if (count0 == (divisor - 1)) begin
        	count0  <= 0;
        	count <= count + 1;
    	end
	end
endmodule
