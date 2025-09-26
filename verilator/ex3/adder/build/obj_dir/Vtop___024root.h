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
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_IN8(ci,0,0);
    VL_OUT8(s,3,0);
    VL_OUT8(co,0,0);
    CData/*0:0*/ top__DOT__w_01;
    CData/*0:0*/ top__DOT__w_12;
    CData/*0:0*/ top__DOT__w_23;
    CData/*0:0*/ top__DOT__inst_0__DOT____VdfgRegularize_h23828683_0_3;
    CData/*0:0*/ top__DOT__inst_1__DOT____VdfgRegularize_h23828683_0_3;
    CData/*0:0*/ top__DOT__inst_2__DOT____VdfgRegularize_h23828683_0_3;
    CData/*0:0*/ top__DOT__inst_3__DOT____VdfgRegularize_h23828683_0_3;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

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
