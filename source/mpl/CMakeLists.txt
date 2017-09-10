#collect source files

set (SOURCES
	"mpl_dummy.cpp"
)

set (HEADERS
	"mpl__if.hpp"
	"mpl_apply.hpp"
	"mpl_apply_values.hpp"
	"mpl_bind.hpp"
	"mpl_equals.hpp"
	"mpl_first.hpp"

	"mpl_fold.hpp"
	"mpl_fold_i.hpp"
	"mpl_fold_v.hpp"

	"mpl_function_decomposition.hpp"
	"mpl_functor.hpp"
	"mpl_has_instance_member.hpp"
	"mpl_has_type_member.hpp"
	"mpl_head.hpp"
	"mpl_is_invokable.hpp"
	"mpl_list.hpp"

	"mpl_map.hpp" # f: Type -> Type
	"mpl_map_i.hpp" # f: Type * Int -> Type
	"mpl_map_v.hpp" # f: Type -> Value
	#"mpl_map_iv.hpp" # f: Type * Int -> Value
	"mpl_map_vv.hpp" # f: Type * Value -> Value
	#"mpl_map_ivv.hpp" # f: Type * Int * Value -> Value

	"mpl_none.hpp"
	"mpl_ordered_piecewise_invoke.hpp"
	"mpl_pop_value.hpp"
	"mpl_push.hpp"
	"mpl_push_value.hpp"
	"mpl_select.hpp"
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