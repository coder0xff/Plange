add_subdirectory(mpl_test)

#collect source files

set (SOURCES
	"mpl_dummy.cpp"
)

set (HEADERS
	"mpl__if.hpp"
	"mpl_any.hpp"
	"mpl_apply.hpp"
	"mpl_apply_v.hpp"
	"mpl_bind.hpp"
	"mpl_bool.hpp"
	"mpl_choose_v.hpp"
	"mpl_drop.hpp"
	"mpl_drop_v.hpp"
	"mpl_equals.hpp"
	"mpl_filter.hpp"
	"mpl_first.hpp"	

	"mpl_fold.hpp" # f: Type * Type -> Type
	"mpl_fold_i.hpp" # f: Type * size_t * Type -> Type
	"mpl_fold_v.hpp" # f: accumulator is a value, (Type * Value) * Type -> (Type * Value)
	#"mpl_fold_iv.hpp" # f: (Type * Value) * size_t * Type -> (Type * Value)
	"mpl_fold_vv.hpp" # f: accumulator and elements are values, (Type * Value) * (Type * Value) -> (Type * Value)
	"mpl_fold_vx.hpp" # f: accumulator and elements are values, (Type * Value) * (Type * Value) -> (Type * Value)
	#"mpl_fold_ivv.hpp" # f: (Type * Value) * size_t * (Type * Value) -> (Type * Value)

	"mpl_flatten.hpp"
	"mpl_function_decomposition.hpp"
	"mpl_functor.hpp"
	"mpl_has_instance_member.hpp"
	"mpl_has_move_assignment.hpp"
	"mpl_has_type_member.hpp"
	"mpl_head.hpp"
	"mpl_indices.hpp" # operations on template<size_t...> lists
	"mpl_is_const.hpp"
	"mpl_is_copyable.hpp"
	"mpl_is_invocable.hpp"
	"mpl_is_movable.hpp"
	"mpl_list.hpp"

	"mpl_map.hpp" # f: Type -> Type
	"mpl_map_i.hpp" # f: Type * size_t -> Type
	"mpl_map_v.hpp" # f: Type -> (Type * Value)
	#"mpl_map_iv.hpp" # f: Type * size_t -> (Type * Value)
	"mpl_map_vv.hpp" # f: (Type * Value) -> (Type * Value)
	#"mpl_map_ivv.hpp" # f: (Type * Value) * size_t -> (Type * Value)

	"mpl_none.hpp"
	"mpl_ordered_piecewise_invoke.hpp"
	"mpl_pop_v.hpp"
	"mpl_push.hpp"
	"mpl_push_v.hpp"
	"mpl_sfinae.hpp"
	"mpl_some.hpp"
	"mpl_substitute.hpp"
	"mpl_utils.hpp"
)
	
add_library(mpl ${HEADERS} ${SOURCES})
source_group("src" FILES ${SOURCES})
source_group("include" FILES ${HEADERS})
set_property(TARGET utilities PROPERTY CXX_STANDARD 17)
set_property(TARGET utilities PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions(-DCMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}")