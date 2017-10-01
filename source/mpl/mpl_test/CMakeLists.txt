include_directories("${DEP_DIR}/googletest/include")
link_directories("${DEP_DIR}/googletest/lib")

set (SOURCES
	"mpl__if.t.cpp"
	"mpl_any.t.cpp"
	"mpl_apply.t.cpp"
	"mpl_apply_v.t.cpp"
	"mpl_bind.t.cpp"
	"mpl_bool.t.cpp"
	"mpl_choose_v.t.cpp"
	"mpl_drop.t.cpp"
	"mpl_drop_v.t.cpp"
	"mpl_equals.t.cpp"
	"mpl_filter.t.cpp"
	"mpl_first.t.cpp"
	"mpl_flatten.t.cpp"
	"mpl_fold.t.cpp"
	"mpl_fold_i.t.cpp"
	"mpl_fold_v.t.cpp"
	"mpl_fold_vv.t.cpp"
	"mpl_fold_vx.t.cpp"
	"mpl_function_decomposition.t.cpp"
	"mpl_functor.t.cpp"
	"mpl_has_instance_member.t.cpp"
	"mpl_has_type_member.t.cpp"
	"mpl_head.t.cpp"
	"mpl_indices.t.cpp"
	"mpl_is_invocable.t.cpp"
	"mpl_list.t.cpp"
	"mpl_map.t.cpp"
	"mpl_map_i.t.cpp"
	"mpl_map_v.t.cpp"
	"mpl_none.t.cpp"
	"mpl_ordered_piecewise_invoke.t.cpp"
	"mpl_pop_value.t.cpp"
	"mpl_push.t.cpp"
	"mpl_push_value.t.cpp"
	"mpl_sfinae.t.cpp"
	"mpl_some.t.cpp"
	"mpl_substitute.t.cpp"
	"mpl_utils.t.cpp"
)

add_executable(mpl_test ${SOURCES})
find_package (Threads)
target_link_libraries(mpl_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
set_property(TARGET mpl_test PROPERTY CXX_STANDARD 17)
set_property(TARGET mpl_test PROPERTY CXX_STANDARD_REQUIRED ON)
