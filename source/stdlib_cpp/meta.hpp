#define FUNC_IMPL(NAMESPACE, NAME, SIGNATURE, IMP) \
exc.get_value(##NAMESPACE).introduce_function_constant(##NAME, ##SIGNATURE, [](std::vector<PObject> const &args) IMP)
