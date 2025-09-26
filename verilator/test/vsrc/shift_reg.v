module shift_reg
#(parameter MAX_COUNT=250000)
(
	input clk,
	input rstn,
	output reg[6:0]out
);
reg [17:0] count;
always(posedge clk or negedge rstn)begin
	if(!rstn)
		count<=18'b0;
	else if(count==MAX_COUNT-1)
		count<=18'b0;
	else count<=count+1'b1;
end
always(posedge clk or negedge rstn)begin
	if(!rstn)
		out<=7'b0;
	else if((out==7'd100)&&(count==MAX_COUNT-1))
		out<=7'b0;
	else if(count==MAX_COUNT-1)
		out<=out+1'b1;
	else out<=out;
end
endmodule
