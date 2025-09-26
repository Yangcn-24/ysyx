// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux41.h for the primary calling header

#ifndef VERILATED_VMUX41___024ROOT_H_
#define VERILATED_VMUX41___024ROOT_H_  // guard

#include "verilated.h"


class Vmux41__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmux41___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(X0,1,0);
    VL_IN8(X1,1,0);
    VL_IN8(X2,1,0);
    VL_IN8(X3,1,0);
    VL_IN8(Y,1,0);
    VL_OUT8(F,1,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmux41__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmux41___024root(Vmux41__Syms* symsp, const char* v__name);
    ~Vmux41___024root();
    VL_UNCOPYABLE(Vmux41___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
