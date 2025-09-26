// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo
                               [vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr]),8);
        bufp->chgIData(oldp+1,(vlSelfRef.top__DOT__ps2segin),24);
        bufp->chgBit(oldp+2,(vlSelfRef.top__DOT__ps2ready));
        bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__ps2next));
        bufp->chgBit(oldp+4,(vlSelfRef.top__DOT__ps2over));
        bufp->chgCData(oldp+5,(vlSelfRef.top__DOT__ascii),8);
        bufp->chgCData(oldp+6,((0xffU & vlSelfRef.top__DOT__ps2segin)),8);
        bufp->chgSData(oldp+7,(vlSelfRef.top__DOT__ps2keyboard__DOT__buffer),10);
        bufp->chgCData(oldp+8,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[0]),8);
        bufp->chgCData(oldp+9,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[1]),8);
        bufp->chgCData(oldp+10,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[2]),8);
        bufp->chgCData(oldp+11,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[3]),8);
        bufp->chgCData(oldp+12,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[4]),8);
        bufp->chgCData(oldp+13,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[5]),8);
        bufp->chgCData(oldp+14,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[6]),8);
        bufp->chgCData(oldp+15,(vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[7]),8);
        bufp->chgCData(oldp+16,(vlSelfRef.top__DOT__ps2keyboard__DOT__w_ptr),3);
        bufp->chgCData(oldp+17,(vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr),3);
        bufp->chgCData(oldp+18,(vlSelfRef.top__DOT__ps2keyboard__DOT__count),4);
        bufp->chgCData(oldp+19,(vlSelfRef.top__DOT__ps2keyboard__DOT__ps2_clk_sync),3);
        bufp->chgBit(oldp+20,((IData)((4U == (6U & (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__ps2_clk_sync))))));
        bufp->chgCData(oldp+21,((0xfU & (vlSelfRef.top__DOT__ps2segin 
                                         >> 4U))),4);
        bufp->chgCData(oldp+22,((0xfU & ((IData)(vlSelfRef.top__DOT__ascii) 
                                         >> 4U))),4);
        bufp->chgCData(oldp+23,((0xfU & (vlSelfRef.top__DOT__ps2segin 
                                         >> 0x14U))),4);
        bufp->chgCData(oldp+24,((0xfU & vlSelfRef.top__DOT__ps2segin)),4);
        bufp->chgCData(oldp+25,((0xfU & (IData)(vlSelfRef.top__DOT__ascii))),4);
        bufp->chgCData(oldp+26,((0xfU & (vlSelfRef.top__DOT__ps2segin 
                                         >> 0x10U))),4);
    }
    bufp->chgBit(oldp+27,(vlSelfRef.clk));
    bufp->chgBit(oldp+28,(vlSelfRef.rst));
    bufp->chgBit(oldp+29,(vlSelfRef.ps2_clk));
    bufp->chgBit(oldp+30,(vlSelfRef.ps2_data));
    bufp->chgCData(oldp+31,(vlSelfRef.seg1),8);
    bufp->chgCData(oldp+32,(vlSelfRef.seg2),8);
    bufp->chgCData(oldp+33,(vlSelfRef.seg3),8);
    bufp->chgCData(oldp+34,(vlSelfRef.seg4),8);
    bufp->chgCData(oldp+35,(vlSelfRef.seg5),8);
    bufp->chgCData(oldp+36,(vlSelfRef.seg6),8);
    bufp->chgCData(oldp+37,(vlSelfRef.seg7),8);
    bufp->chgCData(oldp+38,(vlSelfRef.seg8),8);
    bufp->chgCData(oldp+39,(vlSelfRef.top__DOT__state_current),4);
    bufp->chgCData(oldp+40,(vlSelfRef.top__DOT__state_next),4);
    bufp->chgBit(oldp+41,(vlSelfRef.top__DOT__segen));
    bufp->chgCData(oldp+42,(vlSelfRef.top__DOT__segcountl),4);
    bufp->chgCData(oldp+43,(vlSelfRef.top__DOT__segcounth),4);
    bufp->chgBit(oldp+44,((1U & (~ (IData)(vlSelfRef.rst)))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
