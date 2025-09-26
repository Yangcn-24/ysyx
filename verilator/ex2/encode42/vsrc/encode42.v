module encode42(
	input en,
	input [3:0]x,
	output reg[1:0]y
);
always@(*)begin
	if(!en) y=2'b00;
	else begin
		casez(x)
			4'b1???:y=2'b11;
			4'b01??:y=2'b10;
			4'b001?:y=2'b01;
			4'b0001:y=2'b00;
			default:y=2'b00;
		endcase
	end
end
endmodule
