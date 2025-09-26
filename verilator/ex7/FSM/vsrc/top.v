module top(
	input clk,
	input rstn,
	input in,
	output out,
	output [3:0]o_state
);
parameter [3:0]A=4'b0000;
parameter [3:0]B=4'b0001;
parameter [3:0]C=4'b0010;
parameter [3:0]D=4'b0011;
parameter [3:0]E=4'b0100;
parameter [3:0]F=4'b0101;
parameter [3:0]G=4'b0110;
parameter [3:0]H=4'b0111;
parameter [3:0]I=4'b1000;

reg [3:0]state,next_state;
always@(posedge clk or posedge rstn)begin
	if(rstn)
		state<=A;
	else state<=next_state;
end	
always@(*)begin
	case(state)
		A:next_state=in?F:B;
		B:next_state=in?F:C;
		C:next_state=in?F:D;
		D:next_state=in?F:E;
		E:next_state=in?F:E;
		F:next_state=in?G:B;
		G:next_state=in?H:B;
		H:next_state=in?I:B;
		I:next_state=in?I:B;
		default:next_state=A;
	endcase
end
assign out=(state==E)|(state==I);
assign o_state=state;
endmodule
