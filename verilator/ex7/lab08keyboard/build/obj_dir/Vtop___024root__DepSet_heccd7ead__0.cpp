// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*7:0*/, 32> Vtop__ConstPool__TABLE_h9d6eb112_0;

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*4:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelfRef.top__DOT__segen = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                 && (1U & (~ (IData)(
                                                     ((0xf000U 
                                                       == 
                                                       (0xff00U 
                                                        & vlSelfRef.top__DOT__ps2segin)) 
                                                      & ((0xffU 
                                                          & vlSelfRef.top__DOT__ps2segin) 
                                                         == 
                                                         (0xffU 
                                                          & (vlSelfRef.top__DOT__ps2segin 
                                                             >> 0x10U))))))));
    __Vtableidx2 = ((0x1eU & (vlSelfRef.top__DOT__ps2segin 
                              << 1U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg1 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx2];
    __Vtableidx3 = ((0x1eU & (vlSelfRef.top__DOT__ps2segin 
                              >> 3U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg2 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx3];
    __Vtableidx5 = ((0x1eU & ((IData)(vlSelfRef.top__DOT__ascii) 
                              << 1U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg3 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx5];
    __Vtableidx6 = ((0x1eU & ((IData)(vlSelfRef.top__DOT__ascii) 
                              >> 3U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg4 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx6];
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*7:0*/, 256> Vtop__ConstPool__TABLE_h7b3eea93_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*7:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*4:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*2:0*/ __Vdly__top__DOT__ps2keyboard__DOT__ps2_clk_sync;
    __Vdly__top__DOT__ps2keyboard__DOT__ps2_clk_sync = 0;
    CData/*3:0*/ __Vdly__top__DOT__ps2keyboard__DOT__count;
    __Vdly__top__DOT__ps2keyboard__DOT__count = 0;
    CData/*2:0*/ __Vdly__top__DOT__ps2keyboard__DOT__w_ptr;
    __Vdly__top__DOT__ps2keyboard__DOT__w_ptr = 0;
    CData/*2:0*/ __Vdly__top__DOT__ps2keyboard__DOT__r_ptr;
    __Vdly__top__DOT__ps2keyboard__DOT__r_ptr = 0;
    CData/*0:0*/ __Vdly__top__DOT__ps2over;
    __Vdly__top__DOT__ps2over = 0;
    CData/*0:0*/ __Vdly__top__DOT__ps2ready;
    __Vdly__top__DOT__ps2ready = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__ps2keyboard__DOT__fifo__v0;
    __VdlyVal__top__DOT__ps2keyboard__DOT__fifo__v0 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__ps2keyboard__DOT__fifo__v0;
    __VdlyDim0__top__DOT__ps2keyboard__DOT__fifo__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__ps2keyboard__DOT__fifo__v0;
    __VdlySet__top__DOT__ps2keyboard__DOT__fifo__v0 = 0;
    // Body
    __Vdly__top__DOT__ps2keyboard__DOT__ps2_clk_sync 
        = vlSelfRef.top__DOT__ps2keyboard__DOT__ps2_clk_sync;
    __Vdly__top__DOT__ps2keyboard__DOT__count = vlSelfRef.top__DOT__ps2keyboard__DOT__count;
    __Vdly__top__DOT__ps2keyboard__DOT__w_ptr = vlSelfRef.top__DOT__ps2keyboard__DOT__w_ptr;
    __Vdly__top__DOT__ps2keyboard__DOT__r_ptr = vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr;
    __Vdly__top__DOT__ps2over = vlSelfRef.top__DOT__ps2over;
    __VdlySet__top__DOT__ps2keyboard__DOT__fifo__v0 = 0U;
    __Vdly__top__DOT__ps2ready = vlSelfRef.top__DOT__ps2ready;
    __Vdly__top__DOT__ps2keyboard__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelfRef.ps2_clk));
    if (vlSelfRef.rst) {
        __Vdly__top__DOT__ps2keyboard__DOT__count = 0U;
        __Vdly__top__DOT__ps2keyboard__DOT__w_ptr = 0U;
        __Vdly__top__DOT__ps2keyboard__DOT__r_ptr = 0U;
        __Vdly__top__DOT__ps2over = 0U;
        __Vdly__top__DOT__ps2ready = 0U;
    } else {
        if (vlSelfRef.top__DOT__ps2ready) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__ps2next)))) {
                __Vdly__top__DOT__ps2keyboard__DOT__r_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr)));
                if (((IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr))))) {
                    __Vdly__top__DOT__ps2ready = 0U;
                }
            }
        }
        if ((IData)((4U == (6U & (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__count))) {
                if ((((~ (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__buffer)) 
                      & (IData)(vlSelfRef.ps2_data)) 
                     & VL_REDXOR_32((0x1ffU & ((IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__buffer) 
                                               >> 1U))))) {
                    __VdlyVal__top__DOT__ps2keyboard__DOT__fifo__v0 
                        = (0xffU & ((IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__buffer) 
                                    >> 1U));
                    __VdlyDim0__top__DOT__ps2keyboard__DOT__fifo__v0 
                        = vlSelfRef.top__DOT__ps2keyboard__DOT__w_ptr;
                    __VdlySet__top__DOT__ps2keyboard__DOT__fifo__v0 = 1U;
                    __Vdly__top__DOT__ps2ready = 1U;
                    __Vdly__top__DOT__ps2keyboard__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__w_ptr)));
                    __Vdly__top__DOT__ps2over = ((IData)(vlSelfRef.top__DOT__ps2over) 
                                                 | ((IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr) 
                                                    == 
                                                    (7U 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__w_ptr)))));
                }
                __Vdly__top__DOT__ps2keyboard__DOT__count = 0U;
            } else {
                vlSelfRef.top__DOT__ps2keyboard__DOT____Vlvbound_h9ff2922b__0 
                    = vlSelfRef.ps2_data;
                if ((9U >= (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__count))) {
                    vlSelfRef.top__DOT__ps2keyboard__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__count))) 
                            & (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelfRef.top__DOT__ps2keyboard__DOT____Vlvbound_h9ff2922b__0) 
                                        << (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__count))));
                }
                __Vdly__top__DOT__ps2keyboard__DOT__count 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.top__DOT__ps2keyboard__DOT__count)));
            }
        }
    }
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__state_current) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__state_current) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__state_current) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__state_current))) {
                    vlSelfRef.top__DOT__ps2segin = 
                        ((0xffff00U & (vlSelfRef.top__DOT__ps2segin 
                                       << 8U)) | vlSelfRef.top__DOT__ps2keyboard__DOT__fifo
                         [vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr]);
                }
            }
        }
    }
    vlSelfRef.top__DOT__ps2keyboard__DOT__count = __Vdly__top__DOT__ps2keyboard__DOT__count;
    vlSelfRef.top__DOT__ps2keyboard__DOT__w_ptr = __Vdly__top__DOT__ps2keyboard__DOT__w_ptr;
    vlSelfRef.top__DOT__ps2over = __Vdly__top__DOT__ps2over;
    vlSelfRef.top__DOT__ps2keyboard__DOT__ps2_clk_sync 
        = __Vdly__top__DOT__ps2keyboard__DOT__ps2_clk_sync;
    vlSelfRef.top__DOT__ps2ready = __Vdly__top__DOT__ps2ready;
    vlSelfRef.top__DOT__ps2keyboard__DOT__r_ptr = __Vdly__top__DOT__ps2keyboard__DOT__r_ptr;
    if (__VdlySet__top__DOT__ps2keyboard__DOT__fifo__v0) {
        vlSelfRef.top__DOT__ps2keyboard__DOT__fifo[__VdlyDim0__top__DOT__ps2keyboard__DOT__fifo__v0] 
            = __VdlyVal__top__DOT__ps2keyboard__DOT__fifo__v0;
    }
    if ((8U & (IData)(vlSelfRef.top__DOT__state_current))) {
        vlSelfRef.top__DOT__ps2next = 1U;
    } else if ((4U & (IData)(vlSelfRef.top__DOT__state_current))) {
        vlSelfRef.top__DOT__ps2next = ((1U & ((IData)(vlSelfRef.top__DOT__state_current) 
                                              >> 1U)) 
                                       || (1U & (IData)(vlSelfRef.top__DOT__state_current)));
    } else if ((2U & (IData)(vlSelfRef.top__DOT__state_current))) {
        vlSelfRef.top__DOT__ps2next = (1U & (IData)(vlSelfRef.top__DOT__state_current));
    } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__state_current)))) {
        vlSelfRef.top__DOT__ps2next = 1U;
    }
    __Vtableidx4 = (0xffU & vlSelfRef.top__DOT__ps2segin);
    vlSelfRef.top__DOT__ascii = Vtop__ConstPool__TABLE_h7b3eea93_0
        [__Vtableidx4];
    vlSelfRef.top__DOT__segen = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                 && (1U & (~ (IData)(
                                                     ((0xf000U 
                                                       == 
                                                       (0xff00U 
                                                        & vlSelfRef.top__DOT__ps2segin)) 
                                                      & ((0xffU 
                                                          & vlSelfRef.top__DOT__ps2segin) 
                                                         == 
                                                         (0xffU 
                                                          & (vlSelfRef.top__DOT__ps2segin 
                                                             >> 0x10U))))))));
    __Vtableidx2 = ((0x1eU & (vlSelfRef.top__DOT__ps2segin 
                              << 1U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg1 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx2];
    __Vtableidx3 = ((0x1eU & (vlSelfRef.top__DOT__ps2segin 
                              >> 3U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg2 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx3];
    __Vtableidx5 = ((0x1eU & ((IData)(vlSelfRef.top__DOT__ascii) 
                              << 1U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg3 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx5];
    __Vtableidx6 = ((0x1eU & ((IData)(vlSelfRef.top__DOT__ascii) 
                              >> 3U)) | (IData)(vlSelfRef.top__DOT__segen));
    vlSelfRef.seg4 = Vtop__ConstPool__TABLE_h9d6eb112_0
        [__Vtableidx6];
}

extern const VlUnpacked<CData/*7:0*/, 16> Vtop__ConstPool__TABLE_head14b53_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    CData/*3:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    CData/*3:0*/ __Vdly__top__DOT__segcounth;
    __Vdly__top__DOT__segcounth = 0;
    CData/*3:0*/ __Vdly__top__DOT__segcountl;
    __Vdly__top__DOT__segcountl = 0;
    // Body
    __Vdly__top__DOT__segcounth = vlSelfRef.top__DOT__segcounth;
    __Vdly__top__DOT__segcountl = vlSelfRef.top__DOT__segcountl;
    if (vlSelfRef.rst) {
        __Vdly__top__DOT__segcounth = 0U;
        __Vdly__top__DOT__segcountl = 0U;
    } else if ((9U == (IData)(vlSelfRef.top__DOT__segcountl))) {
        __Vdly__top__DOT__segcounth = (0xfU & ((IData)(1U) 
                                               + (IData)(vlSelfRef.top__DOT__segcounth)));
        __Vdly__top__DOT__segcountl = 0U;
    } else {
        __Vdly__top__DOT__segcountl = (0xfU & ((IData)(1U) 
                                               + (IData)(vlSelfRef.top__DOT__segcountl)));
    }
    vlSelfRef.top__DOT__segcounth = __Vdly__top__DOT__segcounth;
    vlSelfRef.top__DOT__segcountl = __Vdly__top__DOT__segcountl;
    __Vtableidx8 = vlSelfRef.top__DOT__segcounth;
    vlSelfRef.seg8 = Vtop__ConstPool__TABLE_head14b53_0
        [__Vtableidx8];
    __Vtableidx7 = vlSelfRef.top__DOT__segcountl;
    vlSelfRef.seg7 = Vtop__ConstPool__TABLE_head14b53_0
        [__Vtableidx7];
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__state_current = ((IData)(vlSelfRef.rst)
                                          ? 8U : (IData)(vlSelfRef.top__DOT__state_next));
}

extern const VlUnpacked<CData/*3:0*/, 32> Vtop__ConstPool__TABLE_h894f70fd_0;

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.top__DOT__ps2ready) 
                     << 4U) | (IData)(vlSelfRef.top__DOT__state_current));
    vlSelfRef.top__DOT__state_next = Vtop__ConstPool__TABLE_h894f70fd_0
        [__Vtableidx1];
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/yangcn/Desktop/verilator/ex7/lab08keyboard/vsrc/top.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/yangcn/Desktop/verilator/ex7/lab08keyboard/vsrc/top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/yangcn/Desktop/verilator/ex7/lab08keyboard/vsrc/top.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY(((vlSelfRef.ps2_clk & 0xfeU)))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY(((vlSelfRef.ps2_data & 0xfeU)))) {
        Verilated::overWidthError("ps2_data");}
}
#endif  // VL_DEBUG
