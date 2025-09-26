// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshift_reg.h for the primary calling header

#include "Vshift_reg__pch.h"
#include "Vshift_reg__Syms.h"
#include "Vshift_reg___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshift_reg___024root___dump_triggers__act(Vshift_reg___024root* vlSelf);
#endif  // VL_DEBUG

void Vshift_reg___024root___eval_triggers__act(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_triggers__act\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.rstn)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rstn__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rstn__0 = vlSelfRef.rstn;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vshift_reg___024root___dump_triggers__act(vlSelf);
    }
#endif
}
