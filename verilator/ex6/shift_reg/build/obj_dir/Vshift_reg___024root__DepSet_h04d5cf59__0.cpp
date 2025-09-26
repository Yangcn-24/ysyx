// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshift_reg.h for the primary calling header

#include "Vshift_reg__pch.h"
#include "Vshift_reg___024root.h"

void Vshift_reg___024root___eval_act(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_act\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vshift_reg___024root___nba_sequent__TOP__0(Vshift_reg___024root* vlSelf);

void Vshift_reg___024root___eval_nba(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_nba\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vshift_reg___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vshift_reg___024root___nba_sequent__TOP__0(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___nba_sequent__TOP__0\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.q = ((IData)(vlSelfRef.rstn) ? ((IData)(vlSelfRef.load)
                                               ? ((
                                                   (~ (IData)(vlSelfRef.ena)) 
                                                   & (IData)(vlSelfRef.R_L))
                                                   ? 
                                                  (((IData)(vlSelfRef.in) 
                                                    << 3U) 
                                                   | (7U 
                                                      & ((IData)(vlSelfRef.q) 
                                                         >> 1U)))
                                                   : 
                                                  ((1U 
                                                    & ((~ (IData)(vlSelfRef.ena)) 
                                                       & (~ (IData)(vlSelfRef.R_L))))
                                                    ? 
                                                   ((0xeU 
                                                     & ((IData)(vlSelfRef.q) 
                                                        << 1U)) 
                                                    | (IData)(vlSelfRef.in))
                                                    : (IData)(vlSelfRef.q)))
                                               : (IData)(vlSelfRef.data))
                    : 1U);
}

void Vshift_reg___024root___eval_triggers__act(Vshift_reg___024root* vlSelf);

bool Vshift_reg___024root___eval_phase__act(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_phase__act\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vshift_reg___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vshift_reg___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vshift_reg___024root___eval_phase__nba(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_phase__nba\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vshift_reg___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshift_reg___024root___dump_triggers__nba(Vshift_reg___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vshift_reg___024root___dump_triggers__act(Vshift_reg___024root* vlSelf);
#endif  // VL_DEBUG

void Vshift_reg___024root___eval(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vshift_reg___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/yangcn/Desktop/verilator/ex6/shift_reg/vsrc/shift_reg.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vshift_reg___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/yangcn/Desktop/verilator/ex6/shift_reg/vsrc/shift_reg.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vshift_reg___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vshift_reg___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vshift_reg___024root___eval_debug_assertions(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_debug_assertions\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rstn & 0xfeU)))) {
        Verilated::overWidthError("rstn");}
    if (VL_UNLIKELY(((vlSelfRef.in & 0xfeU)))) {
        Verilated::overWidthError("in");}
    if (VL_UNLIKELY(((vlSelfRef.load & 0xfeU)))) {
        Verilated::overWidthError("load");}
    if (VL_UNLIKELY(((vlSelfRef.data & 0xf0U)))) {
        Verilated::overWidthError("data");}
    if (VL_UNLIKELY(((vlSelfRef.R_L & 0xfeU)))) {
        Verilated::overWidthError("R_L");}
    if (VL_UNLIKELY(((vlSelfRef.ena & 0xfeU)))) {
        Verilated::overWidthError("ena");}
}
#endif  // VL_DEBUG
