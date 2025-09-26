// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbarrel_shifter.h for the primary calling header

#include "Vbarrel_shifter__pch.h"
#include "Vbarrel_shifter___024root.h"

void Vbarrel_shifter___024root___eval_act(Vbarrel_shifter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarrel_shifter___024root___eval_act\n"); );
    Vbarrel_shifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vbarrel_shifter___024root___nba_sequent__TOP__0(Vbarrel_shifter___024root* vlSelf);

void Vbarrel_shifter___024root___eval_nba(Vbarrel_shifter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarrel_shifter___024root___eval_nba\n"); );
    Vbarrel_shifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vbarrel_shifter___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vbarrel_shifter___024root___nba_sequent__TOP__0(Vbarrel_shifter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarrel_shifter___024root___nba_sequent__TOP__0\n"); );
    Vbarrel_shifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dout = (0xffU & ((IData)(vlSelfRef.A_L)
                                ? ((IData)(vlSelfRef.L_R)
                                    ? ((IData)(vlSelfRef.din) 
                                       << (IData)(vlSelfRef.shamt))
                                    : ((0x80U & (IData)(vlSelfRef.din)) 
                                       | (0x7fU & ((IData)(vlSelfRef.din) 
                                                   >> (IData)(vlSelfRef.shamt)))))
                                : ((IData)(vlSelfRef.L_R)
                                    ? ((IData)(vlSelfRef.din) 
                                       << (IData)(vlSelfRef.shamt))
                                    : ((IData)(vlSelfRef.din) 
                                       >> (IData)(vlSelfRef.shamt)))));
}

void Vbarrel_shifter___024root___eval_triggers__act(Vbarrel_shifter___024root* vlSelf);

bool Vbarrel_shifter___024root___eval_phase__act(Vbarrel_shifter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarrel_shifter___024root___eval_phase__act\n"); );
    Vbarrel_shifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vbarrel_shifter___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vbarrel_shifter___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vbarrel_shifter___024root___eval_phase__nba(Vbarrel_shifter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarrel_shifter___024root___eval_phase__nba\n"); );
    Vbarrel_shifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vbarrel_shifter___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbarrel_shifter___024root___dump_triggers__nba(Vbarrel_shifter___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbarrel_shifter___024root___dump_triggers__act(Vbarrel_shifter___024root* vlSelf);
#endif  // VL_DEBUG

void Vbarrel_shifter___024root___eval(Vbarrel_shifter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarrel_shifter___024root___eval\n"); );
    Vbarrel_shifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vbarrel_shifter___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/yangcn/Desktop/verilator/ex6/barrel_shifter/vsrc/barrel_shifter.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vbarrel_shifter___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/yangcn/Desktop/verilator/ex6/barrel_shifter/vsrc/barrel_shifter.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vbarrel_shifter___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vbarrel_shifter___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vbarrel_shifter___024root___eval_debug_assertions(Vbarrel_shifter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarrel_shifter___024root___eval_debug_assertions\n"); );
    Vbarrel_shifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.shamt & 0xf8U)))) {
        Verilated::overWidthError("shamt");}
    if (VL_UNLIKELY(((vlSelfRef.L_R & 0xfeU)))) {
        Verilated::overWidthError("L_R");}
    if (VL_UNLIKELY(((vlSelfRef.A_L & 0xfeU)))) {
        Verilated::overWidthError("A_L");}
}
#endif  // VL_DEBUG
