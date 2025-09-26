// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode42.h for the primary calling header

#include "Vencode42__pch.h"
#include "Vencode42__Syms.h"
#include "Vencode42___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__stl(Vencode42___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vencode42___024root___eval_triggers__stl(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_triggers__stl\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vencode42___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
