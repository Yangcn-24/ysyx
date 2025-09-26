// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux41__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmux41::Vmux41(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmux41__Syms(contextp(), _vcname__, this)}
    , X0{vlSymsp->TOP.X0}
    , X1{vlSymsp->TOP.X1}
    , X2{vlSymsp->TOP.X2}
    , X3{vlSymsp->TOP.X3}
    , Y{vlSymsp->TOP.Y}
    , F{vlSymsp->TOP.F}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmux41::Vmux41(const char* _vcname__)
    : Vmux41(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmux41::~Vmux41() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmux41___024root___eval_debug_assertions(Vmux41___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux41___024root___eval_static(Vmux41___024root* vlSelf);
void Vmux41___024root___eval_initial(Vmux41___024root* vlSelf);
void Vmux41___024root___eval_settle(Vmux41___024root* vlSelf);
void Vmux41___024root___eval(Vmux41___024root* vlSelf);

void Vmux41::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux41::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux41___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmux41___024root___eval_static(&(vlSymsp->TOP));
        Vmux41___024root___eval_initial(&(vlSymsp->TOP));
        Vmux41___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmux41___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmux41::eventsPending() { return false; }

uint64_t Vmux41::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmux41::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmux41___024root___eval_final(Vmux41___024root* vlSelf);

VL_ATTR_COLD void Vmux41::final() {
    Vmux41___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmux41::hierName() const { return vlSymsp->name(); }
const char* Vmux41::modelName() const { return "Vmux41"; }
unsigned Vmux41::threads() const { return 1; }
void Vmux41::prepareClone() const { contextp()->prepareClone(); }
void Vmux41::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmux41::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmux41___024root__trace_decl_types(VerilatedVcd* tracep);

void Vmux41___024root__trace_init_top(Vmux41___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmux41___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux41___024root*>(voidSelf);
    Vmux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmux41___024root__trace_decl_types(tracep);
    Vmux41___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmux41___024root__trace_register(Vmux41___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux41::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmux41::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmux41___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
