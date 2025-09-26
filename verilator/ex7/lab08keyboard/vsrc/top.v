module top(
    input clk,
    input rst,
    input ps2_clk,
    input ps2_data,
    output[7:0] seg1,seg2,seg3,seg4,seg5,seg6,seg7,seg8
  );
  reg [7:0] ps2out;
  reg [23:0] ps2segin ;
  reg ps2ready,ps2next,ps2over;
  ps2_keyboard ps2keyboard(.clk(clk),
                           .clrn(~rst), //低电平复位
                           .ps2_clk(ps2_clk),
                           .ps2_data(ps2_data),
                           .data(ps2out),
                           .ready(ps2ready),
                           .nextdata_n(ps2next),
                           .overflow(ps2over)
                          );

  /***************************三段式状态机*******************************/

  parameter stateRead = 4'b0001;
  parameter stateNotify = 4'b0010; //拉低nextdata_n,通知读取完毕
  parameter stateNotify2 = 4'b0100;//拉低nextdata_n,通知读取完毕
  parameter stateIdle = 4'b1000;
  reg [3:0] state_current,state_next;
  //同步状态转移
  always @(posedge clk or posedge rst)
  begin
    if (rst)
    begin
      state_current<=stateIdle;
    end
    else
    begin
      state_current<=state_next;
    end
  end
  //异步改变状态
  always @(*)
  begin
    case (state_current)
      stateIdle:
      begin
        state_next=(ps2ready==1'b1)?stateRead:stateIdle;
      end
      stateRead:
      begin
        state_next=stateNotify;
      end
      stateNotify:
      begin
        state_next=stateNotify2;
      end
      stateNotify2:
      begin
        state_next=stateIdle;
      end
      default:
        state_next=stateIdle;
    endcase
  end
  //每个状态的输出
  always @(posedge clk)
  begin
    case (state_current)
      stateIdle:
      begin
        ps2next<=1;//默认拉高
      end
      stateNotify:
      begin
        ps2next<=0;//总线拉低
      end
      stateNotify2:
      begin
        ps2next<=0;//总线拉低
      end
      stateRead:
      begin
        ps2segin[23:0] <={ps2segin[15:0],ps2out[7:0]};//保存读取的最后三个值
      end
      default:
      begin
        ps2next<=1;//默认拉高
      end
    endcase
  end
  /*********************************************************************/

  /**
  * 如果读取到的最后三个值是 (A,0XF0,A)形式，则是断码，关闭数码管显示
  * (eg:有bug,找了很久没有找出来，程序复位时，segen的值是1，不是0
  * 经过排查，为 if 语句出错，但找不到原因。)
  **/
  reg segen  ; //数码管控制端口
  always @(*)
  begin
    if(rst) segen= 0;
    else if((ps2segin[15:8]==8'hf0)
        &&ps2segin[7:0]==ps2segin[23:16])
    begin
      segen = 0;
    end
    else
    begin
      segen = 1;
    end
  end


  /*当按下键盘时，segen = 1,数码管亮
  * 松开键盘时，segen = 0,数码管灭
  * 通过捕获 segen 的上升沿，或下降沿，即可获取按下键盘的次数
  */
  reg [3:0 ]segcountl ,segcounth;
  always @(negedge segen) begin
    if(rst) begin
    	segcounth <= 4'd0;
    	segcountl <= 4'd0;
    end
    else if (segcountl==4'd9)
    begin
      segcounth <= segcounth +4'd1;
      segcountl <= 4'd0;
    end
    else
    begin
      segcountl <= segcountl +4'd1;
    end
  end
  /* 键盘扫描码显示 */
  seg seglow1 (.in(ps2segin[3:0]), .out(seg1),.en(segen ));
  seg seghigh1 (.in(ps2segin[7:4]), .out(seg2),.en(segen));
  /* 键盘 ASCII 码显示 */
  reg  [7:0]ascii;
  toASCII ps2ascii(.addr(ps2segin[7:0]),.val(ascii));

  seg seglow2 (.in(ascii[3:0]), .out(seg3),.en(segen ));
  seg seghigh2 (.in(ascii[7:4]), .out(seg4),.en(segen));

  /* 没有用到，不显示 */
  seg seglow3 (.in(ps2segin[19:16]), .out(seg5),.en(1'd0 ));
  seg seghigh3 (.in(ps2segin[23:20]), .out(seg6),.en(1'd0 ));

  /* 计数显示 */
  seg segnuml (.in(segcountl), .out(seg7),.en(1'd1 ));
  seg seghnumh (.in(segcounth), .out(seg8),.en(1'd1));

endmodule
