module top(
	input en,
	input [7:0]x,
	output [2:0]y,
	output eo,
	output [6:0]h
);

wire [2:0]w_y;
assign y=w_y;
encode83 inst_encode83(
	.en(en),
	.x(x),
	.y(w_y),
	.eo(eo)
);

bcd7seg inst_bcd7seg(
	.b(w_y),
	.h(h)
);
endmodule
