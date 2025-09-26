module barrel_shifter(
	input			clk	,
	input 		[7:0]	din	,	
	input 		[2:0]	shamt	,
	input 			L_R	,
	input 			A_L	,
	output  reg	[7:0]	dout
);
reg sign=din[7];
always@(posedge clk)begin
	if(A_L)begin
		if(L_R)
			dout<=din<<shamt;
		else begin
			dout<={sign,{din>>shamt}[6:0]};
		end
	end
	else begin
		if(L_R)
			dout<=din<<shamt;
		else dout<=din>>shamt;
	end
		
end
endmodule
