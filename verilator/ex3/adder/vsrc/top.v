module top(
	input [3:0]a,
	input [3:0]b,
	input ci,
	output[3:0]s,
	output co
);
wire w_01;
wire w_12;
wire w_23;
adder inst_0(
	.a(a[0]),
	.b(b[0]),
	.ci(ci),
	.s(s[0]),
	.co(w_01)
);

adder inst_1(
	.a(a[1]),
	.b(b[1]),
	.ci(w_01),
	.s(s[1]),
	.co(w_12)
);

adder inst_2(
	.a(a[2]),
	.b(b[2]),
	.ci(w_12),
	.s(s[2]),
	.co(w_23)
);

adder inst_3(
	.a(a[3]),
	.b(b[3]),
	.ci(w_23),
	.s(s[3]),
	.co(co)
);
endmodule
