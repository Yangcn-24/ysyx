// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+4,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+6,0,"ci",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+8,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+5,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+6,0,"ci",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+8,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"w_01",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"w_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"w_23",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("inst_0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+9,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"ci",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+12,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"ci",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+15,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"ci",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("inst_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+18,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"ci",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"co",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.top__DOT__w_01));
    bufp->fullBit(oldp+2,(vlSelfRef.top__DOT__w_12));
    bufp->fullBit(oldp+3,(vlSelfRef.top__DOT__w_23));
    bufp->fullCData(oldp+4,(vlSelfRef.a),4);
    bufp->fullCData(oldp+5,(vlSelfRef.b),4);
    bufp->fullBit(oldp+6,(vlSelfRef.ci));
    bufp->fullCData(oldp+7,(vlSelfRef.s),4);
    bufp->fullBit(oldp+8,(vlSelfRef.co));
    bufp->fullBit(oldp+9,((1U & (IData)(vlSelfRef.a))));
    bufp->fullBit(oldp+10,((1U & (IData)(vlSelfRef.b))));
    bufp->fullBit(oldp+11,((1U & (((~ (IData)(vlSelfRef.a)) 
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
    bufp->fullBit(oldp+12,((1U & ((IData)(vlSelfRef.a) 
                                  >> 1U))));
    bufp->fullBit(oldp+13,((1U & ((IData)(vlSelfRef.b) 
                                  >> 1U))));
    bufp->fullBit(oldp+14,((1U & (((~ ((IData)(vlSelfRef.a) 
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
    bufp->fullBit(oldp+15,((1U & ((IData)(vlSelfRef.a) 
                                  >> 2U))));
    bufp->fullBit(oldp+16,((1U & ((IData)(vlSelfRef.b) 
                                  >> 2U))));
    bufp->fullBit(oldp+17,((1U & (((~ ((IData)(vlSelfRef.a) 
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
    bufp->fullBit(oldp+18,((1U & ((IData)(vlSelfRef.a) 
                                  >> 3U))));
    bufp->fullBit(oldp+19,((1U & ((IData)(vlSelfRef.b) 
                                  >> 3U))));
    bufp->fullBit(oldp+20,((1U & (((~ ((IData)(vlSelfRef.a) 
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
