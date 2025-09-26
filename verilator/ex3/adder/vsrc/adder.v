module adder(
	input a,
	input b,
	input ci,
	output s,
	output co
);
assign s=(~a&~b&ci)|(a&~b&~ci)|(a&b&ci)|(~a&b&~ci);
assign co=(a&b)|(b&ci)|(a&ci);
endmodule
