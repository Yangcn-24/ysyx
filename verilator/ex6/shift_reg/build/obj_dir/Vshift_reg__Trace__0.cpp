// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vshift_reg__Syms.h"


void Vshift_reg___024root__trace_chg_0_sub_0(Vshift_reg___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vshift_reg___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root__trace_chg_0\n"); );
    // Init
    Vshift_reg___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vshift_reg___024root*>(voidSelf);
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vshift_reg___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vshift_reg___024root__trace_chg_0_sub_0(Vshift_reg___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root__trace_chg_0_sub_0\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rstn));
    bufp->chgBit(oldp+2,(vlSelfRef.in));
    bufp->chgBit(oldp+3,(vlSelfRef.load));
    bufp->chgCData(oldp+4,(vlSelfRef.data),4);
    bufp->chgBit(oldp+5,(vlSelfRef.R_L));
    bufp->chgBit(oldp+6,(vlSelfRef.ena));
    bufp->chgCData(oldp+7,(vlSelfRef.q),4);
}

void Vshift_reg___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root__trace_cleanup\n"); );
    // Init
    Vshift_reg___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vshift_reg___024root*>(voidSelf);
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
