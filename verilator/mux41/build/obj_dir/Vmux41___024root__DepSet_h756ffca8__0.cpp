// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux41.h for the primary calling header

#include "Vmux41__pch.h"
#include "Vmux41___024root.h"

void Vmux41___024root___ico_sequent__TOP__0(Vmux41___024root* vlSelf);

void Vmux41___024root___eval_ico(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval_ico\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vmux41___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vmux41___024root___ico_sequent__TOP__0(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___ico_sequent__TOP__0\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.F = ((2U & (IData)(vlSelfRef.Y)) ? ((1U 
                                                   & (IData)(vlSelfRef.Y))
                                                   ? (IData)(vlSelfRef.X3)
                                                   : (IData)(vlSelfRef.X2))
                    : ((1U & (IData)(vlSelfRef.Y)) ? (IData)(vlSelfRef.X1)
                        : (IData)(vlSelfRef.X0)));
}

void Vmux41___024root___eval_triggers__ico(Vmux41___024root* vlSelf);

bool Vmux41___024root___eval_phase__ico(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval_phase__ico\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vmux41___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vmux41___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vmux41___024root___eval_act(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval_act\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmux41___024root___eval_nba(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval_nba\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmux41___024root___eval_triggers__act(Vmux41___024root* vlSelf);

bool Vmux41___024root___eval_phase__act(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval_phase__act\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmux41___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vmux41___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmux41___024root___eval_phase__nba(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval_phase__nba\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmux41___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41___024root___dump_triggers__ico(Vmux41___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41___024root___dump_triggers__nba(Vmux41___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41___024root___dump_triggers__act(Vmux41___024root* vlSelf);
#endif  // VL_DEBUG

void Vmux41___024root___eval(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vmux41___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/yangcn/Desktop/verilator/mux41/vsrc/mux41.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vmux41___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vmux41___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/yangcn/Desktop/verilator/mux41/vsrc/mux41.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vmux41___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/yangcn/Desktop/verilator/mux41/vsrc/mux41.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vmux41___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vmux41___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmux41___024root___eval_debug_assertions(Vmux41___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41___024root___eval_debug_assertions\n"); );
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.X0 & 0xfcU)))) {
        Verilated::overWidthError("X0");}
    if (VL_UNLIKELY(((vlSelfRef.X1 & 0xfcU)))) {
        Verilated::overWidthError("X1");}
    if (VL_UNLIKELY(((vlSelfRef.X2 & 0xfcU)))) {
        Verilated::overWidthError("X2");}
    if (VL_UNLIKELY(((vlSelfRef.X3 & 0xfcU)))) {
        Verilated::overWidthError("X3");}
    if (VL_UNLIKELY(((vlSelfRef.Y & 0xfcU)))) {
        Verilated::overWidthError("Y");}
}
#endif  // VL_DEBUG
