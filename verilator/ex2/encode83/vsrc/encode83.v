module encode83(
	input en,
	input [7:0]x,
	output reg[2:0]y,
	output eo
);
always@(*)begin
	if(!en)begin
		y=3'b0;
		eo=0;
	end
	else begin
		casez(x)
			8'b1???????:begin
				y=3'b111;
				eo=1;
				end
			8'b01??????:begin
				y=3'b110;
				eo=1;
				end
			8'b001?????:begin
				y=3'b101;
				eo=1;
				end
			8'b0001????:begin
				y=3'b100;
				eo=1;
				end
			8'b00001???:begin
				y=3'b011;
				eo=1;
				end
			8'b000001??:begin
				y=3'b010;
				eo=1;
				end
			8'b0000001?:begin
				y=3'b001;
				eo=1;
				end
			8'b00000001:begin
				y=3'b000;
				eo=1;
				end
			default:begin
				y=3'b000;
				eo=0;
				end
		endcase
	end
end
endmodule

