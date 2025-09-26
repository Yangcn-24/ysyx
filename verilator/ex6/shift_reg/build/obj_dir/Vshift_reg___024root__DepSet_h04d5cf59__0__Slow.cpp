// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshift_reg.h for the primary calling header

#include "Vshift_reg__pch.h"
#include "Vshift_reg___024root.h"

VL_ATTR_COLD void Vshift_reg___024root___eval_static(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_static\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rstn__0 = vlSelfRef.rstn;
}

VL_ATTR_COLD void Vshift_reg___024root___eval_initial(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_initial\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vshift_reg___024root___eval_final(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_final\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vshift_reg___024root___eval_settle(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___eval_settle\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshift_reg___024root___dump_triggers__act(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___dump_triggers__act\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rstn)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vshift_reg___024root___dump_triggers__nba(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___dump_triggers__nba\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rstn)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vshift_reg___024root___ctor_var_reset(Vshift_reg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshift_reg___024root___ctor_var_reset\n"); );
    Vshift_reg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = 0;
    vlSelf->rstn = 0;
    vlSelf->in = 0;
    vlSelf->load = 0;
    vlSelf->data = 0;
    vlSelf->R_L = 0;
    vlSelf->ena = 0;
    vlSelf->q = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rstn__0 = 0;
}
