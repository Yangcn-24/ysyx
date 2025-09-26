module shift_reg(
	input 				clk	,
	input 				rstn	,
	input 				in	,	
	input 				load	,
	input 		[3:0]		data	,
	input 				R_L	,
	output  reg	[3:0]		q
);
always@(posedge clk or negedge rstn)begin
	if(!rstn)begin
		q<=4'd1;
	end
	else begin
		if(!load)
			q<=data;
		else begin
			if(R_L)
				q<={in,q[3:1]};
			else if(~R_L)
				q<={q[2:0],in};
			else q<=q;
		end
	end
end
endmodule
