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
        bufp->chgBit(oldp+0,(vlSelfRef.top__DOT__w_01));
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__w_12));
        bufp->chgBit(oldp+2,(vlSelfRef.top__DOT__w_23));
    }
    bufp->chgCData(oldp+3,(vlSelfRef.a),4);
    bufp->chgCData(oldp+4,(vlSelfRef.b),4);
    bufp->chgBit(oldp+5,(vlSelfRef.ci));
    bufp->chgCData(oldp+6,(vlSelfRef.s),4);
    bufp->chgBit(oldp+7,(vlSelfRef.co));
    bufp->chgBit(oldp+8,((1U & (IData)(vlSelfRef.a))));
    bufp->chgBit(oldp+9,((1U & (IData)(vlSelfRef.b))));
    bufp->chgBit(oldp+10,((1U & (((~ (IData)(vlSelfRef.a)) 
                                  & ((~ (IData)(vlSelfRef.b)) 
                                     & (IData)(vlSelfRef.ci))) 
                                 | (((IData)(vlSelfRef.a) 
                                     & ((~ (IData)(vlSelfRef.b)) 
                                        & (~ (IData)(vlSelfRef.ci)))) 
                                    | (((IData)(vlSelfRef.top__DOT__inst_0__DOT____VdfgRegularize_h23828683_0_3) 
                                        & (IData)(vlSelfRef.ci)) 
                                       | ((~ (IData)(vlSelfRef.a)) 
                                          & ((~ (IData)(vlSelfRef.ci)) 
                                             & (IData)(vlSelfRef.b)))))))));
    bufp->chgBit(oldp+11,((1U & ((IData)(vlSelfRef.a) 
                                 >> 1U))));
    bufp->chgBit(oldp+12,((1U & ((IData)(vlSelfRef.b) 
                                 >> 1U))));
    bufp->chgBit(oldp+13,((1U & (((~ ((IData)(vlSelfRef.a) 
                                      >> 1U)) & ((~ 
                                                  ((IData)(vlSelfRef.b) 
                                                   >> 1U)) 
                                                 & (IData)(vlSelfRef.top__DOT__w_01))) 
                                 | ((((IData)(vlSelfRef.a) 
                                      >> 1U) & ((~ 
                                                 ((IData)(vlSelfRef.b) 
                                                  >> 1U)) 
                                                & (~ (IData)(vlSelfRef.top__DOT__w_01)))) 
                                    | (((IData)(vlSelfRef.top__DOT__inst_1__DOT____VdfgRegularize_h23828683_0_3) 
                                        & (IData)(vlSelfRef.top__DOT__w_01)) 
                                       | ((~ ((IData)(vlSelfRef.a) 
                                              >> 1U)) 
                                          & ((~ (IData)(vlSelfRef.top__DOT__w_01)) 
                                             & ((IData)(vlSelfRef.b) 
                                                >> 1U)))))))));
    bufp->chgBit(oldp+14,((1U & ((IData)(vlSelfRef.a) 
                                 >> 2U))));
    bufp->chgBit(oldp+15,((1U & ((IData)(vlSelfRef.b) 
                                 >> 2U))));
    bufp->chgBit(oldp+16,((1U & (((~ ((IData)(vlSelfRef.a) 
                                      >> 2U)) & ((~ 
                                                  ((IData)(vlSelfRef.b) 
                                                   >> 2U)) 
                                                 & (IData)(vlSelfRef.top__DOT__w_12))) 
                                 | ((((IData)(vlSelfRef.a) 
                                      >> 2U) & ((~ 
                                                 ((IData)(vlSelfRef.b) 
                                                  >> 2U)) 
                                                & (~ (IData)(vlSelfRef.top__DOT__w_12)))) 
                                    | (((IData)(vlSelfRef.top__DOT__inst_2__DOT____VdfgRegularize_h23828683_0_3) 
                                        & (IData)(vlSelfRef.top__DOT__w_12)) 
                                       | ((~ ((IData)(vlSelfRef.a) 
                                              >> 2U)) 
                                          & ((~ (IData)(vlSelfRef.top__DOT__w_12)) 
                                             & ((IData)(vlSelfRef.b) 
                                                >> 2U)))))))));
    bufp->chgBit(oldp+17,((1U & ((IData)(vlSelfRef.a) 
                                 >> 3U))));
    bufp->chgBit(oldp+18,((1U & ((IData)(vlSelfRef.b) 
                                 >> 3U))));
    bufp->chgBit(oldp+19,((1U & (((~ ((IData)(vlSelfRef.a) 
                                      >> 3U)) & ((~ 
                                                  ((IData)(vlSelfRef.b) 
                                                   >> 3U)) 
                                                 & (IData)(vlSelfRef.top__DOT__w_23))) 
                                 | ((((IData)(vlSelfRef.a) 
                                      >> 3U) & ((~ 
                                                 ((IData)(vlSelfRef.b) 
                                                  >> 3U)) 
                                                & (~ (IData)(vlSelfRef.top__DOT__w_23)))) 
                                    | (((IData)(vlSelfRef.top__DOT__inst_3__DOT____VdfgRegularize_h23828683_0_3) 
                                        & (IData)(vlSelfRef.top__DOT__w_23)) 
                                       | ((~ ((IData)(vlSelfRef.a) 
                                              >> 3U)) 
                                          & ((~ (IData)(vlSelfRef.top__DOT__w_23)) 
                                             & ((IData)(vlSelfRef.b) 
                                                >> 3U)))))))));
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
