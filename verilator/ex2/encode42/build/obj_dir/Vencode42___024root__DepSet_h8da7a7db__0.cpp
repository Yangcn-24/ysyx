// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode42.h for the primary calling header

#include "Vencode42__pch.h"
#include "Vencode42__Syms.h"
#include "Vencode42___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__ico(Vencode42___024root* vlSelf);
#endif  // VL_DEBUG

void Vencode42___024root___eval_triggers__ico(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_triggers__ico\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vencode42___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__act(Vencode42___024root* vlSelf);
#endif  // VL_DEBUG

void Vencode42___024root___eval_triggers__act(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_triggers__act\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vencode42___024root___dump_triggers__act(vlSelf);
    }
#endif
}
