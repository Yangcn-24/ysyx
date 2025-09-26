module top(
	input clk,
	input rstn,
	input [7:0]din,
	output [7:0]dout,
	output [7:0] seg_high,seg_low
	
);
wire [3:0]seg1,seg2;
reg [7:0]r_data;
always@(posedge clk or posedge rstn)begin
	if(rstn)
		r_data<=din;
	else begin
		r_data<={r_data[0]^r_data[2]^r_data[3]^r_data[4],r_data[7:1]};
	end
end
assign dout=r_data;
assign seg1=r_data[7:4];
assign seg2=r_data[3:0];

seg inst_seg1(
	.in(seg1),
	.out(seg_high)
);

seg inst_seg2(
	.in(seg2),
	.out(seg_low)
);
endmodule
