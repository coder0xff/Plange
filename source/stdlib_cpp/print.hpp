
FUNC_IMP("Plange.print", [](std::vector<Object> const &args))
Object print_func(std::vector<Object> const &args) {
	std::cout << args[0].stringify();
}