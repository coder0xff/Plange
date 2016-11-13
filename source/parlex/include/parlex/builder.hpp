#define DECLARE_STATE_MACHINE(name, ...) \
	class name##_t : public parlex::state_machine_base { \
	public: \
		name##_t() : state_machine_base(#name, __VA_ARGS__) {} \
		void process(parlex::details::context_ref const & c, size_t dfaState) const override; \
	}; \
	extern name##_t name

#define DEFINE_STATE_MACHINE(name, cases) \
	void name##_t::process(parlex::details::context_ref const & c, size_t dfaState) const { \
		switch (dfaState) { \
		cases \
		default: \
			throw std::logic_error("invalid state: " + std::to_string(dfaState)); \
		} \
	} \
	name##_t name;

#define DFA_STATE case 
#define DFA_ACCEPT accept(c)
#define DFA_EDGE(recognizer, out_neighbor) on(c, recognizer, out_neighbor)

#define COMPILED_GRAMMAR(name, main, productions, precedences) \
	parlex::compiled_grammar name(main, std::vector<std::reference_wrapper<parlex::state_machine_base const>>productions, std::vector<std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>>precedences)
#define GRAMMAR_PRECEDENCE(a, b) (std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>(a, b))