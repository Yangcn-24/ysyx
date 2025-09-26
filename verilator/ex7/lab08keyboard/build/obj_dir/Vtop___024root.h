// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ top__DOT__segen;
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_OUT8(seg1,7,0);
    VL_OUT8(seg2,7,0);
    VL_OUT8(seg3,7,0);
    VL_OUT8(seg4,7,0);
    VL_OUT8(seg5,7,0);
    VL_OUT8(seg6,7,0);
    VL_OUT8(seg7,7,0);
    VL_OUT8(seg8,7,0);
    CData/*0:0*/ top__DOT__ps2ready;
    CData/*0:0*/ top__DOT__ps2next;
    CData/*0:0*/ top__DOT__ps2over;
    CData/*3:0*/ top__DOT__state_current;
    CData/*3:0*/ top__DOT__state_next;
    CData/*3:0*/ top__DOT__segcountl;
    CData/*3:0*/ top__DOT__segcounth;
    CData/*7:0*/ top__DOT__ascii;
    CData/*2:0*/ top__DOT__ps2keyboard__DOT__w_ptr;
    CData/*2:0*/ top__DOT__ps2keyboard__DOT__r_ptr;
    CData/*3:0*/ top__DOT__ps2keyboard__DOT__count;
    CData/*2:0*/ top__DOT__ps2keyboard__DOT__ps2_clk_sync;
    CData/*0:0*/ top__DOT__ps2keyboard__DOT____Vlvbound_h9ff2922b__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__segen__0;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ top__DOT__ps2keyboard__DOT__buffer;
    IData/*23:0*/ top__DOT__ps2segin;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> top__DOT__ps2keyboard__DOT__fifo;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
