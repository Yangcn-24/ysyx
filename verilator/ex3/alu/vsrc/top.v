module top(
	input signed[3:0]a,
	input signed[3:0]b,
	input [2:0]mode,
	output reg co,
	output reg zero,
	output reg overflow,
	output reg signed[3:0]f
);
reg [4:0]temp=5'b0;
always@(*)begin
	case(mode)
		3'b000:begin
			temp = {1'b0, a} + {1'b0, b};
			co=temp[4];
			overflow=(a[3]==b[3])&(a[3]!=temp[3]);
			f=temp[3:0];
			
		end
		
		3'b001:begin
			temp = {1'b0, a} - {1'b0, b};
			co=temp[4];
			overflow=(a[3]==(~b[3]))&(a[3]!=temp[3]);
			f=temp[3:0];
		end
		
		3'b010:begin
			f=~a;
			co=0;
			overflow=0;
			temp=5'b0;
		end
		3'b011:begin
			f=a&b;
			co=0;
			overflow=0;
			temp=5'b0;
		end
		
		
		3'b100:begin
			f=a|b;
			co=0;
			overflow=0;
			temp=5'b0;
		end
		
		3'b101:begin
			f=a^b;
			co=0;
			overflow=0;
			temp=5'b0;
		end
		
		3'b110:begin
			f=(a<b)?4'd1:4'd0;
			co=0;
			overflow=0;
			temp=5'b0;
		end
		
		3'b111:begin
			f=(a==b)?4'd1:4'd0;
			co=0;
			overflow=0;
			temp=5'b0;
		end
		default:begin
			f=4'd0;
			co=0;
			overflow=0;
			temp=5'b0;
		end
	endcase
	zero=(f==4'b0)?1'b1:1'b0;

end
endmodule
